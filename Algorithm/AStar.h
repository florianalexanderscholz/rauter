/*
 * AStar.h
 *
 *  Created on: 27.12.2014
 *      Author: florian
 */

#include <cstdint>
#include <map>

#include "OpenList.h"
#include "ClosedList.h"
#include "WayTracker.h"

#include "../Graph/Edge.h"
#include "../Graph/Node.h"
#include "../Storage/Storage.h"

#ifndef ASTAR_H_
#define ASTAR_H_

namespace Algorithm {


class AStar {
private:
	OpenList<Graph::Node_sp> _open;
	ClosedList _closed;
	std::map<int64_t,double> _weights;
	Storage::Storage &_db;
	void Search_Expand(Graph::Node_sp currentNode,Graph::Node_sp endNode, WayTracker &tracker);
public:
	AStar(Storage::Storage &db);
	bool Start(Graph::Node_sp n1, Graph::Node_sp n2, WayTracker &tracker);
	virtual ~AStar();
};

} /* namespace Algorithm */

#endif /* ASTAR_H_ */
