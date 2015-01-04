/*
 * Storage.cpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include "Storage/Storage.h"
#include <algorithm>
#include <utility>

namespace Storage {

Storage::Storage() {
	// TODO Auto-generated constructor stub

}

Storage::~Storage() {
	// TODO Auto-generated destructor stub
}

/**
 * Test
 * @param street
 * @param postal
 * @return
 */
Graph::Edge_sp Storage::findEdgeByStreet(std::string street,
		std::string postal) {
	auto foundEdge = std::find_if(_edgedb.begin(), _edgedb.end(),
			[&street,&postal](std::pair<int64_t,Graph::Edge_sp> pair)
			{
				if(pair.second->information->_postal !=  postal)
					return false;

				return pair.second->information->_street == street;
			});

	if (foundEdge != _edgedb.end() && foundEdge->second != Graph::Edge::Empty) {
		return foundEdge->second;
	} else {
		return Graph::Edge::Empty;
	}
}

void Storage::getNeighbors(int64_t nodeid, std::list<Graph::Node_sp> &neighbors)
{
    neighbors.clear();
    auto range = _edgedb.equal_range(nodeid);

    for(auto it = range.first; it !=  range.second; it++)
    {
        Graph::Edge_sp edge = it->second;

        auto val = findNodeById(edge->right());
        if(val != nullptr)
        neighbors.push_back(val);
    }
}

Graph::Node_sp Storage::findNodeById(int64_t id)
{
	auto iter = _nodedb.find(id);

	if(iter == _nodedb.end())
	{
		return nullptr;
	}
	else
	{
		return iter->second;
	}
}

void Storage::addEdge(Graph::Edge_sp edge) {
	_edgedb.insert(std::make_pair(edge->left(), edge));
}
void Storage::addNode(Graph::Node_sp node) {
	_nodedb.insert(std::make_pair(node->id(), node));
}

}/* namespace Graph */
