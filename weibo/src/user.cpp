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

void Network::print_top_user(int n) {
    if (users.size() <= n) {
        cout << "Warning: there are altogether "
            << users.size() << " users" << endl;
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
        if (rit == s.rend()) {
            break;
        }
    }
}

void Network::print_all_user() {
    for (int i = 0; i < users.size(); i++) {
        print_user(i);
    }
}

void Network::print_user(int idx) {
    cout << "user " << users[idx].uid << ":";
    for (Friend *f = users[idx].friends; f != NULL; f = f->next) {
        cout << " " << users[f->dest].uid;
        cout << "(" << f->closeness << ")"; 
    }
    cout << endl;
}

void Network::print_all_user_in_circle(int cidx) {
    for (Circle::const_iterator it = circles[cidx].begin();
            it != circles[cidx].end(); ++it) {
        print_user(*it);
    }
}

void Network::print_top_user_in_circle(int cidx, int n) {
    if (circles[cidx].size() <= n) {
        cout << "Warning: there are altogether "
            << circles[cidx].size() << " users" << endl;
    }
    set<UserHot> s;
    for (Circle::const_iterator it = circles[cidx].begin();
            it != circles[cidx].end(); ++it) {
        int uid = users[*it].uid;
        int activeness = users[*it].activeness();
        s.insert(UserHot(uid, activeness));
    }
    set<UserHot>::const_reverse_iterator rit = s.rbegin();
    for (int i = 0; i < n; i++) {
        cout << "user " << rit->uid << ": ";
        cout << "activeness " << rit->activeness << endl;
        ++rit;
        if (rit == s.rend()) {
            break;
        }
    }
}
