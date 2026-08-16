#include <stdbool.h>

/* 
 * Scenario: Resource allocation in a network scheduling system.
 *
 * The synthesized function `can_allocate_resources` determines if a network node 
 * with a given capacity can accommodate a request for resource blocks, considering 
 * both a coarse-grained check (first function) and a fine-grained check (second function).
 *
 * Data flow:
 * - The first function `func` (renamed to `check_capacity`) validates if the node's 
 *   capacity (n) is sufficient for a basic allocation unit (m) using a specific formula.
 * - The second function `func` (renamed to `check_fine_grained`) performs a more 
 *   detailed check comparing capacity (n) against a scaled request (k).
 * - The synthesized function combines these: first, it checks basic capacity; if 
 *   that passes, it proceeds to the fine-grained check. The final assertion ensures 
 *   that when both checks pass, the fine-grained condition implies the basic one, 
 *   ensuring consistency.
 */

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer condition(integer n, integer m) = (n - 1) / 2 >= m - 1 ? 1 : 0;
*/

bool check_capacity(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert valid_range(n, m);
    result = ((n - 1) / 2) >= (m - 1);
    //@ assert result == (condition(n, m) != 0);
    return result;
}

/*@
    predicate condition_holds(integer n, integer k) =
        n >= k * 2 - 1;
*/

bool check_fine_grained(unsigned long n, unsigned long k)
{
    bool result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;
    
    if (n >= k * 2 - 1) {
        //@ assert condition_holds(n, k);
        result = true;
    } else {
        //@ assert !condition_holds(n, k);
        result = false;
    }
    
    return result;
}

bool can_allocate_resources(unsigned int n, unsigned int m, unsigned long k)
{
    bool basic_ok;
    bool fine_ok;
    
    basic_ok = check_capacity(n, m);
    
    if (basic_ok) {
        //@ assert condition(n, m) != 0;
        fine_ok = check_fine_grained((unsigned long)n, k);
    } else {
        fine_ok = false;
    }
    
    //@ assert basic_ok ==> (condition(n, m) != 0);
    //@ assert fine_ok ==> (n >= k * 2 - 1);
    
    //@ assert (basic_ok && fine_ok) ==> (condition(n, m) != 0 && (n >= k * 2 - 1));
    
    return basic_ok && fine_ok;
}
