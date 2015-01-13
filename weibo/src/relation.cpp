#include "network.h"
#include "vector.h"

#include <iostream>
#include <algorithm>

using namespace std;

bool rel_compare(const Rel& r1, const Rel& r2) {
    if (r1.closeness > r2.closeness) {
        return true;
    } else if (r1.closeness < r2.closeness) {
        return false;
    } else {
        if (r1.src > r2.src) {
            return true;
        } else if (r1.src < r2.src) {
            return false;
        } else {
            return r1.dest > r2.dest;
        }
    }
}

void Network::build_rel() {
    for (int i = 0; i < users.size(); i++) {
        for (Friend *f = users[i].friends; f != NULL; f = f->next) {
            // add condition < to avoid repetition
            if (i < f->dest) {
                rels.push_back(Rel(i, f->dest, f->closeness));
            }
        }
    }
    sort(rels.begin(), rels.end(), rel_compare);
}

void Network::print_rel(const Rel& r) {
    cout << "(user " << users[r.src].uid 
        << ", user " << users[r.dest].uid
        << "): closeness " << r.closeness << endl;
}

void Network::print_all_rel() {
    for (Vector<Rel>::const_iterator it = rels.begin();
            it != rels.end(); ++it) {
        print_rel(*it);
    }
}

void Network::print_top_rel(int n) {
    if (rels.size() < n) {
        cout << "Warning: there are altogether "
            << rels.size() << " relations" << endl;
    }
    Vector<Rel>::const_iterator it = rels.begin();
    for (int i = 0; i < n; i++) {
        print_rel(*it);
        ++it;
        if (it == rels.end()) {
            break;
        }
    }
}

void Network::print_all_rel_in_circle(int cidx) {
    // filter relations in global set
    Vector<Rel> v;
    for (Vector<Rel>::const_iterator it = rels.begin();
            it != rels.end(); ++it) {
        if (user_in_circle(it->src, cidx) 
                && user_in_circle(it->dest, cidx)) {
            v.push_back(*it);
        }
    }
    sort(v.begin(), v.end(), rel_compare);
    for (Vector<Rel>::const_iterator it = v.begin();
            it != v.end(); ++it) {
        print_rel(*it);
    }
}

void Network::print_top_rel_in_circle(int cidx, int n) {
    Vector<Rel> v;
    for (Vector<Rel>::const_iterator it = rels.begin();
            it != rels.end(); ++it) {
        if (user_in_circle(it->src, cidx) 
                && user_in_circle(it->dest, cidx)) {
            v.push_back(*it);
        }
    }
    sort(v.begin(), v.end(), rel_compare);

    if (v.size() < n) {
        cout << "Warning: there are altogether "
            << v.size() << " relations" << endl;
    }
    Vector<Rel>::const_iterator it = v.begin();
    for (int i = 0; i < n; i++) {
        print_rel(*it);
        ++it;
        if (it == v.end()) {
            break;
        }
    }
}
