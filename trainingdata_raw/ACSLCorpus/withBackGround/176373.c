#include <stdbool.h>

/*@ predicate a_len_eq_2(int *a) = \valid(a) && \valid(a+1);
    predicate b_len_eq_2(int *b) = \valid(b) && \valid(b+1);
    predicate a0_in_range(int *a) = \valid(a) && 1 <= a[0] <= 100;
    predicate a1_in_range(int *a) = \valid(a+1) && 1 <= a[1] <= 100;
    predicate b0_in_range(int *b) = \valid(b) && 1 <= b[0] <= 100;
    predicate b1_in_range(int *b) = \valid(b+1) && 1 <= b[1] <= 100;
*/

/*@
    requires a_len_eq_2(a) && b_len_eq_2(b);
    requires a0_in_range(a) && a1_in_range(a);
    requires b0_in_range(b) && b1_in_range(b);
    ensures \result == (a[1] >= b[0] && b[1] >= a[0]);
*/
bool func(int *a, int *b)
{
    bool result;
    
    //@ assert a_len_eq_2(a) && b_len_eq_2(b);
    //@ assert a0_in_range(a) && a1_in_range(a);
    //@ assert b0_in_range(b) && b1_in_range(b);
    
    if (a[1] >= b[0] && b[1] >= a[0])
    {
        result = true;
        //@ assert result == (a[1] >= b[0] && b[1] >= a[0]);
    }
    else
    {
        //@ assert a[1] < b[0] || b[1] < a[0];
        result = false;
        //@ assert result == (a[1] >= b[0] && b[1] >= a[0]);
    }
    
    return result;
}
