#ifndef DONTCARE_H
#define DONTCARE_H

#include <memory>
#include <map>
#include <iostream>

class Msg{
public:
    Msg(int num = 0):
        _num(num)
    {
    }

    void relpy()
    {
        std::cout<< "my num is: "<<_num<< std::endl;
    }
private:
    int _num;
};

typedef std::shared_ptr<Msg> MsgPtr;

class ResponseHandler
{
public:
    virtual void handle() = 0;
};


class RSIClient{
public:
    ~RSIClient()
    {
        // need delete ResponseHandler* space in map
    }

    void sendRequest(int a, ResponseHandler& h){
        id_h.insert(std::pair<int, ResponseHandler*>(1, &h));//save
    }

    void asynCallback(){
        std::map<int, ResponseHandler*>::iterator ii = id_h.begin();
        (*ii).second->handle();
    }
private:
    std::map<int , ResponseHandler*> id_h;
};


#endif // DONTCARE_H
