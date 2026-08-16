#include <stdbool.h>

/*@
    predicate in_range(integer n, integer m, integer k) =
        1 <= n <= 1000 &&
        1 <= m <= 1000 &&
        0 <= k <= n * m;

    logic integer product(integer n, integer m) = n * m;

    lemma product_bound: \forall integer n, m;
        1 <= n <= 1000 && 1 <= m <= 1000 ==> product(n, m) <= 1000000;
*/

/*@
    requires in_range(n, m, k);
    ensures \result == true <==> (n * m - k) % 2 == 0;
    assigns \nothing;
*/
bool func(int n, int m, int k)
{
    // Variable declarations at top of scope
    int nm;
    int diff;
    bool is_even;
    int temp_diff;

    // Precondition assertions
    //@ assert 1 <= n <= 1000;
    //@ assert 1 <= m <= 1000;
    //@ assert 0 <= k <= n * m;

    // Ensure no overflow
    //@ assert n * m <= 1000 * 1000;

    nm = n * m;
    diff = nm - k;
    is_even = true;
    temp_diff = diff;

    /*@
        loop invariant 0 <= temp_diff <= n * m;
        loop invariant temp_diff % 2 == diff % 2;
        loop assigns temp_diff;
    */
    while (temp_diff > 1)
    {
        temp_diff -= 2;
    }

    if (temp_diff != 0)
    {
        is_even = false;
    }

    // Postcondition verification
    //@ assert is_even == true <==> (n * m - k) % 2 == 0;
    return is_even;
}
