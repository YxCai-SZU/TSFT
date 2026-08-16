#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/* ====== Original function 1: Check if a three-digit number contains digit 7 ====== */

/*@
    predicate has_seven_in_hundreds(integer n) = (n / 100) == 7;
    predicate has_seven_in_tens(integer n) = ((n / 10) % 10) == 7;
    predicate has_seven_in_ones(integer n) = (n % 10) == 7;
    predicate has_seven_anywhere(integer n) = 
        has_seven_in_hundreds(n) || has_seven_in_tens(n) || has_seven_in_ones(n);
*/

bool func_has_seven(int n)
{
    int num = n;
    bool ok = false;
    int first_digit;
    int second_digit;
    int third_digit;
    
    first_digit = num / 100;
    
    if (first_digit == 7) {
        ok = true;
    }
    
    if (!ok) {
        second_digit = num / 10 % 10;
        if (second_digit == 7) {
            ok = true;
        }
    }
    
    if (!ok) {
        third_digit = num % 10;
        if (third_digit == 7) {
            ok = true;
        }
    }
    
    //@ assert ok == true <==> has_seven_anywhere(n);
    
    return ok;
}

/* ====== Original function 2: Simple test functions (adapted into a validation helper) ====== */

/*@
    predicate test_bool(integer a) = a == 0;
    lemma test_bool_proof: \forall integer a; test_bool(a) ==> a == 0;
*/

void test_int() {
    int x = 0;
    //@ assert 0 * x == 0;
}

void test_boolproof(int a) {
    //@ assert test_bool(a);
}

/* ====== Original function 3: Compute n*800 - (n/15)*200 for 1 <= n <= 100 ====== */

/*@
    predicate is_valid_n_small(integer n) = 1 <= n && n <= 100;

    logic integer quotient_logic(integer n) = n / 15;
    logic integer remainder_logic(integer n) = n % 15;

    logic integer expected_result_small(integer n) = n * 800 - (n / 15) * 200;

    lemma division_property:
        \forall integer n;
            is_valid_n_small(n) ==> n == 15 * (n / 15) + (n % 15) && 0 <= (n % 15) && (n % 15) < 15;
*/

int64_t func_compute_small(uint64_t n)
{
    uint64_t x;
    uint64_t quotient = 0;
    uint64_t remainder = n;
    uint64_t y;
    uint64_t ans;
    int64_t signed_ans;

    //@ assert is_valid_n_small(n);
    x = n * 800;

    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        quotient += 1;
        remainder -= 15;
        //@ assert remainder + 15 * quotient == n;
    }

    //@ assert quotient == n / 15;
    //@ assert remainder == n % 15;

    y = quotient * 200;
    ans = x - y;

    //@ assert ans == n * 800 - (n / 15) * 200;

    if (ans <= INT64_MAX)
    {
        signed_ans = (int64_t)ans;
    }
    else
    {
        signed_ans = INT64_MAX;
    }

    //@ assert signed_ans == expected_result_small(n);
    return signed_ans;
}

/* ====== Original function 4: Compute (1000 - n % 1000) % 1000 for 1 <= n <= 10000 ====== */

/*@
    predicate is_valid_n_medium(integer n) = 1 <= n && n <= 10000;

    logic integer compute_result(integer n) =
        (1000 - n % 1000) % 1000;

    lemma result_less_than_1000:
        \forall integer n; is_valid_n_medium(n) ==> compute_result(n) < 1000;
*/

uint32_t func_compute_mod(uint32_t n)
{
    uint32_t result;
    
    //@ assert is_valid_n_medium(n);
    result = (1000 - n % 1000) % 1000;
    //@ assert result == compute_result(n);
    //@ assert result < 1000;
    
    return result;
}

/* ====== Synthesized complex function: Process order discount with lucky number check ====== */

/* 
   Scenario: E-commerce order processing system.
   - Input: order_id (1-100), customer_id (100-999), product_code (1-10000)
   - Step 1: Check if customer_id contains digit 7 (lucky customer) -> if true, apply special discount
   - Step 2: Validate test infrastructure (not relevant to core logic, but part of system)
   - Step 3: Compute base price adjustment: n*800 - (n/15)*200 (for order quantity n)
   - Step 4: Compute modulo rounding for final price: (1000 - product_code % 1000) % 1000
   - Output: Final adjusted price (int64_t)
   
   High-level property: When customer is lucky (has digit 7), the final price is always non-negative.
*/

int64_t process_order(uint64_t order_qty, int customer_id, uint32_t product_code)
{
    bool is_lucky;
    int64_t base_price;
    uint32_t rounding;
    int64_t final_price;
    
    is_lucky = func_has_seven(customer_id);
    //@ assert is_lucky == true <==> has_seven_anywhere(customer_id);
    
    test_int();
    if (is_lucky) {
        test_boolproof(0);
    }
    
    base_price = func_compute_small(order_qty);
    //@ assert base_price == expected_result_small(order_qty);
    
    rounding = func_compute_mod(product_code);
    //@ assert rounding < 1000;
    //@ assert rounding == compute_result(product_code);
    
    if (is_lucky) {
        final_price = base_price + (int64_t)rounding;
    } else {
        final_price = base_price;
    }
    
    //@ assert (is_lucky == true) ==> (final_price >= 0);
    
    return final_price;
}
