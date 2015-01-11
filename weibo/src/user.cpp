#include "network.h"
#include <iostream>
#include <set>

using namespace std;

struct UserHot {
    int uid;
    int hotness;
    UserHot() { uid = -1; hotness = 0; }
    UserHot(int id, int h) { uid = id; hotness = h; }
    bool operator<(const UserHot& rhs) const {
        return hotness < rhs.hotness 
            || hotness == rhs.hotness && uid < rhs.uid;
    }
    bool operator>(const UserHot& rhs) const {
        return hotness > rhs.hotness
            || hotness == rhs.hotness && uid > rhs.uid;
    }
    bool operator==(const UserHot& rhs) const {
        return uid == rhs.uid && hotness == rhs.hotness;
    }
};

void Network::top_user(int n) {
    if (users.size() <= n) {
        cout << "Error: there are altogether "
            << users.size() << "users" << endl;
        return;
    }
    set<UserHot> s;
    for (int i = 0; i < users.size(); i++) {
        int uid = users[i].uid;
        int hotness = users[i].hotness();
        s.insert(UserHot(uid, hotness));
    }
    set<UserHot>::const_reverse_iterator rit = s.rbegin();
    for (int i = 0; i < n; i++) {
        cout << "user " << rit->uid << ": ";
        cout << "hotness " << rit->hotness << endl;
        ++rit;
    }
}


