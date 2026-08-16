#include <stdint.h>
#include <stdbool.h>

/* ========== Function 1: packet_priority_check ========== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer sum(integer x, integer y) = x + y;
    
    lemma sum_range:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 1 <= sum(x, y) <= 20000;
*/

int packet_priority_check(long long a, long long b, long long c, long long d)
{
    long long a_new;
    long long b_new;
    int result;
    
    //@ assert valid_range(a) && valid_range(d);
    //@ assert 1 <= a + d <= 20000;
    a_new = a + d;
    
    //@ assert valid_range(c) && valid_range(b);
    //@ assert 1 <= c + b <= 20000;
    b_new = c + b;
    
    result = 0;
    
    if (a_new < b_new)
    {
        result = 1;
    }
    
    //@ assert a_new == a + d;
    //@ assert b_new == c + b;
    //@ assert result == (a_new < b_new);
    //@ assert result == (a + d < c + b);
    
    return result;
}

/* ========== Function 2: exact_change_possible ========== */
/*@
    predicate valid_x(integer x) = 1 <= x <= 100000;
    predicate valid_i(integer x, integer i) = 1 <= i <= x / 6 + 1;
    predicate valid_j(integer x, integer i, integer j) = 1 <= j <= (x - 6 * i) / 4 + 1;
    predicate valid_k(integer x, integer i, integer j, integer k) = 1 <= k <= (x - 6 * i - 4 * j) / 2 + 1;
    predicate all_zero(integer a, integer b, integer c) = a == 0 && b == 0 && c == 0;
*/

int32_t exact_change_possible(uint32_t x)
{
    int32_t a = 0;
    uint32_t i = 1;
    
    while (i <= x / 6)
    {
        int32_t b = 0;
        uint32_t j = 1;
        
        while (j <= (x - 6 * i) / 4)
        {
            int32_t c = 0;
            uint32_t k = 1;
            
            while (k <= (x - 6 * i - 4 * j) / 2)
            {
                //@ assert valid_x(x);
                if (k * 2 + j * 4 + i * 6 == x)
                {
                    return 1;
                }
                k += 1;
            }
            c += 1;
            j += 1;
        }
        b += 1;
        i += 1;
    }
    return 0;
}

/* ========== Function 3: compute_budget_usage ========== */
/*@
    predicate valid_vec(unsigned int *arr, integer len) =
        len >= 3 &&
        1 <= arr[0] <= 100 &&
        1 <= arr[1] <= 20 &&
        1 <= arr[2] <= 2000;

    logic integer vec_len(unsigned int *arr, integer len) = len;

    logic integer vec_at(unsigned int *arr, integer idx) = arr[idx];
*/

unsigned int compute_budget_usage(unsigned int *xs, unsigned int len) {
    unsigned int water;
    //@ assert len >= 3;
    //@ assert 1 <= xs[0] <= 100;
    //@ assert 1 <= xs[1] <= 20;
    //@ assert 1 <= xs[2] <= 2000;
    
    water = xs[0] + xs[1];
    
    if (water < xs[2]) {
        //@ assert water <= xs[2];
        return water;
    } else {
        //@ assert xs[2] <= 2000;
        return xs[2];
    }
}

/* ========== Function 4: compute_allocated_size ========== */
/*@
    predicate bounds(integer x) = 0 <= x <= 100;

    logic integer func_spec(integer x, integer y, integer z) =
        x + y + 1 <= z ?
            (y < x ? y : x) + (z - (x + y + 1) - (z - (x + y + 1)) / 2)
        : x + y + z;

    lemma func_lemma: \forall integer x, y, z;
        bounds(x) && bounds(y) && bounds(z) ==> func_spec(x, y, z) <= x + y + z;
*/

uint32_t compute_allocated_size(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t ans;
    uint32_t min_val;
    uint32_t tmp1;
    uint32_t tmp2;
    uint32_t tmp3;

    //@ assert bounds(x) && bounds(y) && bounds(z);
    
    if (x + y + 1 <= z)
    {
        //@ assert x + y + 1 <= z;
        
        if (y < x)
        {
            min_val = y;
        }
        else
        {
            min_val = x;
        }
        
        //@ assert min_val <= x && min_val <= y;
        
        tmp1 = z - (x + y + 1);
        //@ assert tmp1 <= 99;
        
        tmp2 = tmp1 / 2;
        //@ assert tmp2 <= 49;
        
        tmp3 = tmp1 - tmp2;
        ans = min_val + tmp3;
        
        //@ assert ans <= 100;
    }
    else
    {
        ans = x + y + z;
    }
    
    //@ assert ans <= x + y + z;
    return ans;
}

/* ========== Synthesized Function: process_packet_allocation ========== */

int process_packet_allocation(
    long long a, long long b, long long c, long long d,
    uint32_t x,
    unsigned int *xs, unsigned int len,
    uint32_t x2, uint32_t y2, uint32_t z2
) {
    int priority_result;
    int change_result;
    unsigned int budget_result;
    uint32_t alloc_result;
    int final_result = 0;

    priority_result = packet_priority_check(a, b, c, d);
    //@ assert priority_result == (a + d < c + b);

    if (priority_result == 0) {
        //@ assert !(a + d < c + b);
        return 0;
    }
    //@ assert a + d < c + b;

    change_result = exact_change_possible(x);
    //@ assert change_result == 0 || change_result == 1;

    if (change_result == 0) {
        return 0;
    }
    //@ assert change_result == 1;

    budget_result = compute_budget_usage(xs, len);
    //@ assert budget_result <= xs[2];

    if (budget_result >= 1000) {
        return 0;
    }
    //@ assert budget_result < 1000;

    alloc_result = compute_allocated_size(x2, y2, z2);
    //@ assert alloc_result <= x2 + y2 + z2;

    if (alloc_result > 150) {
        return 0;
    }
    //@ assert alloc_result <= 150;

    final_result = 1;

    //@ assert final_result == 1 ==> (a + d < c + b && change_result == 1 && budget_result < 1000 && alloc_result <= 150);
    //@ assert final_result == 1 ==> (a + d < c + b);

    return final_result;
}
