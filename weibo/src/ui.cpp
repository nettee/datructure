#include "network.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<string> split(const string&);
void split_at(const string&, int&, int&);

void main_loop(Network *net)
{
    while (true) {
        cout << ">>> ";
        string cmd;
        getline(cin, cmd);
        if (!cin) {
            cout << endl;
            return;
        } else if (cmd.empty()) {
            // deal with control-d case 
            continue;
        }

        vector<string> tokens = split(cmd);
        if (tokens[0] == "quit") {
            return;
        } else if (tokens[0] == "add") {
            if (tokens.size() < 3) {
                cout << "add: too few arguments" << endl;
                continue;
            }
            int uid1 = atoi(tokens[1].c_str());
            int uid2 = atoi(tokens[2].c_str());
            net->add_friends(uid1, uid2);
        } else if (tokens[0] == "at") {
            string s1;
            cin >> s1;
            int d1, d2;
            split_at(s1, d1, d2);
            cout << d1 << " @ " << d2 << endl;
        } else if (tokens[0] == "show") {
            net->print_network();
        } else if (tokens[0] == "analyse") {
            net->analyse();
        } else if (tokens[0] == "circle") {
            net->circle();
            net->print_articulation();
            net->print_circle();
        } else {
            cout << "invalid command '" << cmd << "'\n";
        }
    }
}
