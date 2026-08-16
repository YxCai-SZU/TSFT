#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer square(integer n) = n * n;
    lemma square_bound: \forall integer n; is_valid_n(n) ==> square(n) <= 10000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    assigns \nothing;
*/
int func(int n)
{
    //@ assert is_valid_n(n);
    //@ assert square(n) <= 10000;
    return n * n;
}
