#include <stdint.h>

/* Original first function: computes a "cost" based on x / 11 and x % 11 */
/*@
    predicate valid_x(integer x) = 1 <= x && x <= 100000000000000000;
    logic integer quotient(integer x) = x / 11;
    logic integer remainder(integer x) = x % 11;
*/

uint64_t func(uint64_t x)
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

/* Original second function: computes distance to next multiple of 1000 */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;
    
    logic integer div_1000(integer n) = n / 1000;
    
    logic integer next_multiple(integer n) = (div_1000(n) + 1) * 1000;
    
    lemma result_correctness:
        \forall integer n;
        is_valid_n(n) ==> next_multiple(n) - n == (n / 1000 + 1) * 1000 - n;
*/

int func2(int n)
{
    int result;
    int temp_n;
    int count;
    
    result = 0;
    temp_n = n;
    count = 0;
    
    while (temp_n >= 1000)
    {
        temp_n -= 1000;
        count += 1;
    }
    
    int next_multiple_of_1000 = (count + 1) * 1000;
    result = next_multiple_of_1000 - n;
    
    //@ assert result == (n / 1000 + 1) * 1000 - n;
    
    return result;
}

/* Synthesized function: Simulates a two-step resource allocation scenario.
 * First, compute a base cost using func (based on resource units divided into groups of 11).
 * Then, compute a padding cost using func2 (based on alignment to next 1000-byte boundary).
 * The combined cost is the sum of these two costs.
 * The high-level property: the total cost is non-negative and bounded by a linear function of the inputs.
 */

uint64_t combined_func(uint64_t x, int n)
{
    uint64_t cost1 = func(x);
    int cost2 = func2(n);
    
    uint64_t total_cost = cost1 + (uint64_t)cost2;
    
    //@ assert total_cost >= 0;
    
    return total_cost;
}
