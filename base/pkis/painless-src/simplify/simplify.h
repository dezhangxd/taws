#ifndef _simplify_h_INCLUDED
#define _simplify_h_INCLUDED

#include "pamap.h"
using namespace std;
#define MAX_XOR 6
typedef long long ll;

struct xorgate {
    xorgate(int _c, int _rhs, int _sz) {
        c = _c, rhs = _rhs, sz = _sz;
    }
public:
    int c;
    int rhs;
    int sz;
};

struct simplify {
public:   
    simplify();
    int vars;
    int clauses;
    svec<svec<int>> clause, res_clause;
    string infile;
    void readfile(const char *file);
    void print_cnf(const char *file);
    void release();
    
    // simplify data structure
    int maxlen, orivars, oriclauses, res_clauses, resolutions;
    int *f, nlit, *a, *val, *color, *varval, *q, *seen, *resseen, *clean, *mapto, *mapfrom, *mapval;
    threadsafe_lookup_table<ll, int> C;
    svec<int> *occurp, *occurn, clause_delete, nxtc, resolution;

    ll mapv(int a, int b);
    int find(int x);    
    bool res_is_empty(int var);
    void update_var_clause_label();
    void simplify_init();
    bool simplify_resolution();
    bool simplify_binary();
    bool simplify_easy_clause();

    void print_complete_model();
};

#endif