#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 3 * (r * r) / 10;
*/
uint64_t func(uint64_t r)
{
    // Variable declarations at scope top
    uint64_t pi = 3;
    uint64_t r_squared;
    uint64_t area;
    uint64_t ans = 0;
    uint64_t temp;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert 1 <= r * r <= 10000;
    r_squared = r * r;
    
    //@ assert 3 <= pi * r_squared <= 30000;
    area = pi * r_squared;
    
    temp = area;
    
    /*@
        loop invariant temp >= 0;
        loop invariant ans == (area - temp) / 10;
        loop invariant temp + 10 * ans == area;
        loop assigns temp, ans;
    */
    while (temp >= 10) {
        //@ assert temp >= 10;
        temp -= 10;
        ans += 1;
        //@ assert temp + 10 * ans == area;
    }
    
    //@ assert ans == 3 * (r * r) / 10;
    return ans;
}
