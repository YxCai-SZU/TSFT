/*@
    predicate remainder_invariant(integer n, integer remainder) =
        0 <= remainder && remainder <= n &&
        n % 500 == remainder % 500;

    lemma remainder_decreases:
        \forall integer n, remainder;
        remainder >= 500 && remainder_invariant(n, remainder) ==>
        remainder_invariant(n, remainder - 500);
*/

#include <stdbool.h>

/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(int n, int a)
{
    int remainder = n;
    
    /*@
        loop invariant remainder_invariant(n, remainder);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500)
    {
        //@ assert remainder_invariant(n, remainder);
        remainder -= 500;
        //@ assert remainder_invariant(n, remainder);
    }
    
    //@ assert remainder == n % 500;
    //@ assert remainder <= a <==> (n % 500 <= a);
    return remainder <= a;
}
