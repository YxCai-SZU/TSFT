#include <stddef.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == ((n) * 800 - ((((n)) / 15) * 200));
    assigns \nothing;
*/
size_t func(size_t n) {
    size_t ans;
    size_t count;
    size_t temp;
    
    ans = n * 800;
    count = 0;
    temp = n;
    
    /*@
        loop invariant 0 <= temp <= n;
        loop invariant 0 <= count <= n/15;
        loop invariant temp == n - count * 15;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 15) {
        //@ assert temp >= 15;
        temp -= 15;
        count += 1;
    }
    
    //@ assert count == n/15;
    ans -= count * 200;
    
    return ans;
}
