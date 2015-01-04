/*
 * ClosedList.cpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include "Algorithm/ClosedList.h"

namespace Algorithm {

ClosedList::ClosedList() {
	// TODO Auto-generated constructor stub

}

ClosedList::~ClosedList() {
	// TODO Auto-generated destructor stub
}

void ClosedList::add(int64_t key)
{
	_set.insert(key);
}
bool ClosedList::contains(int64_t key)
{
	auto iter = _set.find(key);

	if(iter == _set.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ClosedList::reset()
{
	_set.clear();
}

} /* namespace Graph */
