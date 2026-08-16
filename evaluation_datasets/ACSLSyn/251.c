#include <stdint.h>
#include <stdbool.h>

/* ==================== Original Function 1: Bulk price calculation ==================== */

/*@
    predicate price_constant(integer p) = p == 1080;

    logic integer discounted_price(integer i) = i * 800;
    logic integer bulk_discount(integer i) = i * 200;

    lemma result_non_negative:
        \forall integer n, d, b;
            1 <= n <= 100 && d == discounted_price(n) && b == bulk_discount(n / 15) ==>
            d - b >= 0;
*/

int32_t func_price(uint32_t n)
{
    int32_t price;
    int32_t discounted_price;
    int32_t bulk_discount;
    uint32_t i;
    int32_t result;

    price = 1080;

    discounted_price = 0;
    i = 0;
    while (i < n)
    {
        //@ assert discounted_price == i * 800;
        discounted_price += 800;
        i += 1;
    }

    bulk_discount = 0;
    i = 0;
    while (i < n / 15)
    {
        //@ assert bulk_discount == i * 200;
        bulk_discount += 200;
        i += 1;
    }

    result = discounted_price - bulk_discount;
    //@ assert result == (n * 800 - (n / 15) * 200);
    //@ assert result >= 0;

    return result;
}

/* ==================== Original Function 2: Condition check ==================== */

/*@ predicate condition(integer a, integer b, integer x) =
      b <= x && a + b >= x;
*/

bool func_check(unsigned long long a, unsigned long long b, unsigned long long x) {
    //@ assert condition(a, b, x) ==> condition(a, b, x);
    return b <= x && a + b >= x;
}

/* ==================== Original Function 3: Resource bound calculation ==================== */

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 &&
        1 <= m <= n &&
        m <= 5;

    logic integer upper_bound(integer n, integer m) =
        110 + (n - m) * 100 + m * 191;

    lemma final_bound_lemma:
        \forall integer n, m, result;
        valid_params(n, m) &&
        result >= 110 &&
        result <= upper_bound(n, m) ==>
        result <= upper_bound(n, m);
*/

int32_t func_bound(uint32_t n, uint32_t m)
{
    int32_t result = 0;
    uint32_t i = 0;

    //@ assert valid_params(n, m);
    
    if (n == m)
    {
        result += 190 * (int32_t)m;
    }
    else
    {
        result += 190 * (int32_t)m;
        result += (int32_t)(n - m) * 100;
        
        while (i < m)
        {
            if (n < 3 + i)
            {
                break;
            }
            result += 1;
            i += 1;
        }
    }
    
    //@ assert result <= upper_bound(n, m);
    return result;
}

/* ==================== Synthesized Function: E-commerce order processing ==================== */

int32_t process_order(uint32_t n, uint32_t m, unsigned long long a, unsigned long long b, unsigned long long x)
{
    int32_t price = func_price(n);
    //@ assert price == (n * 800 - (n / 15) * 200);
    //@ assert price >= 0;

    bool promotion = func_check(a, b, x);
    //@ assert promotion == 1 <==> (b <= x && a + b >= x);

    int32_t resource_cost = func_bound(n, m);
    //@ assert resource_cost >= 110;
    //@ assert resource_cost <= upper_bound(n, m);

    int32_t total_cost;
    if (promotion)
    {
        total_cost = (price * 9) / 10 + resource_cost;
    }
    else
    {
        total_cost = price + resource_cost;
    }

    //@ assert total_cost >= 0;
    //@ assert total_cost <= (n * 800 - (n / 15) * 200) + 110 + (n - m) * 100 + m * 191;
    return total_cost;
}
