# coding=utf-8

import sys, glob
sys.path.append('gen-py')

from ws import WebService
from ws.ttypes import *

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

try:

  # Make socket
  transport = TSocket.TSocket('localhost', 9090)

  # Buffering is critical. Raw sockets are very slow
  transport = TTransport.TBufferedTransport(transport)

  # Wrap in a protocol
  protocol = TBinaryProtocol.TBinaryProtocol(transport)

  # Create a client to use the protocol encoder
  client = WebService.Client(protocol)

  transport.open()

  id1 = client.findNode("Luisenstraße","41564")
  id2 = client.findNode("Webschulstraße","41065")

  route = client.calcShortestWay("astar",id1,id2)
  for coord in route:
    print("%s,%s" % (coord.lat,coord.lon))

  transport.close()

except WebServiceException, tx:
  print '%s' % (tx.what)
