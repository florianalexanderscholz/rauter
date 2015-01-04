/*
 * Manager.h
 *
 *  Created on: 27.12.2014
 *      Author: florian
 */

#include "Storage/Storage.h"
#include "Algorithm/AStar.h"

#include <stdexcept>

#ifndef MANAGER_H_
#define MANAGER_H_

class ManagerError : public std::logic_error
{
public:
	explicit ManagerError(const std::string &err) : std::logic_error(err)
	{}
	explicit ManagerError(const char* err) : std::logic_error(err)
	{}
};

class Manager {
private:
	Storage::Storage _db;
public:
	enum Algorithms {
		Dijkstra, AStar
	};

	Manager(std::string fn);
	int64_t findNodeByStreet(std::string street, std::string postal);
	bool runAlgorithm(Algorithms algorithm, int64_t startNodeId, int64_t goalNodeId, Algorithm::WayTracker &tracker);
	virtual ~Manager();
};


#endif /* MANAGER_H_ */
