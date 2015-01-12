#include "network.h"

#include <iostream>

using namespace std;

void Network::build_rel() {
    for (int i = 0; i < users.size(); i++) {
        for (Friend *f = users[i].friends; f != NULL; f = f->next) {
            // add condition < to avoid repetition
            if (i < f->dest) {
                rels.insert(Rel(i, f->dest, f->closeness));
            }
        }
    }
}

void Network::print_rel(const Rel& r) {
    cout << "(user " << users[r.src].uid 
        << ", user " << users[r.dest].uid
        << "): closeness " << r.closeness << endl;
}

void Network::print_all_rel() {
    for (set<Rel>::const_reverse_iterator rit = rels.rbegin();
            rit != rels.rend(); ++rit) {
        print_rel(*rit);
    }
}

void Network::print_top_rel(int n) {
    if (rels.size() < n) {
        cout << "Warning: there are altogether "
            << rels.size() << " relations" << endl;
    }
    set<Rel>::const_reverse_iterator rit = rels.rbegin();
    for (int i = 0; i < n; i++) {
        print_rel(*rit);
        ++rit;
        if (rit == rels.rend()) {
            break;
        }
    }
}

void Network::print_all_rel_in_circle(int cidx) {
    // filter relations in global set
    set<Rel> s;
    for (set<Rel>::const_iterator it = rels.begin();
            it != rels.end(); ++it) {
        if (user_in_circle(it->src, cidx) 
                && user_in_circle(it->dest, cidx)) {
            s.insert(*it);
        }
    }
    for (set<Rel>::const_reverse_iterator rit = s.rbegin();
            rit != s.rend(); ++rit) {
        print_rel(*rit);
    }
}

void Network::print_top_rel_in_circle(int cidx, int n) {
    set<Rel> s;
    for (set<Rel>::const_iterator it = rels.begin();
            it != rels.end(); ++it) {
        if (user_in_circle(it->src, cidx) 
                && user_in_circle(it->dest, cidx)) {
            s.insert(*it);
        }
    }

    if (s.size() < n) {
        cout << "Warning: there are altogether "
            << s.size() << " relations" << endl;
    }
    set<Rel>::const_reverse_iterator rit = s.rbegin();
    for (int i = 0; i < n; i++) {
        print_rel(*rit);
        ++rit;
        if (rit == s.rend()) {
            break;
        }
    }
}
