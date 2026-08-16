#include <stdbool.h>
#include <stdint.h>

/* ACSL predicates and lemmas from original functions */

/* Function 1: resource allocation check */
/*@
    predicate condition_holds(integer a, integer b, integer k) =
        a >= k || a + b >= k;
 */

bool alloc_check(int a, int b, int c, int k)
{
    int k_remaining;
    int a_remaining;
    int b_remaining;

    k_remaining = k;
    a_remaining = (a < k_remaining) ? a : k_remaining;
    k_remaining = k_remaining - a_remaining;
    b_remaining = (b < k_remaining) ? b : k_remaining;
    k_remaining = k_remaining - b_remaining;

    //@ assert condition_holds(a, b, k) <==> (a >= k || a + b >= k);

    if (a >= k || a + b >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Function 2: ordering check */
/*@
    predicate diff_in_range(integer diff) = -99 <= diff <= 99;
    predicate prod_in_range(integer prod) = -9801 <= prod <= 9801;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma diff1_range: \forall integer a, c; 1 <= a <= 100 && 1 <= c <= 100 ==> diff_in_range(a - c);
    lemma diff2_range: \forall integer b, d; 1 <= b <= 100 && 1 <= d <= 100 ==> diff_in_range(b - d);
    lemma prod_range: \forall integer x, y; diff_in_range(x) && diff_in_range(y) ==> prod_in_range(product(x, y));
*/

bool order_check(int a, int b, int c, int d) {
    int diff1;
    int diff2;
    int prod;
    bool result;
    
    diff1 = a - c;
    diff2 = b - d;
    
    //@ assert diff_in_range(diff1);
    //@ assert diff_in_range(diff2);
    
    prod = diff1 * diff2;
    
    //@ assert prod_in_range(prod);
    
    if (prod < 0) {
        result = true;
    } else {
        if (prod == 0) {
            result = (a <= c && b <= d);
        } else {
            result = false;
        }
    }
    
    return result;
}

/* Function 3: align to multiple of 5 */
/*@
    predicate is_mod_zero(integer x) = x % 5 == 0;
    predicate is_mod_nonzero(integer x) = x % 5 != 0;
*/

/*@
    logic integer compute_result(integer x) =
        (x % 5 == 0) ? 0 : (5 - (x % 5));
*/

/*@
    lemma mod_zero_implies_zero:
        \forall integer x; 0 <= x <= 1000000000 && x % 5 == 0 ==> compute_result(x) == 0;
    
    lemma mod_nonzero_implies_complement:
        \forall integer x; 0 <= x <= 1000000000 && x % 5 != 0 ==> compute_result(x) == 5 - (x % 5);
*/

uint32_t align_to_5(uint32_t x)
{
    uint32_t y;
    uint32_t result;
    
    y = x % 5;
    
    if (y == 0)
    {
        //@ assert y == 0;
        result = 0;
    }
    else
    {
        //@ assert y != 0;
        result = 5 - y;
    }
    
    return result;
}

/* Function 4: triangle inequality check */
/*@
    predicate sorted(integer min, integer mid, integer max) =
        min <= mid && mid <= max;
*/

bool triangle_check(const unsigned int* a) {
    unsigned int a_0;
    unsigned int a_1;
    unsigned int a_2;
    unsigned int min1;
    unsigned int mid;
    unsigned int max;

    a_0 = a[0];
    a_1 = a[1];
    a_2 = a[2];

    if (a_0 <= a_1 && a_0 <= a_2) {
        if (a_1 <= a_2) {
            min1 = a_0;
            mid = a_1;
            max = a_2;
        } else {
            min1 = a_0;
            mid = a_2;
            max = a_1;
        }
    } else if (a_1 <= a_0 && a_1 <= a_2) {
        if (a_0 <= a_2) {
            min1 = a_1;
            mid = a_0;
            max = a_2;
        } else {
            min1 = a_1;
            mid = a_2;
            max = a_0;
        }
    } else {
        if (a_0 <= a_1) {
            min1 = a_2;
            mid = a_0;
            max = a_1;
        } else {
            min1 = a_2;
            mid = a_1;
            max = a_0;
        }
    }

    //@ assert sorted(min1, mid, max);

    return max == min1 + mid;
}

/* 
 * Synthesized function: Resource allocation and validation for a packet processing system
 * 
 * Scenario: A network packet processor needs to allocate buffer resources (alloc_check),
 * validate packet ordering (order_check), align payload sizes to alignment boundary (align_to_5),
 * and verify packet segment relationships (triangle_check).
 * 
 * Data flow:
 * 1. Input parameters: resource sizes (a,b,c), allocation request (k), ordering coordinates (a1,b1,c1,d1),
 *    payload size (x), and triangle sides (arr)
 * 2. First, check if allocation is possible (alloc_check)
 * 3. If allocation possible, check ordering constraints (order_check)
 * 4. Then align payload size (align_to_5)
 * 5. Finally verify triangle relationship (triangle_check)
 * 6. Return true only if all checks pass
 */

bool packet_processor(int a, int b, int c, int k, int a1, int b1, int c1, int d1, uint32_t x, const unsigned int* arr) {
    bool alloc_ok;
    bool order_ok;
    uint32_t aligned_size;
    bool triangle_ok;
    
    alloc_ok = alloc_check(a, b, c, k);
    
    if (alloc_ok) {
        order_ok = order_check(a1, b1, c1, d1);
    } else {
        order_ok = false;
    }
    
    aligned_size = align_to_5(x);
    
    triangle_ok = triangle_check(arr);
    
    //@ assert alloc_ok ==> condition_holds(a, b, k);
    //@ assert order_ok ==> ((a1 - c1) * (b1 - d1) < 0 || ((a1 - c1) * (b1 - d1) == 0 && a1 <= c1 && b1 <= d1));
    //@ assert triangle_ok ==> (arr[1] == arr[0] + arr[2] || arr[2] == arr[1] + arr[0] || arr[0] == arr[2] + arr[1]);
    
    return alloc_ok && order_ok && triangle_ok;
}
