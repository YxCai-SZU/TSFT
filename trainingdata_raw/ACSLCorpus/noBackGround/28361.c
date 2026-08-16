#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result == (100 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    int32_t ans;
    uint32_t shift_count;

    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (m) <= 5);
    
    // Precondition verification
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= n;
    //@ assert m <= 5;
    
    // Calculate initial value
    ans = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    
    //@ assert ans == (100 * ((n) - (m)) + 1900 * (m));
    
    shift_count = m;
    
    /*@
        loop invariant 0 <= shift_count <= m;
        loop invariant ans == (100 * ((n) - (m)) + 1900 * (m));
        loop assigns ans, shift_count;
        loop variant shift_count;
    */
    while (shift_count > 0)
    {
        int32_t current_target;
        
        current_target = 100 * ((int32_t)n - (int32_t)shift_count) + 1900 * (int32_t)shift_count;
        
        //@ assert current_target == (100 * ((n) - (shift_count)) + 1900 * (shift_count));
        
        if (ans < current_target) {
            ans = current_target;
        }
        
        //@ assert ans == (100 * ((n) - (m)) + 1900 * (m));
        
        shift_count--;
    }
    
    //@ assert ans == (100 * ((n) - (m)) + 1900 * (m));
    return ans;
}
