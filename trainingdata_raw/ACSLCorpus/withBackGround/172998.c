#include <stdbool.h>

/*@
    predicate remainder_invariant(integer n, integer r) =
        0 <= r <= n &&
        r == n - 500 * ((n - r) / 500);

    lemma remainder_decreases:
        \forall integer n, r; 1 <= n <= 10000 && r >= 500 && remainder_invariant(n, r) ==>
            remainder_invariant(n, r - 500);
*/

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 - a <= 0);
*/
bool func(int n, int a)
{
    int remainder;
    remainder = n;

    /*@
        loop invariant remainder_invariant(n, remainder);
        loop assigns remainder;
    */
    while (remainder >= 500)
    {
        //@ assert remainder_invariant(n, remainder);
        remainder = remainder - 500;
    }

    //@ assert remainder == n % 500;
    
    if (remainder - a <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
