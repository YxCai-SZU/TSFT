/* Scenario: E-commerce Order Discount Eligibility Checker
 *
 * Data Flow:
 * - func1 (renamed to check_budget) verifies if a product's price (x) is within
 *   the budget limit (500 * k) for a given discount tier (k).
 * - func2 (renamed to compute_discount) computes the total discount amount as
 *   the product of two factors (e.g., quantity and per-unit discount).
 * - The synthesized function (check_order_eligibility) combines them: given a
 *   discount tier k, price x, quantity a, and per-unit discount b, it first
 *   checks if the price is within budget, then computes the total discount,
 *   and asserts that if the budget check passes, the total discount is
 *   non-negative and within a reasonable bound.
 */

#include <stdbool.h>
#include <limits.h>

/*@
    predicate valid_params(integer k, integer x) =
        1 <= k && k <= 100 &&
        1 <= x && x <= 100000 &&
        k * 500 <= 50000000;

    lemma multiplication_safe: \forall integer k, x; valid_params(k, x) ==> 500 * k <= 50000000;
*/

bool check_budget(long long k, long long x)
{
    long long product;
    bool result;

    //@ assert 1 <= k && k <= 100;
    //@ assert 1 <= x && x <= 100000;
    //@ assert k * 500 <= 50000000;
    
    product = 500 * k;
    //@ assert product <= 50000000;
    result = product >= x;
    
    return result;
}

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= safe_product(a, b) <= 10000;
*/

int compute_discount(int a, int b)
{
    long long c;
    int result;

    //@ assert valid_range(a, b);
    //@ assert 1 <= safe_product(a, b) <= 10000;

    c = (long long)a * (long long)b;

    if (c > (long long)INT_MAX)
    {
        result = INT_MAX;
    }
    else if (c < (long long)INT_MIN)
    {
        result = INT_MIN;
    }
    else
    {
        result = (int)c;
    }

    //@ assert result == safe_product(a, b);
    return result;
}

bool check_order_eligibility(long long k, long long x, int a, int b)
{
    bool budget_ok;
    int discount;

    budget_ok = check_budget(k, x);

    discount = compute_discount(a, b);

    /*@
        assert (budget_ok == (500 * k >= x)) &&
               (discount == safe_product(a, b)) &&
               (budget_ok ==> (discount >= 1 && discount <= 10000));
    */
    return budget_ok;
}
