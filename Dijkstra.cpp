/*
 * AStar.cpp
 *
 *  Created on: 27.12.2014
 *      Author: florian
 */

#include "Algorithm/Dijkstra.h"

namespace Algorithm {

Dijkstra::Dijkstra(Storage::Storage &db) :
		_db(db) {
	// TODO Auto-generated constructor stub

}

Dijkstra::~Dijkstra() {
	// TODO Auto-generated destructor stub
}

bool Dijkstra::Start(Graph::Node_sp n1, Graph::Node_sp n2, WayTracker &tracker) {
	_open.reset();
	_closed.reset();
	_weights.clear();
	tracker._goal = n2;
	_weights[n1->id()] = 0;
	_open.add(n1, 0);


	do {
		auto currentNode = _open.getMin();
		if (currentNode == n2) {
			return true;
		}

		Search_Expand(currentNode, n2, tracker);

	} while (_open.isEmpty() == false);

	return false;
}

void Dijkstra::Search_Expand(Graph::Node_sp currentNode,Graph::Node_sp endNode, WayTracker &tracker)
{
    _closed.add(currentNode->id());
    std::list<Graph::Node_sp> neighbors;
    _db.getNeighbors(currentNode->id(),neighbors);
    //std::cout << _weights[currentNode->id()] << std::endl;
    for(auto successor : neighbors)
    {
        if(_closed.contains(successor->id()))
        {
            continue;
        }

        double tentative_g = _weights[currentNode->id()] + Graph::Node::dist2(*currentNode,*successor);

        auto successor_found = _open.contains(successor);
        if(successor_found != nullptr && tentative_g >= _weights[successor->id()])
        {
            continue;
        }

        tracker.addAncestor(successor,currentNode);
        _weights[successor->id()] = tentative_g;
        double f = tentative_g;

        if(successor_found != nullptr)
        {
            _open.updateKey(successor_found,f);
        }
        else
        {
        	_open.add(successor,f);
        }
    }
}

} /* namespace Algorithm */
