#include <stdbool.h>

/*@ predicate is_valid_vector(int *v, integer len) =
    len == 2 &&
    1 <= v[0] <= 100 &&
    1 <= v[1] <= 100;
*/

/*@
    requires \valid(v) && \valid(v+1);
    requires is_valid_vector(v, 2);
    ensures \result == true <==> v[0] > v[1];
    assigns \nothing;
*/
bool func(int *v) {
    int a;
    int b;
    
    a = v[0];
    b = v[1];
    
    if (a > b) {
        //@ assert a > b;
        return true;
    } else {
        //@ assert !(a > b);
        return false;
    }
}
