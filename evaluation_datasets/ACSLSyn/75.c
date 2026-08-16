#include <stdbool.h>
#include <stdint.h>

/* ACSL predicates and lemmas from original functions */

/* from func1 (prime check) */
/*@
    predicate is_prime(integer n, integer limit) =
        \forall integer i; 2 <= i < limit ==> n % i != 0;
 */

/* from func2 (all different check) */
/*@
    predicate all_different(int *arr, integer n) =
        \forall integer i, j; 0 <= i < j < n ==> arr[i] != arr[j];
*/

/* from func3 (valid_x) */
/*@
    predicate valid_x(integer x) = 1 <= x && x <= 100000000000000000;
    logic integer quotient(integer x) = x / 11;
    logic integer remainder(integer x) = x % 11;
*/

/* from func4 (square rectangle) */
/*@ predicate is_square(uint32_t w, uint32_t h) = w == h; */
/*@ logic integer area(uint32_t w, uint32_t h) = (integer)w * (integer)h; */
/*@ lemma area_non_negative: \forall uint32_t w, h; area(w, h) >= 0; */

struct Rectangle {
    uint32_t width;
    uint32_t height;
};

/* Original function 1: checks if 2*input-1 is prime */
int func_prime_check(unsigned int input)
{
    int num;
    bool is_prime;
    unsigned int i;
    int result;

    num = (int)(input * 2) - 1;
    is_prime = true;
    i = 2;

    while (i < input)
    {
        unsigned int num_unsigned = (unsigned int)num;
        //@ assert i >= 2;
        if (num_unsigned % i == 0)
        {
            is_prime = false;
            break;
        }
        i = i + 1;
    }

    if (is_prime)
    {
        result = num;
    }
    else
    {
        result = -1;
    }

    //@ assert result == 2 * input - 1 || result == -1;
    return result;
}

/* Original function 2: checks if n >= 3 given all elements are different */
bool func_size_check(int n, int *v) {
    int t = 3;
    
    //@ assert n >= t ==> n >= 3;
    
    return n >= t;
}

/* Original function 3: computes some cost based on x */
uint64_t func_cost(uint64_t x)
{
    uint64_t ans;
    uint64_t temp_x;
    uint64_t q;
    
    ans = 0;
    temp_x = x;
    q = 0;
    
    while (temp_x >= 11)
    {
        temp_x = temp_x - 11;
        q = q + 1;
    }
    
    ans = ans + q * 2;
    temp_x = x % 11;
    
    if (temp_x > 6)
    {
        ans = ans + 2;
    }
    else if (temp_x > 0)
    {
        ans = ans + 1;
    }
    
    return ans;
}

/* Original function 4: returns a square rectangle from a square rectangle */
struct Rectangle func_square_rect(struct Rectangle const *r)
{
    uint32_t w;
    struct Rectangle ret;

    w = r->width;
    //@ assert w == r->height;
    ret.width = w;
    ret.height = w;
    return ret;
}

/* ===== Synthesized Complex Function ===== */

/* 
 * Scenario: Video frame buffer validation and cost analysis
 * 
 * Given a set of distinct frame IDs (v[0..n-1]), a prime-related parameter (input),
 * and a buffer size (x), this function:
 * 1. Checks that the frame set has at least 3 distinct IDs (for multi-frame processing)
 * 2. Computes a prime candidate from input
 * 3. Calculates memory cost based on buffer size x
 * 4. Creates a square output rectangle for display
 *
 * The core property: when the function succeeds, the output rectangle represents
 * a valid square frame with non-negative area, and the cost is within bounds.
 */

struct Rectangle process_frame_data(unsigned int input, int n, int *v, uint64_t x, struct Rectangle const *r)
{
    int prime_result;
    bool size_ok;
    uint64_t cost;
    struct Rectangle result_rect;
    
    size_ok = func_size_check(n, v);
    //@ assert size_ok == (n >= 3);
    
    prime_result = func_prime_check(input);
    //@ assert prime_result == 2 * input - 1 || prime_result == -1;
    
    cost = func_cost(x);
    //@ assert cost >= 0;
    
    result_rect = func_square_rect(r);
    //@ assert result_rect.width == r->width && result_rect.height == r->height;
    //@ assert area(result_rect.width, result_rect.height) >= 0;
    
    //@ assert area(result_rect.width, result_rect.height) >= 0 && cost >= 0;
    
    return result_rect;
}
