#include <limits.h>
#include <stdbool.h>

/*@ requires ((1 <= ((s0)) && ((s0)) <= 100) && (1 <= ((s1)) && ((s1)) <= 100) && (1 <= ((s2)) && ((s2)) <= 100));
    ensures \result >= 0;
    ensures \result <= ((s0) + (s1)) || 
            \result <= ((s1) + (s2)) || 
            \result <= ((s2) + (s0));
    assigns \nothing;
 */
long func(long s0, long s1, long s2) {
    long ans;
    long tmp1;
    long tmp2;
    long tmp3;
    
    ans = LONG_MAX;
    
    //@ assert ((s0) + (s1)) <= 200;
    tmp1 = s0 + s1;
    ans = ans < tmp1 ? ans : tmp1;
    
    //@ assert ((s1) + (s2)) <= 200;
    tmp2 = s1 + s2;
    ans = ans < tmp2 ? ans : tmp2;
    
    //@ assert ((s2) + (s0)) <= 200;
    tmp3 = s2 + s0;
    ans = ans < tmp3 ? ans : tmp3;
    
    return ans;
}
