namespace cpp ws
namespace py ws

struct Coordinate {
 1: double lon
 2: double lat
}

exception WebServiceException {
  1: string what
}

service WebService {
  i64 findNode(1: string street, 2: string postal) throws (1:WebServiceException ouch)
  list<Coordinate> calcShortestWay(1: string algorithm,2: i64 startNode,3: i64 endNode)
}