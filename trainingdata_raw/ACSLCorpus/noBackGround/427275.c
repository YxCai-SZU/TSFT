#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 &&
        1 <= (m) <= 1000 &&
        0 <= (k) <= (n) * (m));
    ensures \result == (k % 2 == (n * m) % 2);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    bool ans = true;
    unsigned int remaining = k;
    
    //@ assert n * m <= 1000000;
    
    if ((n * m) % 2 != k % 2) {
        ans = false;
    } else {
        unsigned int count = 0;
        
        /*@
            loop invariant 0 <= remaining <= k;
            loop invariant 0 <= count <= k / 2;
            loop invariant remaining == k - 2 * count;
            loop invariant ans == (k % 2 == (n * m) % 2);
            loop assigns remaining, count;
            loop variant remaining;
        */
        while (remaining >= 2) {
            //@ assert remaining >= 2;
            remaining -= 2;
            count += 1;
        }
    }
    
    //@ assert ans == (k % 2 == (n * m) % 2);
    return ans;
}
