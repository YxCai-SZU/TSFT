#include <stdbool.h>
#include <stdint.h>

/* ================== Function 1: Resource capacity check ================== */

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        0 <= a && a <= 10000 &&
        0 <= b && b <= 10000 &&
        0 <= c && c <= 10000 &&
        0 <= d && d <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer a, b;
        0 <= a && a <= 10000 && 0 <= b && b <= 10000 ==>
        0 <= product(a, b) && product(a, b) <= 100000000;
*/

bool resource_check(unsigned long long a, unsigned long long b,
                    unsigned long long c, unsigned long long d)
{
    bool result;

    //@ assert 0 <= a && a <= 10000;
    //@ assert 0 <= b && b <= 10000;
    //@ assert 0 <= c && c <= 10000;
    //@ assert 0 <= d && d <= 10000;

    //@ assert 0 <= a * b && a * b <= 100000000;
    //@ assert 0 <= c * d && c * d <= 100000000;

    result = (a * b) <= (c * d);
    return result;
}

/* ================== Function 2: Ratio validation ================== */

/*@
    predicate valid_range(integer x) = 1 <= x <= 100000;

    logic integer div100(integer x) = x / 100;
    logic integer mod100(integer x) = x % 100;

    lemma mod_property:
        \forall integer x; valid_range(x) ==>
        (mod100(x) <= 5 * div100(x) || mod100(x) > 5 * div100(x));
*/

uint32_t ratio_check(uint64_t x)
{
    uint64_t quotient = 0;
    uint64_t remainder = x;
    
    while (remainder >= 100)
    {
        remainder -= 100;
        quotient += 1;
    }

    uint64_t d = quotient;
    uint64_t m = remainder;

    if (m <= 5 * d)
    {
        //@ assert x % 100 <= 5 * (x / 100);
        return 1;
    }
    else
    {
        //@ assert x % 100 > 5 * (x / 100);
        return 0;
    }
}

/* ================== Function 3: Budget calculation ================== */

/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer total_sum(integer k) = 500 * k;

    lemma sum_bound: \forall integer k; 1 <= k <= 100 ==> total_sum(k) <= 50000;
*/

int budget_check(unsigned int k, unsigned int x)
{
    unsigned int n;
    unsigned int i;
    unsigned int sum;

    n = 500;
    i = 0;
    sum = 0;

    while (i < k)
    {
        sum += n;
        i += 1;
    }

    //@ assert sum == total_sum(k);
    return sum >= x ? 1 : 0;
}

/* ================== Synthesized Function: Resource allocation decision ================== */

/*@
    predicate valid_allocation(integer a, integer b, integer c, integer d,
                                integer k, integer x, integer y) =
        bounds(a, b, c, d) &&
        valid_range(y) &&
        valid_params(k, x) &&
        1 <= y <= 100000 &&
        1 <= x <= 100000;
*/

int allocate_resources(unsigned long long a, unsigned long long b,
                       unsigned long long c, unsigned long long d,
                       unsigned int k, unsigned int x,
                       uint64_t y)
{
    bool cap_ok;
    uint32_t ratio_ok;
    int budget_ok;
    int decision;

    cap_ok = resource_check(a, b, c, d);

    ratio_ok = ratio_check(y);

    budget_ok = budget_check(k, x);

    if (cap_ok && ratio_ok == 1 && budget_ok == 1)
    {
        decision = 1;
    }
    else
    {
        decision = 0;
    }

    //@ assert (decision == 1) <==> (cap_ok && ratio_ok == 1 && budget_ok == 1);

    /* High-level property: allocation decision is valid if and only if
       capacity is sufficient, ratio is acceptable, and budget covers the need */
    //@ assert (decision == 1) <==> ((a * b <= c * d) && (y % 100 <= 5 * (y / 100)) && (500 * k >= x));

    return decision;
}
