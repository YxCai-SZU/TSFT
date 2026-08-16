#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer p) =
        0 <= a && a <= 100 && 0 <= p && p <= 100;

    logic integer compute_pies(integer a, integer p) =
        (a * 3 + p) / 2;

    lemma overflow_prevention:
        \forall integer a, p; valid_input(a, p) ==> a * 3 + p <= 4294967295;
*/

uint32_t compute_pies(uint32_t a, uint32_t p)
{
    uint32_t pies;

    //@ assert valid_input(a, p);
    //@ assert a * 3 + p <= 4294967295;

    pies = (a * 3 + p) / 2;

    //@ assert pies >= 0;
    //@ assert pies == compute_pies(a, p);

    return pies;
}

/*@
    predicate valid_params(integer n, integer m, integer k) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100 &&
        0 <= k && k <= n * m;

    logic integer bound(integer n, integer m) = n * m - (n + m - 1);

    lemma product_bound: \forall integer n, m;
        valid_params(n, m, 0) ==> n * m <= 10000;

    lemma sum_bound: \forall integer n, m;
        valid_params(n, m, 0) ==> n + m - 1 <= 199;

    lemma bound_nonneg: \forall integer n, m;
        valid_params(n, m, 0) ==> bound(n, m) >= 0;

    lemma bound_max: \forall integer n, m;
        valid_params(n, m, 0) ==> bound(n, m) <= 9999;
*/

bool is_feasible(unsigned int n, unsigned int m, unsigned int k)
{
    bool result;

    //@ assert n * m <= 10000;
    //@ assert n + m - 1 <= 199;
    //@ assert n * m - (n + m - 1) >= 0;
    //@ assert n * m - (n + m - 1) <= 9999;

    result = (k <= (n * m - (n + m - 1)));
    return result;
}

/*@
    predicate valid_range(integer n) = 1 <= n <= 100;
    logic integer formula(integer n, integer m) = n * m - (n - 1) - (m - 1) - 1;
*/

int32_t compute_available(int32_t n, int32_t m)
{
    uint32_t n_unsigned;
    uint32_t m_unsigned;
    int32_t ans;

    n_unsigned = (uint32_t)n;
    m_unsigned = (uint32_t)m;

    //@ assert n_unsigned - 1 <= 99;
    //@ assert m_unsigned - 1 <= 99;
    //@ assert n_unsigned * m_unsigned <= 10000;

    ans = n * m - (n - 1) - (m - 1) - 1;
    return ans;
}

/*@
    predicate valid_bakery_params(integer a, integer p, integer n, integer m, integer k) =
        valid_input(a, p) && valid_range(n) && valid_range(m) && 0 <= k && k <= 10000;

    predicate order_feasible(integer a, integer p, integer n, integer m, integer k) =
        k <= compute_pies(a, p) && k <= formula(n, m);
*/

bool bakery_resource_planner(uint32_t a, uint32_t p, int32_t n, int32_t m, unsigned int k)
{
    uint32_t pies;
    int32_t available;
    bool result;

    pies = compute_pies(a, p);

    available = compute_available(n, m);

    //@ assert k <= pies || k > pies;
    //@ assert k <= available || k > available;

    result = (k <= (unsigned int)available) && (k <= pies);

    //@ assert result <==> order_feasible(a, p, n, m, k);

    return result;
}
