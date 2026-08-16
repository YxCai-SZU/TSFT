#include <stdbool.h>

/*@ predicate N_in_range(integer n) = 1 <= n && n <= 100; */
/*@ predicate Ndash_in_range(integer nd) = 0 <= nd && nd <= 4111; */
/*@ logic integer total_value(integer n, integer nd) = n * 100 + nd; */

/*@
    requires N_in_range(N);
    requires Ndash_in_range(Ndash);
    ensures \result == (total_value(N, Ndash) <= 5000);
    assigns \nothing;
*/
bool func(int N, int Ndash)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= N && N <= 100;
    //@ assert 0 <= Ndash && Ndash <= 4111;
    //@ assert N * 100 <= 10000;
    //@ assert N * 100 + Ndash <= 15111;

    if (N * 100 + Ndash <= 5000) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
