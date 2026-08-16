#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (314159)* (r)) / 100000);
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t ans;
    int64_t temp;
    int64_t div;
    
    pi = 314159;
    ans = 0;
    temp = 2 * pi * r;
    div = 100000;
    
    //@ assert pi == (314159);
    //@ assert div == 100000;
    //@ assert temp == 2 * pi * r;
    
    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant pi == (314159);
        loop invariant div == 100000;
        loop invariant ans >= 0;
        loop invariant temp >= 0;
        loop invariant temp + div * ans == 2 * pi * r;
        loop assigns temp, ans;
        loop variant temp;
    */
    while (temp >= div) {
        //@ assert temp >= div;
        temp -= div;
        ans += 1;
        //@ assert temp + div * ans == 2 * pi * r;
    }
    
    //@ assert temp < div;
    //@ assert ans == ((2 * (314159)* (r)) / 100000);
    
    return ans;
}
