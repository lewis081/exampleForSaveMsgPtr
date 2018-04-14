

#include "server.h"

int main(int argc, char *argv[])
{

    std::shared_ptr<Msg> msg(new Msg(100));

    Server server;

    std::cout<< "+++start call onInvoke"<< std::endl;
    server.onInvoke(msg);
    std::cout<< "---end call onInvoke"<< std::endl;

    std::cout<< "+++start simulate asyn callback"<< std::endl;
    server.asynCallback();
    std::cout<< "---end simulate asyn callback"<< std::endl;

    return 0;
}
