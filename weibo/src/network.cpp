#include "network.h"

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <set>

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

    int idx1 = find_no_create(uid1);
    int idx2 = find_no_create(uid2);

    users[idx1].add_closeness_with(idx2, 3);
    users[idx2].add_closeness_with(idx1, 3);

    return true;
}

bool Network::are_friends_by_index(int idx1, int idx2) {
    for (Friend *f = users[idx1].friends; f != NULL; f = f->next) {
        if (f->dest == idx2) {
            return true;
        }
    }
    return false;
}

int Network::closeness_of(int idx1, int idx2) {
    for (Friend *f = users[idx1].friends; f != NULL; f = f->next) {
        if (f->dest == idx2) {
            return f->closeness;
        }
    }
    return -1;
}

bool Network::are_friends(int uid1, int uid2) {
    if (uid1 == uid2) 
        return false;

    int idx1 = find_no_create(uid1);
    int idx2 = find_no_create(uid2);

    if (idx1 == -1 || idx2 == -1)
        return false;

    return are_friends_by_index(idx1, idx2);
}

void Network::print_all_friends_with(int uid) {
    int uidx = find_no_create(uid);
    set<Friend> s;
    for (Friend *f = users[uidx].friends; f != NULL; f = f->next) {
        s.insert(*f);
    }
    cout << "All friends of user " << users[uidx].uid << ": " << endl;
    for (set<Friend>::const_reverse_iterator rit = s.rbegin();
            rit != s.rend(); ++rit) {
        cout << "friend " << users[rit->dest].uid
            << ": closeness " << rit->closeness << endl;
    }
}

void Network::print_top_friends_with(int uid, int n) {
    int uidx = find_no_create(uid);
    set<Friend> s;
    for (Friend *f = users[uidx].friends; f != NULL; f = f->next) {
        s.insert(*f);
    }
    if (s.size() < n) {
        cout << "Warning: there are altogether "
            << s.size() << " friends" << endl;
    }

    cout << "Top " << n << " friends of user " << users[uidx].uid << ": " << endl;
    set<Friend>::const_reverse_iterator rit = s.rbegin();
    for (int i = 0; i < n; i++) {
        cout << "friend " << users[rit->dest].uid
            << ": closeness " << rit->closeness << endl;
        ++rit;
        if (rit == s.rend()) {
            break;
        }
    }
}

bool Network::user_in_circle(int uidx, int cidx) {
    for (Circle::const_iterator it = circles[cidx].begin();
            it != circles[cidx].end(); ++it) {
        if (*it == uidx) {
            return true;
        }
    }
    return false;
}

int Network::find_no_create(int uid) {
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

bool Network::enter_user(int uid) {
    int idx = find_no_create(uid);
    if (idx == -1) {
        cout << "user " << uid << " does not exist" << endl;
        return false;
    }
    cout << "user " << users[idx].uid << ":";
    for (Friend *f = users[idx].friends; f != NULL; f = f->next) {
        cout << " " << users[f->dest].uid;
        cout << "(" << f->closeness << ")"; 
    }
    cout << endl;
    return true;
}

bool Network::enter_circle(int cid) {
    if (cid < 0 || cid >= circles.size()) {
        cout << "circle " << cid << " does not exist" << endl;
        return false;
    }
    cout << "Circle[" << cid << "]:";
    for (Circle::const_iterator it = circles[cid].begin();
            it != circles[cid].end(); ++it) {
        cout << " " << users[*it].uid;
    }
    cout << endl;
    return true;
}

void Network::print_articulation() {
    cout << "articulation nodes:";
    for (int i = 0; i < users.size(); i++) {
        if (users[i].is_arti) {
            cout << " " << users[i].uid;
        }
    }
    cout << endl;
}
