/*
 * Edge.cpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include "Graph/Edge.h"

namespace Graph {

Edge_sp Edge::Empty;

Edge::Edge(int64_t id, int64_t left, int64_t right) {
	_id = id;
	_left = left;
	_right = right;
}

Edge::Edge(const Edge &other) {
	_id = other._id;
	_left = other._left;
	_right = other._right;
}

Edge::Edge(int64_t id, int64_t left, int64_t right, EdgeInformation_sp info) : Edge(id,left,right) {
	information = info;
}

Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

} /* namespace Graph */
