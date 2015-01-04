/*
 * Node.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include <cstdint>
#include <boost/shared_ptr.hpp>

#ifndef NODE_H_
#define NODE_H_

/**
 * @brief Contains graph components like nodes and edges.
 */
namespace Graph {

class Node;
typedef boost::shared_ptr<Node> Node_sp;

/**
 * @brief Describes an Open Street Map node.
 */
class Node {
private:
	int64_t _id;
	double _lat;
	double _lon;
public:
	/**
	 * @brief Constructor
	 * @param id The OSM node id
	 * @param lon The longitude
	 * @param lat The latitude.
	 */
	Node(int64_t id, double lon, double lat);

	/**
	 * @brief The copy constructor
	 * @param other Another instance.
	 */
	Node(const Node &other);

	/**
	 * @brief The destructor
	 */
	virtual ~Node();

	/**
	 * @brief Returns the OSM id
	 * @return The OSM id
	 */
	int64_t id() {
		return _id;
	}

	/**
	 * @brief Returns the latitude of the node.
	 * @return The latitude
	 */
	double lat() {
		return _lat;
	}

	/**
	 * @brief Returns the longitude of the node.
	 * @return The longitude
	 */
	double lon() {
		return _lon;
	}

	//Overloaded Operators
	const bool operator==(const Node &);

	/**
	 * @brief Calculates the distance between two OSM nodes.
	 * @param l One node
	 * @param r Another node
	 * @return The distance in kilometres.
	 */
	static double dist(Node &l, Node &r);

	/**
	 * @brief Calculates the distance between two OSM nodes.
	 * @param l One node
	 * @param r Another node
	 * @return The distance in kilometres.
	 */
	static double dist2(Node l, Node r);

	/**
	 * @brief Represents an empty node.
	 */
	static Node_sp Empty;
};

} /* namespace Graph */

#endif /* NODE_H_ */
