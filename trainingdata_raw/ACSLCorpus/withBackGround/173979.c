#include <limits.h>

/*@
    predicate is_valid_input(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;

    logic integer calculate_min_val(integer n) =
        n < 10 ? 100 * (10 - n) : 0;

    logic integer calculate_result(integer n, integer r) =
        r + calculate_min_val(n);

    lemma min_val_bounds:
        \forall integer n;
        1 <= n <= 100 ==>
        0 <= calculate_min_val(n) <= 1000;

    lemma result_bounds:
        \forall integer n, integer r;
        is_valid_input(n, r) ==>
        0 <= calculate_result(n, r) <= 5111;

    lemma result_property:
        \forall integer n, integer r;
        is_valid_input(n, r) ==>
        (n >= 10 ==> calculate_result(n, r) == r) &&
        (n < 10 ==> calculate_result(n, r) == r + 100 * (10 - n));
*/

/*@
    requires is_valid_input(n, r);
    ensures \result == calculate_result(n, r);
    ensures (n >= 10 ==> \result == r);
    ensures (n < 10 ==> \result == r + 100 * (10 - n));
    ensures 0 <= \result <= 5111;
*/
int func(int n, int r)
{
    int min_val;
    int ans;

    //@ assert is_valid_input(n, r);
    
    if (n < 10) {
        min_val = 100 * (10 - n);
    } else {
        min_val = 0;
    }

    //@ assert min_val == calculate_min_val(n);
    //@ assert 0 <= min_val <= 1000;

    ans = r + min_val;

    //@ assert ans == calculate_result(n, r);
    //@ assert 0 <= ans <= 5111;

    return ans;
}
