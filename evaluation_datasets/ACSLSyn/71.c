#include <stdint.h>
#include <stdbool.h>

/* 
 * Scenario: A network packet validator that checks if a packet's payload size 
 * fits within allowed limits after accounting for header overhead and alignment.
 * 
 * Data flow:
 * 1. func() computes maximum usable payload size after subtracting overhead and alignment gaps
 * 2. verify_zero_div() verifies the alignment unit is valid (non-zero)
 * 3. func2() checks if the actual payload size fits within the computed bounds
 */

/*@
    predicate valid_params(integer n, integer k) =
        2 <= k && k <= n && n <= 1000000000;
*/

/*@
    logic integer func_spec(integer n, integer k) =
        n <= k ? n - 1 : (n - 1) - (k - 1);
*/

/*@
    lemma func_lemma:
        \forall integer n, integer k;
        valid_params(n, k) ==>
        func_spec(n, k) <= n - 1 &&
        (func_spec(n, k) == n - 1 || (n - 1 - func_spec(n, k)) >= (k - 1));
*/

uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t result;
    uint64_t x;
    uint64_t y;
    uint64_t ans;
    
    if (n <= k) {
        result = n - 1;
        //@ assert result == n - 1;
        return result;
    } else {
        x = n - 1;
        y = k - 1;
        
        //@ assert x >= y;
        //@ assert x - y <= n - 1;
        
        ans = (x > y) ? (x - y) : 0;
        result = ans;
        
        //@ assert result == func_spec(n, k);
        return result;
    }
}

int verify_zero_div(unsigned int x) {
    //@ assert x > 0;
    int result = x / x;
    //@ assert result == 1;
    return result;
}

/*@ predicate bounds_a(integer a) = 1 <= a <= 100;
    predicate bounds_b(integer b) = 1 <= b <= 100;
    predicate bounds_c(integer c) = 1 <= c <= 200;
    predicate sum_bounds(integer a, integer b) = a + b <= 200;
 */

/*@ lemma sum_bounds_lemma: 
        \forall integer a, b; bounds_a(a) && bounds_b(b) ==> sum_bounds(a, b);
 */

bool func2(const int *v)
{
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert bounds_a(a);
    //@ assert bounds_b(b);
    //@ assert bounds_c(c);
    //@ assert sum_bounds(a, b);

    result = (a <= c && c <= a + b);
    return result;
}

int packet_validator(uint64_t total_size, uint64_t alignment, const int *v)
{
    uint64_t max_payload = func(total_size, alignment);
    
    int align_check = verify_zero_div((unsigned int)alignment);
    
    bool fits = func2(v);
    
    //@ assert max_payload <= total_size - 1;
    //@ assert align_check == 1;
    
    int result;
    if (fits && (uint64_t)v[2] <= max_payload) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == 1 ==> (v[0] <= v[2] && v[2] <= v[0] + v[1] && (uint64_t)v[2] <= max_payload);
    
    return result;
}
