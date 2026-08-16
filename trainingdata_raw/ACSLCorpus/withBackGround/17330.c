#include <stdbool.h>

/*@
    predicate sorted(int *v, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> v[i] < v[j];

    predicate in_range(int *v, integer len, integer low, integer high) =
        \forall integer i; 0 <= i < len ==> low <= v[i] <= high;

    predicate all_pairs_within_k(int *v, integer len, integer k) =
        \forall integer i, j; 0 <= i < j < len ==> v[j] - v[i] <= k;
*/

/*@
    requires \valid(v + (0..4));
    requires in_range(v, 5, 0, 123);
    requires sorted(v, 5);
    requires 0 <= k <= 123;
    ensures \result == true <==> all_pairs_within_k(v, 5, k);
*/
bool func(int *v, int k)
{
    int i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer x, y; 0 <= x < y < i ==> v[y] - v[x] <= k;
        loop invariant in_range(v, 5, 0, 123);
        loop invariant sorted(v, 5);
        loop invariant 0 <= k <= 123;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        int d = v[i] - v[0];
        int abs_d = (d < 0) ? -d : d;
        //@ assert abs_d == (d >= 0 ? d : -d);
        if (abs_d > k)
        {
            return false;
        }
        i++;
    }
    return true;
}
