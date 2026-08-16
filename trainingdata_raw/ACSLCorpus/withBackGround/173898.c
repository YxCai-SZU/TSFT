#include <stdbool.h>

/*@
    predicate in_range(integer v, integer low, integer high) =
        low <= v && v <= high;

    lemma subtraction_bounds:
        \forall integer a, b;
            in_range(a, -1000000000, 1000000000) &&
            in_range(b, -1000000000, 1000000000) ==>
            in_range(a - b, -2000000000, 2000000000);
*/

/*@
    requires in_range(a, -1000000000, 1000000000);
    requires in_range(b, -1000000000, 1000000000);
    requires in_range(c, -1000000000, 1000000000);
    requires in_range(k, 0, 100000000000000000);
    ensures \result == a - b || \result == b - a;
    ensures in_range(\result, -2000000000, 2000000000);
*/
int func(int a, int b, int c, long long k)
{
    bool is_even = true;
    long long temp_k = k;
    
    /*@
        loop invariant in_range(temp_k, 0, k);
        loop invariant in_range(a, -1000000000, 1000000000);
        loop invariant in_range(b, -1000000000, 1000000000);
        loop invariant in_range(c, -1000000000, 1000000000);
        loop invariant in_range(k, 0, 100000000000000000);
        loop assigns is_even, temp_k;
    */
    while (temp_k > 0)
    {
        if (temp_k == 1)
        {
            is_even = false;
            break;
        }
        temp_k -= 2;
    }

    if (is_even)
    {
        //@ assert in_range(a - b, -2000000000, 2000000000);
        return a - b;
    }
    else
    {
        //@ assert in_range(b - a, -2000000000, 2000000000);
        return b - a;
    }
}
