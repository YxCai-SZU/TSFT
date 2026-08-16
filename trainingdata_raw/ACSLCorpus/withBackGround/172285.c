#include <stdbool.h>

/*@ predicate a_valid(int *a) = \valid(a) && \valid(a+1) && \valid(a+2);
    predicate b_valid(int *b) = \valid(b) && \valid(b+1) && \valid(b+2);
    predicate arrays_equal(int *a, int *b) = a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
*/

/*@ requires a_valid(a);
    requires b_valid(b);
    ensures \result == true <==> arrays_equal(a, b);
    assigns \nothing;
*/
bool func(int *a, int *b)
{
    //@ assert a_valid(a);
    //@ assert b_valid(b);
    
    if (a[0] != b[0] || a[1] != b[1] || a[2] != b[2]) {
        return false;
    } else {
        return true;
    }
}

/*@ requires a_valid(a);
    requires b_valid(b);
    ensures \result == true <==> arrays_equal(a, b);
    assigns \nothing;
*/
bool another_func(int *a, int *b)
{
    //@ assert a_valid(a);
    //@ assert b_valid(b);
    
    if (a[0] != b[0] || a[1] != b[1] || a[2] != b[2]) {
        return false;
    } else {
        return true;
    }
}
