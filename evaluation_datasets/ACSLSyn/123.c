#include <stdint.h>

/* First function: selects an index based on parameters n and k */

int32_t select_index(uint32_t n, uint32_t k)
{
    int32_t result = 1;
    uint32_t i = 1;

    if (k == 1)
    {
        //@ assert result >= 1;
        //@ assert result <= n;
        return result;
    }

    while (i < n)
    {
        //@ assert k * i >= k;
        //@ assert k * i <= 2500;

        if ((k * i) % (k - 1) == 0)
        {
            result = (int32_t)i;
        }

        i = i + 1;
    }

    //@ assert result >= 1;
    //@ assert result <= n;
    return result;
}

/* Second function: determines a parity-based flag from two parameters */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    predicate is_valid_m(integer m) = 1 <= m && m <= 100;
    
    logic integer product(integer n, integer m) = (n - 1) * (m - 1);
    
    lemma product_bounds:
        \forall integer n, m;
        is_valid_n(n) && is_valid_m(m) ==> 0 <= product(n, m) <= 99 * 99;
*/

int32_t compute_flag(uint32_t n, uint32_t m)
{
    uint32_t n_is_odd;
    uint32_t m_is_odd;
    uint32_t product;
    int32_t ans;
    
    //@ assert n - 1 >= 0 && n - 1 <= 99;
    //@ assert m - 1 >= 0 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    
    n_is_odd = (n % 2 == 1) ? 1 : 0;
    m_is_odd = (m % 2 == 1) ? 1 : 0;
    product = (n - 1) * (m - 1);
    
    if (product == 0)
    {
        ans = 0;
    }
    else if (product == 1)
    {
        ans = 1;
    }
    else
    {
        if ((n_is_odd * m_is_odd) == 1)
        {
            ans = 0;
        }
        else
        {
            ans = 1;
        }
    }
    
    //@ assert ans == 0 || ans == 1;
    return ans;
}

/* Synthesized function: simulates a simple resource allocation check in a system
   Scenario: Given a number of resources n and a step parameter k, select a candidate 
   resource index using select_index, then verify its allocation eligibility using 
   compute_flag with the index and original n as parameters. The final assertion ensures 
   the allocation decision (flag) is valid (0 or 1) for the selected resource. */

int32_t check_allocation(uint32_t n, uint32_t k)
{
    int32_t selected;
    int32_t flag;

    selected = select_index(n, k);
    //@ assert selected >= 1 && selected <= n;

    flag = compute_flag((uint32_t)selected, n);
    //@ assert flag == 0 || flag == 1;
    
    //@ assert (flag == 0 || flag == 1);
    return flag;
}
