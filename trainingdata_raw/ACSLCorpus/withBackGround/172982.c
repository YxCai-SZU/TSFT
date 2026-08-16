#include <stddef.h>

/*@
    predicate valid_params(integer N, integer X, integer T) =
        1 <= N <= 1000 &&
        1 <= X <= 1000 &&
        1 <= T <= 1000;

    logic integer possible_result_1(integer N, integer X, integer T) =
        (N / X + 1) * T;

    logic integer possible_result_2(integer N, integer X, integer T) =
        (N / X) * T;

    lemma division_bounds:
        \forall integer N, X;
        valid_params(N, X, 1) ==>
        N / X <= 1000;

    lemma division_plus_one_bounds:
        \forall integer N, X;
        valid_params(N, X, 1) ==>
        N / X + 1 <= 1001;

    lemma product_bounds_1:
        \forall integer N, X, T;
        valid_params(N, X, T) ==>
        (N / X) * T <= 1000 * 1000;

    lemma product_bounds_2:
        \forall integer N, X, T;
        valid_params(N, X, T) ==>
        (N / X + 1) * T <= 1001 * 1000;
*/

/*@
    requires valid_params(N, X, T);
    ensures \result == possible_result_1(N, X, T) ||
            \result == possible_result_2(N, X, T);
    assigns \nothing;
*/
size_t func(size_t N, size_t X, size_t T)
{
    // Variable declarations at scope top
    size_t ans;

    //@ assert N <= 1000;
    //@ assert X >= 1 && X <= 1000;
    //@ assert T <= 1000;
    //@ assert N / X <= 1000;
    //@ assert (N / X + 1) <= 1001;
    //@ assert N / X * T <= 1000 * 1000;
    //@ assert (N / X + 1) * T <= 1001 * 1000;

    if (N % X == 0) {
        ans = (N / X) * T;
    } else {
        ans = (N / X + 1) * T;
    }

    return ans;
}
