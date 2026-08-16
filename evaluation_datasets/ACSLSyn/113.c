#include <stdint.h>

/* Original first function (adapted with integer types for compatibility) */

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;

    logic integer remainder(integer x) = x % 100;
    logic integer quotient(integer x) = x / 100;
    logic integer calc_tmp(integer x) = remainder(x) * 21 + quotient(x) * 100;

    lemma remainder_bound: \forall integer x; is_valid_x(x) ==> 0 <= remainder(x) <= 99;
    lemma quotient_bound: \forall integer x; is_valid_x(x) ==> 0 <= quotient(x) <= 1000;
    lemma tmp_bound: \forall integer x; is_valid_x(x) ==> calc_tmp(x) <= 100 * 21 + 100000;
*/

int32_t func1(uint32_t x) {
    uint32_t n;
    uint32_t h;
    int32_t ans;
    uint32_t tmp;

    n = x % 100;
    h = x / 100;
    ans = 0;

    //@ assert n == remainder(x);
    //@ assert h == quotient(x);

    //@ assert n * 21 <= 100 * 21;
    //@ assert h * 100 <= 100000;
    //@ assert n * 21 + h * 100 <= 100 * 21 + 100000;

    tmp = n * 21 + h * 100;

    //@ assert tmp == calc_tmp(x);

    if (tmp <= x) {
        ans = 1;
        //@ assert tmp <= x;
    } else {
        //@ assert tmp > x;
    }

    return ans;
}

/* Original second function (adapted with integer types for compatibility) */

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;
    
    logic integer quotient_value(integer n) = n / 15;
    
    logic integer expected_result(integer n) = n * 800 - quotient_value(n) * 200;
*/

int64_t func2(int64_t n)
{
    int64_t quotient = 0;
    int64_t temp_n = n;
    
    while (temp_n >= 15)
    {
        temp_n -= 15;
        quotient += 1;
    }
    
    //@ assert n * 800 - 200 * quotient == expected_result(n);
    return n * 800 - 200 * quotient;
}

/* Synthesized function: Payment discount validator for a vending machine */
/* Scenario: In a vending machine, a customer inserts a payment amount x (1-100000 cents).
   The machine checks if the amount qualifies for a "combo discount" (func1 returns 1 if valid).
   If qualified, the customer can select up to n items (1-100), and the total cost is computed
   with a discount rule: every 15 items get a 200 cent discount (func2).
   The synthesized function validates that for a qualified payment, the final cost does not exceed
   the payment amount (ensuring the customer can afford the selected items).
*/

int32_t validate_purchase(uint32_t x, int64_t n)
{
    int32_t discount_valid;
    int64_t total_cost;

    discount_valid = func1(x);
    
    if (discount_valid == 1)
    {
        total_cost = func2(n);
        
        /*@ assert discount_valid == 1 ==> calc_tmp(x) <= x; */
        /*@ assert total_cost == expected_result(n); */
        
        if (total_cost <= x)
        {
            //@ assert expected_result(n) <= x;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
