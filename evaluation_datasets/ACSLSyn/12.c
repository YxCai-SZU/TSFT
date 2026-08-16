/* Scenario: Network Packet Rate Limiter
 * 
 * In a network traffic management system, we need to check if a packet
 * should be allowed based on bandwidth constraints. The system has a
 * token bucket rate limiter where:
 * - d = current data size of packet (bytes)
 * - t = available tokens in bucket (bytes)
 * - s = burst size multiplier (scaling factor)
 * 
 * The first function checks if a packet fits within the available 
 * bandwidth (d <= t * s). The second function acts as a binary flag
 * converter that transforms the boolean result into a traffic action
 * (0 = allow, 1 = drop/mark).
 * 
 * This combined check ensures both that the packet fits within bandwidth
 * and that the resulting action is consistent with the bandwidth check.
 */

#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 && 1 <= t <= 10000 && 1 <= s <= 10000;

    lemma product_bound: \forall integer t, s;
        is_valid_params(1, t, s) ==> t * s <= 10000 * 10000;
*/

bool bandwidth_check(unsigned int d, unsigned int t, unsigned int s)
{
    //@ assert is_valid_params(d, t, s);
    //@ assert t * s <= 10000 * 10000;
    return d <= t * s;
}

/*@
    predicate is_zero(integer n) = n == 0;
    predicate is_one(integer n) = n == 1;
    logic integer func_result(integer n) = (n == 0) ? 1 : 0;
*/

uint32_t action_selector(uint32_t n)
{
    uint32_t result;
    
    //@ assert n <= 1;
    
    if (n == 0U)
    {
        result = 1U;
        //@ assert n == 0;
        return result;
    }
    else
    {
        //@ assert n == 1;
        result = 0U;
        return result;
    }
}

uint32_t rate_limiter(unsigned int d, unsigned int t, unsigned int s)
{
    bool fits;
    uint32_t action;
    
    //@ assert is_valid_params(d, t, s);
    
    fits = bandwidth_check(d, t, s);
    //@ assert fits == (d <= t * s);
    
    if (fits)
    {
        //@ assert fits == true;
        //@ assert d <= t * s;
        action = action_selector(0U);
        //@ assert action == 1;  // action_selector(0) returns 1
    }
    else
    {
        //@ assert fits == false;
        //@ assert d > t * s;
        action = action_selector(1U);
        //@ assert action == 0;  // action_selector(1) returns 0
    }
    
    //@ assert (d <= t * s) ==> (action == 1);
    //@ assert (d > t * s) ==> (action == 0);
    
    return action;
}

int main()
{
    unsigned int d;
    unsigned int t;
    unsigned int s;
    uint32_t result;
    
    d = 1000;
    t = 5000;
    s = 2000;
    result = rate_limiter(d, t, s);
    //@ assert result == 1;
    return 0;
}
