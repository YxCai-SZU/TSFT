/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;

    predicate loop_invariant(integer i, integer m, integer current, integer n) =
        0 <= i <= m && current <= n && current == n - i;

    logic integer subtraction(integer a, integer b) = a - b;

    lemma final_value: \forall integer n, m, i, current;
        loop_invariant(i, m, current, n) && i == m ==> current == n - m;
*/

#include <stdbool.h>

/*@
    requires is_valid_params(n, m);
    ensures \result == (n == m);
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int i = 0;
    unsigned int current = n;

    /*@
        loop invariant loop_invariant(i, m, current, n);
        loop assigns i, current;
    */
    while (i < m)
    {
        //@ assert current == n - i;
        current -= 1;
        i += 1;
        //@ assert current == n - i;
    }

    //@ assert current == n - m;
    return current == 0;
}
