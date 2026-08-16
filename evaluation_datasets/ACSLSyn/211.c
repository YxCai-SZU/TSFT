#include <stdint.h>

/*@
    predicate is_valid_range(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer mul_n(integer n) = 2 * n;
    logic integer mul_m(integer m) = 5 * m;
    logic integer total(integer n, integer m) = mul_n(n) + mul_m(m);

    lemma mul_n_no_overflow:
        \forall integer n; 1 <= n && n <= 100 ==> mul_n(n) == 2 * n;

    lemma mul_m_no_overflow:
        \forall integer m; 1 <= m && m <= 100 ==> mul_m(m) == 5 * m;
*/

int func(int n, int m)
{
    int mul_n;
    int mul_m;
    int result;

    //@ assert mul_n(n) == 2 * n;
    mul_n = 2 * n;

    //@ assert mul_m(m) == 5 * m;
    mul_m = 5 * m;

    result = (mul_n + mul_m) <= 100;
    return result;
}

/*@
    predicate non_negative(integer a, integer b, integer c) =
        0 <= a <= 50 && 0 <= b <= 50 && 0 <= c <= 50;

    logic integer total_sum(integer a, integer b, integer c) = a + b + c;

    lemma sum_bounds: \forall integer a, b, c;
        non_negative(a, b, c) ==> 0 <= total_sum(a, b, c) <= 150;
*/

int64_t func2(int64_t a, int64_t b, int64_t c)
{
    int64_t res = 0;
    int64_t local_a = a;
    int64_t local_b = b;
    int64_t local_c = c;

    //@ assert non_negative(local_a, local_b, local_c);

    if (local_a > local_b + local_c + 1)
    {
        res += local_a - (local_b + local_c + 1);
        local_a = local_b + local_c + 1;
    }
    else
    {
        local_a = 0;
    }

    //@ assert res >= 0;

    if (local_b > local_a + local_c + 1)
    {
        res += local_b - (local_a + local_c + 1);
        local_b = local_a + local_c + 1;
    }
    else
    {
        local_b = 0;
    }

    //@ assert res >= 0;

    if (local_c > local_a + local_b + 1)
    {
        res += local_c - (local_a + local_b + 1);
        local_c = local_a + local_b + 1;
    }
    else
    {
        local_c = 0;
    }

    //@ assert res >= 0;

    int64_t sum = local_a + local_b + local_c;
    int64_t last_res = 0;
    int64_t temp_sum = sum;

    while (temp_sum >= 3)
    {
        temp_sum -= 3;
        last_res += 1;
    }

    res += last_res;

    //@ assert res >= 0;
    //@ assert res <= a + b + c;

    return res;
}

/* 
 * Scenario: Resource allocation verification system
 * 
 * The system receives three resource types (a, b, c) and a capacity threshold (n, m).
 * First, it checks if the capacity threshold is valid using func.
 * Then, it computes the minimum number of resource units to redistribute
 * to balance the resources using func2.
 * 
 * The combined property ensures that when the capacity threshold is valid,
 * the redistribution cost never exceeds the total available resources.
 */

int64_t resource_balance_check(int n, int m, int64_t a, int64_t b, int64_t c)
{
    int threshold_valid;
    int64_t redistribution_cost;

    threshold_valid = func(n, m);
    
    redistribution_cost = func2(a, b, c);
    
    /*@ assert (threshold_valid == 1) ==> (redistribution_cost <= a + b + c); */
    
    return redistribution_cost;
}
