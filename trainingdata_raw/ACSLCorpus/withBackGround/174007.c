#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    predicate vector_valid(int *v) = 
        \valid(v) && \valid(v+1) && \valid(v+2) &&
        valid_range(v[0]) && valid_range(v[1]) && valid_range(v[2]);
*/

/*@
    requires vector_valid(v);
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;
    
    a = v[0];
    b = v[1];
    c = v[2];
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    //@ assert (a < b && b < c) ==> (a < b && b < c);
    
    result = (a < b && b < c);
    return result;
}
