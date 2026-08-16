#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 100000 &&
     1 <= (k) && (k) <= (n) + 1);
    ensures \result >= 0 && \result <= n;
    ensures \result == ((n) - (k) + 1);
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t ans;
    
    //@ assert (1 <= (n) && (n) <= 100000 &&      1 <= (k) && (k) <= (n) + 1);
    ans = n - k + 1;
    //@ assert ans == ((n) - (k) + 1);
    
    if (ans < 0) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        //@ assert ans == ((n) - (k) + 1);
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    //@ assert ans == ((n) - (k) + 1);
    return ans;
}
