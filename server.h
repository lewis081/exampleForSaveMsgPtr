#ifndef SERVER_H
#define SERVER_H

#include "dontcare.h"


class MyHandler : public ResponseHandler
{
public:
    MyHandler(MsgPtr msgPr):
        _msgPtr(msgPr)
    {
    }

    virtual void handle()
    {
        std::cout<< "I'm in class MyHandler"<< std::endl;
        _msgPtr->relpy();
    }
private:
    MsgPtr _msgPtr;
};

class Server{
public:
    void onInvoke(MsgPtr& msg )
    {
        ResponseHandler* handler = new MyHandler(msg);
        _rsiClient.sendRequest(1, *handler);
    }

    // just for simulating asyn callback
    void asynCallback()
    {
        _rsiClient.asynCallback();
    }

private:
    RSIClient _rsiClient;
};

#endif // SERVER_H
