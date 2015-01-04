/*
 * WayTracker.h
 *
 *  Created on: 27.12.2014
 *      Author: florian
 */

#include <map>
#include <deque>

#ifndef WAYTRACKER_H_
#define WAYTRACKER_H_

#include "../Graph/Node.h"

namespace Algorithm {

class WayTracker {
private:
	std::map<int64_t, Graph::Node_sp> _ancestors;
	std::deque<Graph::Node_sp> _nodes;
public:
	Graph::Node_sp _goal;

	WayTracker()
	{
		_goal =  nullptr;
	}

	void reset() {
		_ancestors.clear();
		_nodes.clear();
		_goal = nullptr;
	}

	void addAncestor(Graph::Node_sp node1, Graph::Node_sp node2) {
		_ancestors[node1->id()] = node2;
	}

	void pushOnStack(Graph::Node_sp node) {
		_nodes.push_back(node);
	}

	double calcWay() {
		if(_goal == nullptr)
		{
			return 0.0;
		}

		Graph::Node_sp  node = _goal;

		std::map<int64_t, Graph::Node_sp>::iterator iter;
		pushOnStack(node);
		double length = 0.0;
		while ((iter = _ancestors.find(node->id())) != _ancestors.end()) {
			auto node_new = iter->second;
			length += Graph::Node::dist2(*node_new, *node);
			pushOnStack(node_new);
			node = iter->second;
		}

		return length;
	}

	template<class F> void traverse(F func) {
		while (_nodes.size() > 0) {
			auto val = _nodes.back();
			func(val);
			_nodes.pop_back();
		}
	}
};

} /* namespace Algorithm */

#endif /* WAYTRACKER_H_ */
