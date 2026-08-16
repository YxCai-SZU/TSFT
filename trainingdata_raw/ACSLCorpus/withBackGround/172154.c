#include <stdint.h>

/*@
    predicate valid_input(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;

    logic integer compute_result(integer n, integer r) =
        n < 10 ? r + 100 * (10 - n) : r;

    lemma no_underflow:
        \forall integer n; 1 <= n <= 100 ==> 10 - n >= -2147483648;

    lemma mult_bound:
        \forall integer n; 1 <= n <= 100 ==> 100 * (10 - n) <= 900;

    lemma add_bound:
        \forall integer n, r; 1 <= n <= 100 && 0 <= r <= 4111 ==> 
            r + 100 * (10 - n) <= 4111 + 900;
*/

/*@
    requires valid_input(n, r);
    ensures \result == compute_result(n, r);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t r)
{
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= r <= 4111;
    
    if (n < 10)
    {
        //@ assert 10 - n >= -2147483648;
        //@ assert 100 * (10 - n) <= 900;
        //@ assert r + 100 * (10 - n) <= 4111 + 900;
        result = r + 100 * (10 - n);
    }
    else
    {
        result = r;
    }
    
    //@ assert result == compute_result(n, r);
    return result;
}
