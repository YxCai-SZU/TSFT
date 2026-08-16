#include <stdint.h>

/*@
    predicate white_in_range(integer n, integer white) =
        0 <= white <= n * n;

    predicate n_in_range(integer n) =
        1 <= n <= 100;

    logic integer total_squares(integer n) = n * n;

    logic integer black_squares(integer n, integer white) =
        total_squares(n) - white;

    lemma white_non_negative:
        \forall integer n, white; n_in_range(n) && white_in_range(n, white) ==> white >= 0;

    lemma white_upper_bound:
        \forall integer n, white; n_in_range(n) && white_in_range(n, white) ==> white <= total_squares(n);

    lemma total_squares_bound:
        \forall integer n; n_in_range(n) ==> total_squares(n) <= 100 * 100;

    lemma black_non_negative:
        \forall integer n, white; n_in_range(n) && white_in_range(n, white) ==> black_squares(n, white) >= 0;

    lemma black_upper_bound:
        \forall integer n, white; n_in_range(n) && white_in_range(n, white) ==> black_squares(n, white) <= total_squares(n);
*/

/*@
    requires n_in_range(n);
    requires white_in_range(n, white);
    ensures \result == black_squares(n, white);
    ensures 0 <= \result <= total_squares(n);
*/
int32_t func(int32_t n, int32_t white)
{
    int32_t ans;

    //@ assert white >= 0;
    //@ assert white <= n * n;
    //@ assert n * n <= 100 * 100;
    //@ assert (n * n) - white >= 0;

    ans = (n * n) - white;

    //@ assert ans >= 0 && ans <= n * n;

    return ans;
}
