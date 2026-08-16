#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n && n <= 10000 &&
        0 <= a && a <= 1000;

    logic integer remainder(integer n) = n % 500;

    lemma remainder_bounds: \forall integer n; 0 <= n ==> 0 <= remainder(n) < 500;
*/

/*@
    requires valid_params(n, a);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned long n, unsigned long a)
{
    // Variable declarations at scope top
    unsigned long pay = n;

    /*@
        loop invariant 0 <= pay <= n;
        loop invariant remainder(n) == remainder(pay);
        loop assigns pay;
        loop variant pay;
    */
    while (pay >= 500)
    {
        //@ assert pay >= 500;
        pay -= 500;
    }

    //@ assert pay == remainder(n);
    return pay <= a;
}
