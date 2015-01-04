CXXFLAGS =	-O3 -g -Wall -fmessage-length=0 -std=c++11 -Iosmpbf -fopenmp -g -fPIC

OBJS_SHARED =		Node.o Edge.o EdgeInformation.o Storage.o StorageOSM.o ClosedList.o OpenListNode.o OpenList.o AStar.o Dijkstra.o Manager.o Rauter.o gen-cpp/WebService.o gen-cpp/service_constants.o gen-cpp/service_types.o
OBJS_BIN = Rauter.o
LIBS =		-lGeographic libosmpbf.a  -lprotobuf -lboost_system -lz  libhttpserver.a libmicrohttpd.a -lz -lpthread -lthrift

TARGET =	Rauter


all:	$(TARGET)

$(TARGET):	$(OBJS_SHARED)
	$(CXX) -o $(TARGET) $(OBJS_SHARED) $(LIBS)

clean:
	rm -f $(OBJS_SHARED) $(OBJS_BIN) librauter.so $(TARGET)
