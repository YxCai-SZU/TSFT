#include <stdbool.h>

/*@
    predicate is_sorted(int *a, integer len) =
        \forall integer i; 0 <= i < len-1 ==> a[i] < a[i+1];

    predicate in_range(int *a, integer len) =
        \forall integer i; 0 <= i < len ==> 0 <= a[i] <= 123;

    logic integer diff(int *a) = a[4] - a[0];
*/

/*@
    requires \valid(a+(0..4));
    requires in_range(a, 5);
    requires is_sorted(a, 5);
    requires 0 <= k <= 123;
    ensures \result == (diff(a) <= k);
    assigns \nothing;
*/
bool func(int *a, int k)
{
    int last;
    int first;
    int diff_val;

    // Declare all variables at the top
    last = a[4];
    first = a[0];

    //@ assert last >= first;
    //@ assert last - first <= 123;
    diff_val = last - first;

    //@ assert diff_val == diff(a);
    return diff_val <= k;
}
