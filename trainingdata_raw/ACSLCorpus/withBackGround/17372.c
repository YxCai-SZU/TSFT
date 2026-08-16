#include <stddef.h>

/*@
    predicate in_range(integer n) = 1 <= n <= 10000;

    logic integer compute_result(integer n) =
        (n / 500) * 1000 + ((n % 500) / 5) * 5;

    lemma c500_bound:
        \forall integer n; in_range(n) ==> (n / 500) * 1000 <= 10000 * 1000;

    lemma c5_bound:
        \forall integer n; in_range(n) ==> ((n % 500) / 5) * 5 <= 10000 * 5;

    lemma result_bound:
        \forall integer n; in_range(n) ==> 
            compute_result(n) <= 10000 * 1000 + 10000 * 5;
*/

/*@
    requires 1 <= n <= 10000;
    ensures \result == (n / 500) * 1000 + ((n % 500) / 5) * 5;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t c500 = n / 500;
    size_t r500 = n - (c500 * 500);
    size_t c5 = r500 / 5;
    size_t r5 = r500 - (c5 * 5);
    size_t res = c500 * 1000 + c5 * 5;

    //@ assert in_range(n);
    //@ assert c500 == n / 500;
    //@ assert r500 == n - (c500 * 500);
    //@ assert c5 == r500 / 5;
    //@ assert r5 == r500 - (c5 * 5);
    //@ assert res == compute_result(n);
    
    return res;
}
