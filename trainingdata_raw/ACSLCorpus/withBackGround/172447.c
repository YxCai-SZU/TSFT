#include <stdbool.h>

/*@
    predicate valid_range(integer a) =
        1 <= a && a <= 100;

    predicate vector_valid(int *v) =
        \valid(v) && \valid(v+1) &&
        valid_range(v[0]) && valid_range(v[1]);

    predicate is_greater(int *v) =
        v[0] > v[1];
*/

/*@
    requires vector_valid(v);
    ensures \result == true <==> is_greater(v);
    assigns \nothing;
*/
bool func(int *v)
{
    //@ assert vector_valid(v);
    
    if (v[0] > v[1]) {
        //@ assert is_greater(v);
        return true;
    } else {
        //@ assert !is_greater(v);
        return false;
    }
}
