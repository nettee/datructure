#include "network.h"

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

using namespace std;

void split_at(const string&, int&, int&);

void Network::import(istream& is) {
    users.clear();
    int uid1, uid2;
    while (is >> uid1 && is >> uid2) {
        add_friends(uid1, uid2);
    }
}

void Network::add_at(istream& is) {
    string line;
    while (getline(is, line)) {
        int ater, atee;
        try {
            split_at(line, ater, atee);
            add_closeness(ater, atee);
        } catch (out_of_range) {
            // invalid input format, simply ignore
            ;
        }
    }
}
    
bool Network::add_friends(int uid1, int uid2) {
    // ignore duplicate adding
    if (uid1 == uid2)
        return false;

    int idx1 = find_create(uid1);
    int idx2 = find_create(uid2);

    users[idx1].add_rel_with(idx2);
    users[idx2].add_rel_with(idx1);

    return true;
}

bool Network::add_closeness(int uid1, int uid2) {
    if (uid1 == uid2)
        return false;

    int idx1 = find(uid1);
    int idx2 = find(uid2);

    users[idx1].add_closeness_with(idx2, 3);
    users[idx2].add_closeness_with(idx1, 1);

    return true;
}

int Network::find(int uid) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].uid == uid) {
            return i;
        }
    }
    return -1;
}

int Network::find_create(int uid) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].uid == uid) {
            return i;
        }
    }

    /* if no element found, create a new user */
    User u(uid);
    users.push_back(u);
    return users.size() - 1;
}

void Network::output() {
    for (int i = 0; i < users.size(); i++) {
        cout << "user " << users[i].uid << ":";
        for (List::const_iterator it = users[i].friends.begin(); it != users[i].friends.end(); ++it) {
            cout << " " << users[it->dest].uid;
            cout << "(" << it->closeness << ")"; 
        }
        cout << endl;
    }
}

void Network::analyse() {
    return;
    cout << "number of users: " << num_user() << endl;
//    cout << "number of relationships: " << num_rel << endl;
}
