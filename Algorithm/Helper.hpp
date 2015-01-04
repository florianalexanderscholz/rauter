/*
 * Helper.hpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include <functional>
#include <boost/shared_ptr.hpp>
#ifndef HELPER_HPP_
#define HELPER_HPP_

namespace Helper
{

template <class T> struct greater_equal : std::binary_function <boost::shared_ptr<T>,boost::shared_ptr<T>,bool> {
  bool operator() (const boost::shared_ptr<T>& x, const boost::shared_ptr<T>& y) const {
	  return x->m_priority > y->m_priority;
  }
};

template <class T> struct greater : std::binary_function <boost::shared_ptr<T>,boost::shared_ptr<T>,bool> {
  bool operator() (const boost::shared_ptr<T>& x, const boost::shared_ptr<T>& y) const {return *x > *y;}
};

}
#endif /* HELPER_HPP_ */
