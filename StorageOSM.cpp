/*
 * StorageOSM.cpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include "Storage/Storage.h"

#include <osmpbf/parsehelpers.h>
#include <osmpbf/inode.h>
#include <osmpbf/iway.h>
#include <osmpbf/irelation.h>
#include <osmpbf/filter.h>
#include <cstdint>

namespace Storage {

static void parseBlock(osmpbf::PrimitiveBlockInputAdaptor & pbi,
		Storage *storage) {
	if (pbi.nodesSize() > 0) {
		for (osmpbf::INodeStream node = pbi.getNodeStream(); !node.isNull();
				node.next()) {
			Graph::Node_sp n(
					new Graph::Node(node.id(), node.lond(), node.latd()));

			storage->addNode(n);
		}
	}
	if (pbi.waysSize()) {
		for (osmpbf::IWayStream way = pbi.getWayStream(); !way.isNull();
				way.next()) {

			int64_t id = way.id();
			std::string street;
			std::string postal;

			bool has_highway = false;

			for (size_t i = 0, s = way.tagsSize(); i < s; ++i) {
				if (way.key(i) == "highway" && way.value(i) != "pedestrian"
						&& way.value(i) != "footway" && way.value(i) != "")
					has_highway = true;
				else if (way.key(i) == "name") {
					street = way.value(i);
				} else if (way.key(i) == "postal_code") {
					postal = way.value(i);
				}
			}

			if (has_highway == false)
				continue;

			std::vector<int64_t> ids;

			for (osmpbf::IWay::RefIterator refIt(way.refBegin()), refEnd(
					way.refEnd()); refIt != refEnd; ++refIt) {
				ids.push_back(*refIt);
			}

			if (ids.size() > 1) {
				Graph::EdgeInformation_sp info(
						new Graph::EdgeInformation(street, postal));

				for (size_t i = 1; i < ids.size(); i++) {
					storage->addEdge(
							Graph::Edge_sp(
									new Graph::Edge(id, ids[i - 1], ids[i],
											info)));
					storage->addEdge(
							Graph::Edge_sp(
									new Graph::Edge(id, ids[i], ids[i - 1],
											info)));
				}
			}
		}
	}
}

bool Storage::OSMReadFile(std::string filename) {
	osmpbf::OSMFileIn inFile(filename.c_str(), false);

	if (!inFile.open()) {
		std::cout << "Failed to open" << std::endl;
		return false;
	}

	auto parseFunc = [&](osmpbf::PrimitiveBlockInputAdaptor & pbi)
	{
		parseBlock(pbi,this);
	};

	osmpbf::parseFile(inFile, parseFunc);
	return true;
}
}
