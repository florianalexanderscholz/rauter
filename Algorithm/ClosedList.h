/*
 * ClosedList.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#ifndef CLOSEDLIST_H_
#define CLOSEDLIST_H_

#include <boost/container/set.hpp>
#include <cstdint>

namespace Algorithm {

/**
 * @brief Maintains a closed list for pathfinding algorithms.
 */
class ClosedList {
public:
	ClosedList();
	virtual ~ClosedList();

	/**
	 * @brief Adds a key to the closed list.
	 * @param key The key to be added.
	 */
	void add(int64_t key);

	/**
	 * @brief Checks if a key has been added to the closed list.
	 * @param key The key to be checked.
	 * @return True if the closed list contains the key.
	 */
	bool contains(int64_t key);

	/**
	 * @brief Resets the state of the closed list.
	 */
	void reset();
private:
	boost::container::set<int64_t> _set;
};

} /* namespace Graph */

#endif /* CLOSEDLIST_H_ */
