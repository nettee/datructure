#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "stack.h"
#include "vector.h"

#include <iostream>
#include <set>

/* Friend definition is like Edge in normal graph */
struct Friend {
    int dest;  // index of destination vertex
    int closeness;
    Friend *next;

    Friend(): dest(-1), closeness(0), next(NULL) {}
    /* "dest" and "idx" are defined for Network */
    Friend(int idx): closeness(5), next(NULL) { dest = idx; }
};

struct Rel {  // relation
    int src;
    int dest;
    int closeness;

    Rel(): src(-1), dest(-1), closeness(0) {}
    Rel(int a, int b): closeness(1) { src = a; dest = b; }
    Rel(int a, int b, int c) { src = a; dest = b; closeness = c; }

    // overloaded comparison functions for top_relation use
    bool operator<(const Rel& rhs) const {
        return closeness < rhs.closeness
            || closeness == rhs.closeness && src > rhs.src
            || closeness == rhs.closeness 
                && src == rhs.src && dest > rhs.dest;
    }
    bool operator>(const Rel& rhs) const {
        return closeness > rhs.closeness
            || closeness == rhs.closeness && src < rhs.src
            || closeness == rhs.closeness 
                && src == rhs.src && dest < rhs.dest;
    }
    bool operator==(const Rel& rhs) const {
        return closeness == rhs.closeness 
            && src == rhs.src && dest == rhs.dest;
    }
};

/* User definition is like Vertex in normal graph */
struct User {
    int uid;
    bool is_arti;  // articulation vertex, for circle dividing 
    Friend *friends;  // adjancent list, single-linked list

    /* default construction function for new in Network
     * uid is initialized to 0, which is never valid
     */
    User(): uid(-1), is_arti(false), friends(NULL) {}
    User(int id): is_arti(false), friends(NULL) { uid = id; }

    int activeness() {
        int acc = 0;
        for (Friend *f = friends; f != NULL; f = f->next) {
            acc += f->closeness;
        }
        return acc;
    }

    /* add a friend of id "uid" into friends list.
     * return true if a new friend is added
     * return false if friend already exist
     */
    bool add_rel_with(int idx) {
        for (Friend *f = friends; f != NULL; f = f->next) {
            if (f->dest == idx) {
                return false;
            }
        }
        /* insert into the front of list */
        Friend *q= new Friend(idx);
        q->next = friends;
        friends = q;
        return true;
    }

    void add_closeness_with(int idx, int incr) {
        for (Friend *f = friends; f != NULL; f = f->next) {
            if (f->dest == idx) {
                f->closeness += incr;
            }
        }
    }
};

typedef std::set<int> Circle;

class Network {
public:
    /* read users from cin, establish a network 
     * return: number of users added
     */
    void import(std::istream& is);
    void add_at(std::istream& is);
    bool add_friends(int uid1, int uid2);
    bool add_closeness(int ater, int atee);

    bool enter_user(int uid);
    bool enter_circle(int cid);

    void divide_circle();
    void build_rel();

    void print_user(int idx);
    void print_all_user();
    void print_top_user(int n);

    void print_user_in_circle(int cidx);

    void print_articulation();
    void print_circle(int cidx);
    void print_all_circle();
    void print_top_circle(int n);

    void print_rel(const Rel& r);
    void print_all_rel();
    void print_top_rel(int n);

    int num_user() { return users.size(); }

private:
    Vector<User> users;
    Vector<Circle> circles;
    std::set<Rel> rels;

    /* search in veritices for given uid, return index of vertex
     * "find" will return -1 if vertex not found
     * "find_create" will create a new vertex
     */
    int find_no_create(int uid);
    int find_create(int uid);

    // for DFS use
    bool *visited;
    int *dfn;
    int *low;
    int *parent;
    void dfs(int u, Stack<Rel>& s);
};

#endif
