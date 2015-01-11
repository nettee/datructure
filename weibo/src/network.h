#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "stack.h"

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <set>

/* Friend definition is like Edge in normal graph */
struct Friend {
    int dest;  // index of destination vertex
    int closeness;
    Friend *next;

    /* "dest" and "idx" are defined for Network */
    Friend(int idx) {
        dest = idx;
        closeness = 5;
        next = NULL;
    }
};

typedef std::list<Friend> List;

struct Rel {  // relationship
    int src;
    int dest;
    Rel(): src(-1), dest(-1) {}
    Rel(int a, int b) { src = a; dest = b; }
};

/* User definition is like Vertex in normal graph */
struct User {
    int uid;
    bool is_arti;  // articulation vertex, for circle dividing 
    List friends;

    /* default construction function for new in Network
     * uid is initialized to 0, which is never valid
     */
    User(): is_arti(false) { uid = 0; }
    User(int id): is_arti(false) { uid = id; }

    int hotness() {
        int acc = 0;
        for (List::const_iterator it = friends.begin();
                it != friends.end(); ++it) {
            acc += it->closeness;
        }
        return acc;
    }

    /* add a friend of id "uid" into friends list.
     * return true if a new friend is added
     * return false if friend already exist
     */
    bool add_rel_with(int idx) {
        for (List::const_iterator it = friends.begin();
                it != friends.end(); ++it) {
            if (it->dest == idx) {
                return false;
            }
        }
        friends.push_front(Friend(idx));
        return true;
    }

    void add_closeness_with(int idx, int incr) {
        for (List::iterator it = friends.begin(); it != friends.end(); ++it) {
            if (it->dest == idx) {
                it->closeness += incr;
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

    void print_user();
    void print_articulation();
    void print_circle();

    void top_user();

    int num_user() { return users.size(); }

private:
    std::vector<User> users;
    std::vector<Circle> circles;

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
