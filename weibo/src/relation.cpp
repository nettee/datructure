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
        cout << "Warning: asking for " << n << " relations, only " 
            << rels.size() << " relations in all." << endl;
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
