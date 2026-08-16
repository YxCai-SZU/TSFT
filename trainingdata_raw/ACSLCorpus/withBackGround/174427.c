#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;

    logic integer target_value(integer a, integer p) = (a * 3 + p) / 2;

    lemma target_non_negative:
        \forall integer a, p; is_valid_params(a, p) ==> target_value(a, p) >= 0;
*/

/*@
    requires is_valid_params(a, p);
    ensures \result == target_value(a, p);
    ensures \result >= 0;
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t sum;
    int64_t result;
    int64_t abs_sum;
    int64_t divisor;
    
    //@ assert is_valid_params(a, p);
    
    sum = a * 3 + p;
    result = 0;
    abs_sum = (sum < 0) ? -sum : sum;
    divisor = 2;
    
    /*@
        loop invariant 0 <= abs_sum <= a * 3 + p;
        loop invariant result == ((a * 3 + p) - abs_sum) / 2;
        loop invariant abs_sum + 2 * result == a * 3 + p;
        loop invariant abs_sum % 2 == (a * 3 + p) % 2;
        loop invariant is_valid_params(a, p);
        loop invariant result >= 0;
        loop assigns abs_sum, result;
        loop variant abs_sum;
    */
    while (abs_sum >= divisor)
    {
        //@ assert abs_sum >= 2;
        abs_sum -= divisor;
        result += 1;
        //@ assert result >= 0;
    }
    
    if (sum < 0)
    {
        result = -result;
    }
    
    //@ assert result == target_value(a, p);
    //@ assert result >= 0;
    
    return result;
}
