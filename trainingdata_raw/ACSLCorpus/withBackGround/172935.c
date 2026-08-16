#include <stdbool.h>

/*@
    predicate valid_vector(int *v) =
        \valid(v) && \valid(v+1) && \valid(v+2) &&
        1 <= v[0] && v[0] <= 9 && 
        1 <= v[1] && v[1] <= 9 && 
        1 <= v[2] && v[2] <= 9;

    logic integer condition_holds(integer a, integer b, integer c) =
        (a == b && b != c) || (b == c && b != a) || (c == a && b != a) ? 1 : 0;
*/

/*@
    requires valid_vector(v);
    ensures \result == condition_holds(v[0], v[1], v[2]);
    assigns \nothing;
*/
bool func(int *v)
{
    bool ans = false;
    
    //@ assert valid_vector(v);
    
    if (v[0] == v[1] && v[1] != v[2]) {
        ans = true;
    }
    
    if (v[1] == v[2] && v[1] != v[0]) {
        ans = true;
    }
    
    if (v[2] == v[0] && v[1] != v[0]) {
        ans = true;
    }
    
    //@ assert ans == (condition_holds(v[0], v[1], v[2]) == 1);
    
    return ans;
}
