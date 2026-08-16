#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
            valid_params(n, m) ==>
            (n - 1) >= 1 && (m - 1) >= 1 &&
            (n - 1) <= 99 && (m - 1) <= 99;

    lemma overflow_lemma:
        \forall integer n, m;
            valid_params(n, m) ==>
            (n - 1) * (m - 1) <= 99 * 99;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert n > 1 && m > 1;
    //@ assert (n - 1) >= 1 && (m - 1) >= 1;
    //@ assert (n - 1) <= 99 && (m - 1) <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    return result;
}

/*@
    assigns \nothing;
    ensures \true;
*/
int32_t read_vec(void)
{
    // Variable declarations at top of scope
    int32_t a = 0;
    int32_t b = 0;
    
    return a;
}

int main(void)
{
    return 0;
}
