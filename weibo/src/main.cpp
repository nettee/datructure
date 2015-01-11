#include "network.h"

#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

void main_loop(Network *);

int main(int argc, char *argv[])
{
    const char *ff, *fa;
    int opt;
    while ((opt = getopt(argc, argv, "f:a:")) != -1) {
        if (opt == 'f') {
            ff = optarg;
        } else if (opt == 'a') {
            fa = optarg;
        }
    }
            
    Network *net = new Network;

    ifstream fs_friends(ff);
    ifstream fs_at(fa);
    net->import(fs_friends);
    net->add_at(fs_at);
    fs_friends.close();
    fs_at.close();

    net->divide_circle();
    
    main_loop(net);

    delete net;

    return 0;
}
