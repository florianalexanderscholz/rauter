/*
 * OpenList.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */


#include <cstdint>
#include <functional>
#include <boost/heap/fibonacci_heap.hpp>
#include "Helper.hpp"
#include <boost/shared_ptr.hpp>
#include "OpenListNode.h"

#ifndef OPENLIST_H_
#define OPENLIST_H_

/**
 * @brief This namespace contains several classes required for routing algorithms!
 */
namespace Algorithm {

/**
 * @brief Maintains an open list for pathfinding algorithms.
 */
template<class T> class OpenList
{

	typedef boost::shared_ptr<Algorithm::OpenList_Node<T>> node_t;
	static boost::shared_ptr<OpenList_Node<T>> emptynode;

public:
	typedef typename OpenList_Node<T>::heap_t heap_t;
	typedef typename OpenList_Node<T>::handle_t handle_t;
    OpenList()
    {
    }
    virtual ~OpenList()
    {
    }

    /**
     * @brief Checks if the open list is empty.
     * @return Returns true if the open list is empty.
     */
    bool isEmpty()
    {
        return _heap.empty();
    }

    /**
     * @brief Extracts the element with the minimal priority from the open list. It also gets removed!
     * @return The extracted element.
     */
    T getMin()
    {
        auto element = _heap.top();
        _heap.pop();
        return element->m_node;
    }

    node_t  contains(T elem)
        {
        typename heap_t::iterator it = _heap.begin();

        for(;it != _heap.end(); it++)
        {
            if((*it)->m_node == elem)
                return *it;
        }

        return nullptr;
    }

    /**
     * @brief Updates the priority of an open list entry.
     * @param node The OpenList_Node shared pointer.
     * @param key The new priority.
     */
    void updateKey(node_t node, double key)
    {
        node->m_priority = key;
        _heap.update(node->m_handle,node);
    }

    void add(T &elem, double prio)
    {
        node_t elemnode (new OpenList_Node<T>(prio,elem));
        auto handle = _heap.push(elemnode);
        elemnode->m_handle = handle;
    }
    void add2(T elem, double prio)
    {
        node_t elemnode (new OpenList_Node<T>(prio,elem));
        auto handle = _heap.push(elemnode);
        elemnode->m_handle = handle;
    }

    void reset()
    {
    	_heap.clear();
    }

protected:
private:
   heap_t _heap;
};

} /* namespace Algorithm */

#endif /* OPENLIST_H_ */
