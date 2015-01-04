/*
 * EdgeInformation.h
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include <string>
#include <boost/shared_ptr.hpp>

#ifndef EDGEINFORMATION_H_
#define EDGEINFORMATION_H_

namespace Graph {

struct EdgeInformation {
	std::string _street;
	std::string _postal;

public:
	EdgeInformation(std::string street, std::string postal);
	EdgeInformation(const EdgeInformation &other);
	EdgeInformation();
};

typedef boost::shared_ptr<EdgeInformation> EdgeInformation_sp;

}

#endif /* EDGEINFORMATION_H_ */
