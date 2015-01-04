/*
 * EdgeInformation.cpp
 *
 *  Created on: 26.12.2014
 *      Author: florian
 */

#include "Graph/EdgeInformation.h"

namespace Graph {

EdgeInformation::EdgeInformation(std::string street, std::string postal) {
	_street = street;
	_postal = postal;
}

EdgeInformation::EdgeInformation() : EdgeInformation("","") {
}

EdgeInformation::EdgeInformation(const EdgeInformation &other) {
	_street = other._street;
	_postal = other._postal;
}

}
