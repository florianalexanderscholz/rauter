/*
 * Node.cpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include "Graph/Node.h"

#include <GeographicLib/Geodesic.hpp>

namespace Graph {

Node_sp Node::Empty;

Node::Node(int64_t id, double lon, double lat) {
	_id = id;
	_lon = lon;
	_lat = lat;
}

Node::Node(const Node &other) {
	_id = other._id;
	_lon = other._lon;
	_lat = other._lat;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

double Node::dist(Node &l, Node &r) {
	GeographicLib::Geodesic geod(GeographicLib::Constants::WGS84_a(),
			GeographicLib::Constants::WGS84_f());

	double distance = 0.0;

	geod.Inverse(l._lat, l._lon, r._lat, r._lon, distance);

	return distance / 1000.0;
}

double Node::dist2(Node l, Node r) {
	GeographicLib::Geodesic geod(GeographicLib::Constants::WGS84_a(),
			GeographicLib::Constants::WGS84_f());

	double distance = 0.0;

	geod.Inverse(l._lat, l._lon, r._lat, r._lon, distance);

	return distance / 1000.0;
}


const bool Node::operator==(const Node &other) {
	return _id == other._id;
}

} /* namespace Graph */
