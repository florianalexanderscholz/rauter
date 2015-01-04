/*
 * OpenListNode.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#ifndef OPENLISTNODE_H_
#define OPENLISTNODE_H_

#include <cstdint>
#include <functional>
#include <boost/heap/fibonacci_heap.hpp>
#include "Helper.hpp"

namespace Algorithm {

template<class T> class OpenList_Node {
	typedef boost::shared_ptr<Algorithm::OpenList_Node<T>> node_t;
	struct greater_equal : std::binary_function <node_t,node_t,bool> {
	  bool operator() (const node_t& x, const node_t& y) const {return x->m_priority > y->m_priority;}
	};
public:
	typedef typename  boost::heap::fibonacci_heap<node_t,boost::heap::compare<Helper::greater_equal<OpenList_Node<T> > >  > heap_t;
	typedef typename heap_t::handle_type handle_t;
	OpenList_Node(double priority, T &node) :
			m_node(node) {
		m_priority = priority;
	}
	virtual ~OpenList_Node() {
		//dtor
	}
	OpenList_Node(const OpenList_Node &n) :
			m_node(n.m_node) {
		m_priority = n.m_priority;
		m_node = n.m_node;
		m_handle = n.m_handle;
	}

	bool operator>=(const OpenList_Node<T> &node) const {
		return m_priority >= node.m_priority;
	}

	double m_priority;
	T m_node;
	handle_t m_handle;
protected:
private:
};

} /* namespace Algorithm */

#endif /* OPENLISTNODE_H_ */
