#include "network.h"
#include "vector.h"
#include <iostream>

using namespace std;

struct UserHot {
    int uid;
    int activeness;
    UserHot() { uid = -1; activeness = 0; }
    UserHot(int id, int h) { uid = id; activeness = h; }
};

bool user_hot_compare(const UserHot& uh1, const UserHot& uh2) {
    if (uh1.activeness > uh2.activeness) {
        return true;
    } else if (uh1.activeness < uh2.activeness) {
        return false;
    } else {
        return uh1.uid > uh2.uid;
    }
}

void Network::print_top_user(int n) {
    if (users.size() <= n) {
        cout << "Warning: there are altogether "
            << users.size() << " users" << endl;
    }
    Vector<UserHot> v;
    for (int i = 0; i < users.size(); i++) {
        int uid = users[i].uid;
        int activeness = users[i].activeness();
        v.push_back(UserHot(uid, activeness));
    }
    Vector<UserHot>::const_iterator it = v.begin();
    for (int i = 0; i < n; i++) {
        cout << "user " << it->uid << ": ";
        cout << "activeness " << it->activeness << endl;
        ++it;
        if (it == v.end()) {
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
    Vector<UserHot> v;
    for (Circle::const_iterator it = circles[cidx].begin();
            it != circles[cidx].end(); ++it) {
        int uid = users[*it].uid;
        int activeness = users[*it].activeness();
        v.push_back(UserHot(uid, activeness));
    }
    Vector<UserHot>::const_iterator it = v.begin();
    for (int i = 0; i < n; i++) {
        cout << "user " << it->uid << ": ";
        cout << "activeness " << it->activeness << endl;
        ++it;
        if (it == v.end()) {
            break;
        }
    }
}
