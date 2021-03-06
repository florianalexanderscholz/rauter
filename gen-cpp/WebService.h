/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef WebService_H
#define WebService_H

#include <thrift/TDispatchProcessor.h>
#include "service_types.h"

namespace ws {

class WebServiceIf {
 public:
  virtual ~WebServiceIf() {}
  virtual int64_t findNode(const std::string& street, const std::string& postal) = 0;
  virtual void calcShortestWay(std::vector<Coordinate> & _return, const std::string& algorithm, const int64_t startNode, const int64_t endNode) = 0;
};

class WebServiceIfFactory {
 public:
  typedef WebServiceIf Handler;

  virtual ~WebServiceIfFactory() {}

  virtual WebServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(WebServiceIf* /* handler */) = 0;
};

class WebServiceIfSingletonFactory : virtual public WebServiceIfFactory {
 public:
  WebServiceIfSingletonFactory(const boost::shared_ptr<WebServiceIf>& iface) : iface_(iface) {}
  virtual ~WebServiceIfSingletonFactory() {}

  virtual WebServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(WebServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<WebServiceIf> iface_;
};

class WebServiceNull : virtual public WebServiceIf {
 public:
  virtual ~WebServiceNull() {}
  int64_t findNode(const std::string& /* street */, const std::string& /* postal */) {
    int64_t _return = 0;
    return _return;
  }
  void calcShortestWay(std::vector<Coordinate> & /* _return */, const std::string& /* algorithm */, const int64_t /* startNode */, const int64_t /* endNode */) {
    return;
  }
};

typedef struct _WebService_findNode_args__isset {
  _WebService_findNode_args__isset() : street(false), postal(false) {}
  bool street;
  bool postal;
} _WebService_findNode_args__isset;

class WebService_findNode_args {
 public:

  WebService_findNode_args() : street(), postal() {
  }

  virtual ~WebService_findNode_args() throw() {}

  std::string street;
  std::string postal;

  _WebService_findNode_args__isset __isset;

  void __set_street(const std::string& val) {
    street = val;
  }

  void __set_postal(const std::string& val) {
    postal = val;
  }

