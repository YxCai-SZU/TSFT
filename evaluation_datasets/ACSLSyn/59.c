#include <stdbool.h>

/* First function: reachability check */
/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer d, t, s;
        valid_params(d, t, s) ==> 1 <= product(t, s) <= 100000000;
*/

bool reachable(long d, long t, long s)
{
    bool is_reachable;
    
    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;
    //@ assert 1 <= t * s && t * s <= 100000000;
    
    is_reachable = t * s >= d;
    return is_reachable;
}

/* Second function: resource allocation check */
/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;
    logic integer compute_n(integer x) = x / 100;
    predicate compute_ans(integer x) = compute_n(x) * 100 <= x;
*/

bool resource_alloc(unsigned int x) {
    bool ans = true;
    unsigned int n = x / 100;
    unsigned int i = 0;
    
    while (i < n) {
        unsigned int sum = 0;
        unsigned int j = 0;
        
        while (j < 100) {
            sum += 1;
            j += 1;
        }
        
        i += 1;
    }
    
    //@ assert ans == true <==> compute_ans(x);
    return ans;
}

/* Synthesized function: Network bandwidth allocation system
   Scenario: A network resource manager checks if a requested bandwidth (d) 
   can be allocated given time slots (t) and sub-channels (s). 
   It also verifies that the resource allocation (x) is properly aligned 
   to 100-byte blocks.
   
   Data flow:
   - Input: d (bandwidth request), t (time slots), s (sub-channels), 
            x (total resource in bytes)
   - Process: First check reachability via reachable(), then validate 
              resource alignment via resource_alloc()
   - Output: true if both conditions are met (bandwidth is reachable AND 
             resource allocation is properly aligned)
*/

/*@
    predicate valid_network_params(integer d, integer t, integer s, integer x) =
        valid_params(d, t, s) && is_valid_x(x);
    
    predicate network_allocation_valid(integer d, integer t, integer s, integer x) =
        (product(t, s) >= d) && compute_ans(x);
*/

bool network_bandwidth_allocator(long d, long t, long s, unsigned int x) {
    bool bandwidth_ok = reachable(d, t, s);
    bool resource_ok = resource_alloc(x);
    bool result = bandwidth_ok && resource_ok;
    
    //@ assert result == true <==> (bandwidth_ok && resource_ok);
    //@ assert bandwidth_ok == (product(t, s) >= d);
    //@ assert resource_ok == true <==> compute_ans(x);
    //@ assert result == true <==> ((product(t, s) >= d) && compute_ans(x));
    
    //@ assert result == true <==> network_allocation_valid(d, t, s, x);
    
    return result;
}
