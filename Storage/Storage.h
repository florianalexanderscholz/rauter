/*
 * Storage.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#ifndef STORAGE_H_
#define STORAGE_H_

#include "../Graph/Node.h"
#include "../Graph/Edge.h"

#include <map>
#include <list>

namespace Storage {

class Storage {
private:
	std::multimap<int64_t,Graph::Edge_sp> _edgedb;
	std::map<int64_t,Graph::Node_sp> _nodedb;
public:
	Storage();
	virtual ~Storage();

	size_t countEdges();
	size_t countNodes();

	Graph::Edge_sp findEdgeByStreet(std::string street, std::string postal);
	Graph::Node_sp findNodeById(int64_t id);

	void getNeighbors(int64_t nodeid, std::list<Graph::Node_sp> &neighbors);

	void addEdge(Graph::Edge_sp edge);
	void addNode(Graph::Node_sp node);

	bool OSMReadFile(std::string filename);
};

} /* namespace Graph */

#endif /* STORAGE_H_ */
