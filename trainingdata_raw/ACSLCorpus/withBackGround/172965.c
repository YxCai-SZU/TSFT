#include <stddef.h>

/*@
    predicate valid_input(integer n, integer m) =
        2 <= n && n <= 100 && 2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
            valid_input(n, m) ==>
            n - 1 >= 1 && n - 1 <= 99 &&
            m - 1 >= 1 && m - 1 <= 99 &&
            compute_result(n, m) <= 9801;
*/

/*@
    requires valid_input(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert n > 1 && n <= 100;
    //@ assert m > 1 && m <= 100;
    //@ assert n - 1 >= 1 && n - 1 <= 99;
    //@ assert m - 1 >= 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 9801;

    result = (n - 1) * (m - 1);
    //@ assert result == compute_result(n, m);
    return result;
}

int main()
{
    return 0;
}
