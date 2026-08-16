#include <stdbool.h>

/*@ predicate a_len_eq_2(int *a) = \valid(a) && \valid(a+1);
    predicate b_len_eq_2(int *b) = \valid(b) && \valid(b+1);
    predicate a0_in_range(int *a) = \valid(a) && 1 <= a[0] <= 10000;
    predicate a1_in_range(int *a) = \valid(a+1) && 1 <= a[1] <= 10000;
    predicate b0_in_range(int *b) = \valid(b) && 1 <= b[0] <= 10000;
    predicate b1_in_range(int *b) = \valid(b+1) && 1 <= b[1] <= 10000;
    predicate a_sorted(int *a) = \valid(a) && \valid(a+1) && a[0] <= a[1];
    predicate b_sorted(int *b) = \valid(b) && \valid(b+1) && b[0] <= b[1];
*/

/*@
    requires a_len_eq_2(a);
    requires b_len_eq_2(b);
    requires a0_in_range(a);
    requires a1_in_range(a);
    requires b0_in_range(b);
    requires b1_in_range(b);
    requires a_sorted(a);
    requires b_sorted(b);
    ensures \result == (a[1] >= b[0] && a[0] <= b[1]);
*/
bool func(int *a, int *b)
{
    //@ assert a_len_eq_2(a);
    //@ assert b_len_eq_2(b);
    //@ assert a0_in_range(a);
    //@ assert a1_in_range(a);
    //@ assert b0_in_range(b);
    //@ assert b1_in_range(b);
    //@ assert a_sorted(a);
    //@ assert b_sorted(b);
    
    return a[1] >= b[0] && a[0] <= b[1];
}
