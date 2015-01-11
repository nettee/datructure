#include "network.h"
#include <iostream>
#include <set>

using namespace std;

struct UserHot {
    int uid;
    int activeness;
    UserHot() { uid = -1; activeness = 0; }
    UserHot(int id, int h) { uid = id; activeness = h; }
    bool operator<(const UserHot& rhs) const {
        return activeness < rhs.activeness 
            || activeness == rhs.activeness && uid < rhs.uid;
    }
    bool operator>(const UserHot& rhs) const {
        return activeness > rhs.activeness
            || activeness == rhs.activeness && uid > rhs.uid;
    }
    bool operator==(const UserHot& rhs) const {
        return uid == rhs.uid && activeness == rhs.activeness;
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
        int activeness = users[i].activeness();
        s.insert(UserHot(uid, activeness));
    }
    set<UserHot>::const_reverse_iterator rit = s.rbegin();
    for (int i = 0; i < n; i++) {
        cout << "user " << rit->uid << ": ";
        cout << "activeness " << rit->activeness << endl;
        ++rit;
    }
}


