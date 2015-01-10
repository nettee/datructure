#include "network.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

enum Mode { GLOBAL, USER, CIRCLE };

vector<string> split(const string&);
void split_at(const string&, int&, int&);

void main_loop(Network *net)
{
    Mode mode = GLOBAL;
    int id = -1;  // circle id if mode == CIRCLE, uid if mode == USER

    while (true) {
        // print prompt
        if (mode == GLOBAL) {
            cout << ">>> ";
        } else if (mode == USER) {
            cout << "(user " << id << "): ";
        } else if (mode == CIRCLE) {
            cout << "(circle " << id << "): ";
        }

        // read a line of command
        string cmd;
        getline(cin, cmd);
        if (!cin) {
            cout << endl;
            return;
        } else if (cmd.empty()) {
            // deal with control-d case 
            continue;
        }

        // command parsing and executing
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

        } else if (tokens[0] == "enter") {
            if (tokens.size() < 3) {
                cout << "enter: too few arguments" << endl;
                continue;
            }
            if (tokens[1] == "user") {
                int uid = atoi(tokens[2].c_str());
                if (net->enter_user(uid)) {
                    mode = USER;
                    id = uid;
                }
            } else if (tokens[1] == "circle") {
                int cid = atoi(tokens[2].c_str());
                if (net->enter_circle(cid)) {
                    mode = CIRCLE;
                    id = cid;
                }
            } else {
                cout << "enter: invalid argument" << endl;
            }
        } else if (tokens[0] == "exit") {
            mode = GLOBAL;
            id = -1;

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
