#include <limits.h>
#include <stddef.h>
#include <stdbool.h>

/* ==================== Original Functions (Unchanged) ==================== */

/* --- Function 1: Rounding to nearest integer (half-up) --- */
/*@
    predicate is_valid_input(integer x) = 1 <= x <= 10000;
    
    logic integer half(integer x) = x / 2;
    logic integer remainder(integer x) = x % 2;
    
    logic integer expected_result(integer x) = half(x) + remainder(x);
*/

int func_round(int x)
{
    int quotient;
    int remainder;
    int divisor;
    
    //@ assert is_valid_input(x);
    
    quotient = 0;
    remainder = (x < 0) ? -x : x;
    divisor = 2;
    
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (x < 0)
    {
        quotient = -quotient;
    }
    
    //@ assert quotient == half(x);
    //@ assert remainder == remainder(x);
    
    if (x < 0 && remainder != 0)
    {
        return quotient - 1;
    }
    else if (remainder != 0)
    {
        return quotient + 1;
    }
    else
    {
        return quotient;
    }
}

/* --- Function 2: Find smallest missing positive integer (like first missing positive) --- */
/*@
    predicate valid_array(int *arr, size_t len) =
        len >= 1 && len <= 200000 &&
        \forall size_t i; 0 <= i < len ==> 1 <= arr[i] <= 1000000;

    predicate func_result(integer h, integer len) =
        h >= 0 && h <= len;
*/

size_t func_missing(int *a, size_t n) {
    size_t h = 0;
    size_t index = 0;
    
    while (index < n) {
        int ai = a[index];
        //@ assert 1 <= ai <= 1000000;
        
        if (h == (size_t)ai) {
            h = h + 1;
        }
        index = index + 1;
    }
    //@ assert h <= n;
    return h;
}

/* --- Function 3: Compute change to next multiple of 1000 --- */
/*@
    predicate is_multiple_of_1000(integer n) = n % 1000 == 0;
    predicate not_multiple_of_1000(integer n) = n % 1000 != 0;
    logic integer compute_change(integer n) = 
        (n % 1000 == 0) ? 0 : 1000 - (n % 1000);
    
    lemma change_bound: \forall integer n; 1 <= n <= 1000000 ==> compute_change(n) <= 1000;
    lemma change_correct: \forall integer n; 1 <= n <= 1000000 ==> 
        ((n % 1000 == 0) ==> compute_change(n) == 0) && 
        ((n % 1000 != 0) ==> compute_change(n) == 1000 - (n % 1000));
*/

unsigned int func_change(unsigned int n)
{
    unsigned int change;
    unsigned int temp;
    
    temp = n % 1000;
    
    if (temp == 0)
    {
        //@ assert temp == 0;
        change = 0;
    }
    else
    {
        //@ assert temp != 0;
        change = 1000 - temp;
    }
    
    return change;
}

/* ==================== Synthesized Function ==================== */

/* 
 * Scenario: A real-world "price rounding and adjustment" system for a vending machine.
 * 
 * Data flow:
 * 1. Take a base price (1-10000) and round it to nearest integer using func_round.
 * 2. Take the rounded price and use it to query a "premium adjustment" from a 
 *    lookup table (simulated by func_missing, which returns the smallest missing 
 *    positive integer in the array). This represents a special offer index.
 * 3. Use the premium adjustment index to compute the change needed to make the 
 *    final price a multiple of 1000 cents (i.e., a round dollar amount).
 * 
 * The final output is the total adjustment (change) needed.
 */

/*@
    predicate valid_price_adjustment(integer base_price, int *table, size_t table_len, unsigned int result) =
        1 <= base_price <= 10000 &&
        valid_array(table, table_len) &&
        result <= 1000;
*/

unsigned int compute_total_adjustment(int base_price, int *offer_table, size_t table_len)
{
    int rounded_price;
    size_t premium_index;
    unsigned int total_change;
    
    //@ assert is_valid_input(base_price);
    rounded_price = func_round(base_price);
    
    //@ assert valid_array(offer_table, table_len);
    premium_index = func_missing(offer_table, table_len);
    
    unsigned int mapped_price;
    if (premium_index == 0) {
        mapped_price = 1;  // avoid zero, map to 1
    } else {
        mapped_price = (unsigned int)(premium_index % 1000000) + 1;
    }
    
    //@ assert 1 <= mapped_price <= 1000000;
    total_change = func_change(mapped_price);
    
    //@ assert total_change <= 1000;
    //@ assert valid_price_adjustment(base_price, offer_table, table_len, total_change);
    
    return total_change;
}
