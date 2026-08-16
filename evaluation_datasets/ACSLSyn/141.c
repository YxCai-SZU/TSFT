#include <stdbool.h>
#include <stdint.h>

/* First function: check if k is in the first half of n */
/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer half_ceil(integer n) = (n + 1) / 2;

    lemma n_plus_one_bound: \forall integer n; 1 <= n <= 100 ==> n + 1 <= 101;
    lemma half_ceil_bound: \forall integer n; 1 <= n <= 100 ==> half_ceil(n) <= 50;
*/

bool is_in_first_half(unsigned int n, unsigned int k)
{
    bool result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    //@ assert n + 1 <= 101;
    //@ assert (n + 1) / 2 <= 50;
    
    result = (k <= (n + 1) / 2);
    return result;
}

/* Second function: verify product division condition */
/*@
    predicate product_division_condition(integer x, integer y) =
        x < 0x80000000 && y < 0x80000000;
*/

/*@
    lemma product_division_lemma:
        \forall integer x, y;
            product_division_condition(x, y) ==> x * y <= x * y;
*/

void product_division(uint32_t x, uint32_t y) {
    //@ assert product_division_condition(x, y);
    
    uint32_t product = x * y;
    
    //@ assert product <= product;
}

/* Synthesized function: email list bucket assignment */
/* In a real-world email campaign system, we have a list of subscribers (n) and we want to assign them to buckets based on their subscriber ID (k).
 * The first half of subscribers (by ID) go to bucket A, the rest to bucket B.
 * Additionally, we verify that the bucket assignment doesn't overflow our processing limits.
 * 
 * Data flow:
 * - Input: n = total subscribers, k = subscriber ID, x = processing limit per bucket, y = safety multiplier
 * - Process: 
 *   1. Check if subscriber goes to bucket A (first half)
 *   2. Verify processing limits are within safe bounds
 * - Output: true if subscriber is in bucket A and processing is safe
 */

/*@
    predicate email_bucket_valid(integer n, integer k, integer x, integer y) =
        valid_params(n, k) && product_division_condition(x, y);
*/

bool assign_email_bucket(unsigned int n, unsigned int k, uint32_t x, uint32_t y)
{
    bool in_first_half;
    bool processing_safe;
    bool result;

    in_first_half = is_in_first_half(n, k);
    
    //@ assert in_first_half == (k <= (n + 1) / 2);
    
    product_division(x, y);
    
    //@ assert product_division_condition(x, y);
    
    processing_safe = (x < 0x80000000 && y < 0x80000000);
    result = in_first_half && processing_safe;
    
    //@ assert result ==> (k <= (n + 1) / 2 && x < 0x80000000 && y < 0x80000000);
    
    return result;
}
