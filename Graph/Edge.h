/*
 * Edge.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#ifndef EDGE_H_
#define EDGE_H_

#include <cstdint>
#include <string>
#include <boost/shared_ptr.hpp>

#include "EdgeInformation.h"

namespace Graph {

class Edge;
typedef boost::shared_ptr<Edge> Edge_sp;

class Edge {
private:
	int64_t _id;
	int64_t _left;
	int64_t _right;
public:
	EdgeInformation_sp information;
	Edge(int64_t id, int64_t left, int64_t right);
	Edge(int64_t id, int64_t left, int64_t right, EdgeInformation_sp info);
	Edge(const Edge &other);
	virtual ~Edge();
	int64_t id()
	{
		return _id;
	}

	int64_t left()
	{
		return _left;
	}

	int64_t right()
	{
		return _right;
	}

	static Edge_sp Empty;
};

} /* namespace Graph */

#endif /* EDGE_H_ */
