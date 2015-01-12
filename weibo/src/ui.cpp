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

        } else if (tokens[0] == "users") {
            if (mode == CIRCLE) {
                cout << net->num_user_in_circle(id)
                    << " users in circle[" << id << "]." << endl;
            } else {
                cout << net->num_user() << " users in total." << endl;
            }
        } else if (tokens[0] == "circles") {
            cout << net->num_circle() << " circles in total." << endl;
        } else if (tokens[0] == "relations") {
            cout << net->num_rel() << " relations in total." << endl;

        } else if (tokens[0] == "all") {
            if (tokens[1] == "users") {
                if (mode == GLOBAL) {
                    net->print_all_user();
                } else if (mode == CIRCLE) {
                    net->print_all_user_in_circle(id);
                } else {
                    cout << "'all users': wrong mode" << endl;
                }
            } else if (tokens[1] == "circles") {
                if (mode == GLOBAL) {
                    net->print_articulation();
                    net->print_all_circle();
                } else {
                    cout << "'all circles': wrong mode" << endl;
                }
            } else if (tokens[1] == "relations") {
                if (mode == GLOBAL) {
                    net->print_all_rel();
                } else if (mode == CIRCLE) {
                    net->print_all_rel_in_circle(id);
                } else {
                    cout << "'all relations': wrong mode" << endl;
                }
            } else {
                cout << "all: invalid arguments" << endl;
            }

        } else if (tokens[0] == "top") {
            if (tokens.size() < 2) {
                cout << "top: too few arguments" << endl;
                continue;
            } else if (tokens.size() == 2) {
                if (tokens[1] == "users") {
                    if (mode == GLOBAL) {
                        net->print_top_user(10);
                    } else if (mode == CIRCLE) {
                        net->print_top_user_in_circle(id, 10);
                    } else {
                        cout << "'top users': wrong mode" << endl;
                    }
                } else if (tokens[1] == "circles") {
                    if (mode == GLOBAL) {
                        net->print_top_circle(5);
                    } else {
                        cout << "'top circles': wrong mode" << endl;
                    }
                } else if (tokens[1] == "relations") {
                    if (mode == GLOBAL) {
                        net->print_top_rel(12);
                    } else if (mode == CIRCLE) {
                        net->print_top_rel_in_circle(id, 8);
                    } else {
                        cout << "'top relations': wrong mode" << endl;
                    }
                } else {
                    cout << "top: invalid arguments" << endl;
                }
            } else {
                int n = atoi(tokens[1].c_str());
                if (tokens[2] == "users") {
                    if (mode == GLOBAL) {
                        net->print_top_user(n);
                    } else if (mode == CIRCLE) {
                        net->print_top_user_in_circle(id, n);
                    } else {
                        cout << "'top users': wrong mode" << endl;
                    }
                } else if (tokens[2] == "circles") {
                    if (mode == GLOBAL) {
                        net->print_top_circle(n);
                    } else {
                        cout << "'top circles': wrong mode" << endl;
                    }
                } else if (tokens[2] == "relations") {
                    if (mode == GLOBAL) {
                        net->print_top_rel(n);
                    } else if (mode == CIRCLE) {
                        net->print_top_rel_in_circle(id, n);
                    } else {
                        cout << "'top relations':wrong mode" << endl;
                    }
                } else {
                    cout << "top: invalid arguments" << endl;
                }
            }

        } else {
            cout << "invalid command '" << cmd << "'\n";
        }
    }
}