  bool operator == (const WebService_findNode_args & rhs) const
  {
    if (!(street == rhs.street))
      return false;
    if (!(postal == rhs.postal))
      return false;
    return true;
  }
  bool operator != (const WebService_findNode_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_findNode_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class WebService_findNode_pargs {
 public:


  virtual ~WebService_findNode_pargs() throw() {}

  const std::string* street;
  const std::string* postal;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_findNode_result__isset {
  _WebService_findNode_result__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _WebService_findNode_result__isset;

class WebService_findNode_result {
 public:

  WebService_findNode_result() : success(0) {
  }

  virtual ~WebService_findNode_result() throw() {}

  int64_t success;
  WebServiceException ouch;

  _WebService_findNode_result__isset __isset;

  void __set_success(const int64_t val) {
    success = val;
  }

  void __set_ouch(const WebServiceException& val) {
    ouch = val;
  }

  bool operator == (const WebService_findNode_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const WebService_findNode_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_findNode_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_findNode_presult__isset {
  _WebService_findNode_presult__isset() : success(false), ouch(false) {}
  bool success;
  bool ouch;
} _WebService_findNode_presult__isset;

class WebService_findNode_presult {
 public:


  virtual ~WebService_findNode_presult() throw() {}

  int64_t* success;
  WebServiceException ouch;

  _WebService_findNode_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _WebService_calcShortestWay_args__isset {
  _WebService_calcShortestWay_args__isset() : algorithm(false), startNode(false), endNode(false) {}
  bool algorithm;
  bool startNode;
  bool endNode;
} _WebService_calcShortestWay_args__isset;

class WebService_calcShortestWay_args {
 public:

  WebService_calcShortestWay_args() : algorithm(), startNode(0), endNode(0) {
  }

  virtual ~WebService_calcShortestWay_args() throw() {}

  std::string algorithm;
  int64_t startNode;
  int64_t endNode;

  _WebService_calcShortestWay_args__isset __isset;

  void __set_algorithm(const std::string& val) {
    algorithm = val;
  }

  void __set_startNode(const int64_t val) {
    startNode = val;
  }

  void __set_endNode(const int64_t val) {
    endNode = val;
  }

  bool operator == (const WebService_calcShortestWay_args & rhs) const
  {
    if (!(algorithm == rhs.algorithm))
      return false;
    if (!(startNode == rhs.startNode))
      return false;
    if (!(endNode == rhs.endNode))
      return false;
    return true;
  }
  bool operator != (const WebService_calcShortestWay_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_calcShortestWay_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class WebService_calcShortestWay_pargs {
 public:


  virtual ~WebService_calcShortestWay_pargs() throw() {}

  const std::string* algorithm;
  const int64_t* startNode;
  const int64_t* endNode;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_calcShortestWay_result__isset {
  _WebService_calcShortestWay_result__isset() : success(false) {}
  bool success;
} _WebService_calcShortestWay_result__isset;

class WebService_calcShortestWay_result {
 public:

  WebService_calcShortestWay_result() {
  }

  virtual ~WebService_calcShortestWay_result() throw() {}

  std::vector<Coordinate>  success;

  _WebService_calcShortestWay_result__isset __isset;

  void __set_success(const std::vector<Coordinate> & val) {
    success = val;
  }

  bool operator == (const WebService_calcShortestWay_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const WebService_calcShortestWay_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const WebService_calcShortestWay_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _WebService_calcShortestWay_presult__isset {
  _WebService_calcShortestWay_presult__isset() : success(false) {}
  bool success;
} _WebService_calcShortestWay_presult__isset;

class WebService_calcShortestWay_presult {
 public:


  virtual ~WebService_calcShortestWay_presult() throw() {}

  std::vector<Coordinate> * success;

  _WebService_calcShortestWay_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class WebServiceClient : virtual public WebServiceIf {
 public:
  WebServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  WebServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int64_t findNode(const std::string& street, const std::string& postal);
  void send_findNode(const std::string& street, const std::string& postal);
  int64_t recv_findNode();
  void calcShortestWay(std::vector<Coordinate> & _return, const std::string& algorithm, const int64_t startNode, const int64_t endNode);
  void send_calcShortestWay(const std::string& algorithm, const int64_t startNode, const int64_t endNode);
  void recv_calcShortestWay(std::vector<Coordinate> & _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class WebServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<WebServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (WebServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_findNode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_calcShortestWay(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  WebServiceProcessor(boost::shared_ptr<WebServiceIf> iface) :
    iface_(iface) {
    processMap_["findNode"] = &WebServiceProcessor::process_findNode;
    processMap_["calcShortestWay"] = &WebServiceProcessor::process_calcShortestWay;
  }

  virtual ~WebServiceProcessor() {}
};

class WebServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  WebServiceProcessorFactory(const ::boost::shared_ptr< WebServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< WebServiceIfFactory > handlerFactory_;
};

class WebServiceMultiface : virtual public WebServiceIf {
 public:
  WebServiceMultiface(std::vector<boost::shared_ptr<WebServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~WebServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<WebServiceIf> > ifaces_;
  WebServiceMultiface() {}
  void add(boost::shared_ptr<WebServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int64_t findNode(const std::string& street, const std::string& postal) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->findNode(street, postal);
    }
    return ifaces_[i]->findNode(street, postal);
  }

  void calcShortestWay(std::vector<Coordinate> & _return, const std::string& algorithm, const int64_t startNode, const int64_t endNode) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->calcShortestWay(_return, algorithm, startNode, endNode);
    }
    ifaces_[i]->calcShortestWay(_return, algorithm, startNode, endNode);
    return;
  }

};

} // namespace

#endif
