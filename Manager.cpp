/*
 * Manager.cpp
 *
 *  Created on: 27.12.2014
 *      Author: florian
 */

#include "Manager.h"
#include "Algorithm/Dijkstra.h"
#include "Algorithm/AStar.h"
#include <string>

Manager::Manager(std::string fn) {
	bool err = _db.OSMReadFile(fn);

	if(err == false)
	{
		throw ManagerError("Cannot read input file");
	}
	// TODO Auto-generated constructor stub

}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

int64_t Manager::findNodeByStreet(std::string street, std::string postal)
{
	std::cout << "ping" << std::endl;
	auto foundEdge = _db.findEdgeByStreet(street,postal);
	std::cout << "pong" << std::endl;
	if(foundEdge == nullptr)
	{
		throw ManagerError("Street not found");
	}

	return foundEdge->right();
}

bool Manager::runAlgorithm(Algorithms algorithm,int64_t startNodeId, int64_t goalNodeId, Algorithm::WayTracker &tracker)
{
	 auto startNode = _db.findNodeById(startNodeId);
	 if(startNode == nullptr)
	 {
		 throw ManagerError("Start node not found");
	 }

	 auto goalNode = _db.findNodeById(goalNodeId);
	 if(goalNode == nullptr)
	 {
		 throw ManagerError("Goal node not found");
	 }

	 if(algorithm == Dijkstra)
	 {
		 Algorithm::Dijkstra alg(_db);
		 return alg.Start(startNode,goalNode,tracker);
	 }
	 else if(algorithm == AStar)
	 {
		 Algorithm::AStar alg(_db);
		 return alg.Start(startNode,goalNode,tracker);
	 }
	 else
	 {
		 throw ManagerError("Not implemented algorithm");
	 }
}
