#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer compute_n(integer x) = x / 100;
    logic integer compute_m(integer x) = x % 100;

    lemma n_bound: \forall integer x; is_valid_range(x) ==> compute_n(x) <= 1000;
    lemma m_bound: \forall integer x; is_valid_range(x) ==> compute_m(x) <= 99;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x / 100 * 100 <= x && x % 100 <= 5 * (x / 100));
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int m;
    bool result;

    //@ assert is_valid_range(x);
    n = x / 100;
    m = x % 100;

    //@ assert n <= 1000;
    //@ assert m <= 99;

    result = (n * 100 + m <= x) && (m <= 5 * n);
    return result;
}
