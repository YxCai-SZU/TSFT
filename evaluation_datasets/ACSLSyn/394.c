#include <stdint.h>
#include <stdbool.h>

/* ====== 1st function: compute score range ====== */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 &&
        1 <= m <= n &&
        m <= 5;

    logic integer lower_bound(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    logic integer upper_bound(integer n, integer m) =
        100 * (n - m) + 1900 * m + 100 * m;
*/

int32_t func1(uint32_t n, uint32_t m)
{
    int32_t result;
    
    result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    if (m != n) {
        result += 100 * (int32_t)m;
    }
    
    return result;
}

/* ====== 2nd function: check if both <= 8 ====== */
/*@ predicate is_max(integer a, integer b, integer m) =
      (a > b ==> m == a) && (a <= b ==> m == b);
*/

/*@ lemma max_bound: \forall integer a, b, m;
        is_max(a, b, m) ==> (m == a || m == b);
*/

bool func2(int a, int b) {
    int max_val;

    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }

    return max_val <= 8;
}

/* ====== 3rd function: count distributable items ====== */
/*@
    predicate valid_inputs(integer a, integer b, integer c) =
        0 <= a && a <= 50 &&
        0 <= b && b <= 50 &&
        0 <= c && c <= 50;

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;
*/

long func3(long a, long b, long c)
{
    long counter = 0;
    long remaining = c;

    if (a >= remaining)
    {
        counter += remaining;
        remaining = 0;
    }
    else
    {
        counter += a;
        remaining -= a;
    }

    if (b >= remaining)
    {
        counter += remaining;
        remaining = 0;
    }
    else
    {
        counter += b;
        remaining -= b;
    }

    return counter;
}

/* ====== 4th function: compute total cost ====== */
/*@
    predicate valid_input(integer x, integer y, integer z, integer a) =
        x >= 0 && x <= 1000000000 &&
        y >= 0 && y <= 1000000000 &&
        z >= 0 && z <= 1000000000 &&
        a >= 0 && a <= 1000000000 &&
        x * y + z + a <= 1000000000000000000;
*/

int64_t func4(int64_t x, int64_t y, int64_t z, int64_t a)
{
    return x * y + z + a;
}

/* ====== Synthesized function: Process order items ====== */
/* Scenario: An e-commerce order processing system.
   Data flow:
   - Compute base score for order (func1)
   - Check if two item categories are both small (func2)
   - Count distributable items from three categories (func3)
   - Compute total cost with quantity * price + shipping + tax (func4)
   The synthesized function processes an order and returns a status code.
*/

/*@
    predicate valid_order(integer n, integer m, integer a, integer b, long c1, long c2, long c3,
                          int64_t x, int64_t y, int64_t z, int64_t tax) =
        valid_params(n, m) &&
        1 <= a <= 16 && 1 <= b <= 16 && a + b <= 16 &&
        valid_inputs(c1, c2, c3) &&
        valid_input(x, y, z, tax);
*/

int64_t process_order(uint32_t n, uint32_t m, int a, int b, long c1, long c2, long c3,
                      int64_t x, int64_t y, int64_t z, int64_t tax)
{
    int32_t score = func1(n, m);
    bool both_small = func2(a, b);
    long distributed = func3(c1, c2, c3);
    int64_t total_cost = func4(x, y, z, tax);
    
    int64_t status = 0;
    
    if (score > 1000) {
        status += 500;
    }
    
    if (both_small) {
        status += 500;
    }
    
    status += distributed;
    status += total_cost;
    
    return status;
}
