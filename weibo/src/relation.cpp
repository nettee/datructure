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

void Network::top_rel(int n) {
    if (rels.size() < n) {
        cout << "Warning: asking for " << n << " relations, only " 
            << rels.size() << " relations in all." << endl;
    }
    set<Rel>::const_reverse_iterator rit = rels.rbegin();
    for (int i = 0; i < n; i++) {
        cout << "(user " << users[rit->src].uid 
            << ", user " << users[rit->dest].uid
            << "): closeness " << rit->closeness << endl;
        ++rit;
        if (rit == rels.rend()) {
            break;
        }
    }
}
