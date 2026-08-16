#include <stdint.h>

/*@ requires 1 <= a <= 9;
    @ requires 1 <= b <= 9;
    @ requires 1 <= c <= 9;
    @ ensures \result >= 1;
    @ ensures \result <= 5;
    @ ensures \result == 1 || \result == 2 || \result == 3 || \result == 4 || \result == 5;
    @ assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c) {
    int64_t p;
    int64_t ans;
    
    p = a;
    
    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);
    
    if (b > p) {
        p = b;
    }
    
    if (c > p) {
        p = c;
    }
    
    //@ assert p <= 9;
    //@ assert p + 2 <= 11;
    
    ans = p + 2;
    
    if (ans > 5) {
        //@ assert ans >= 6;
        //@ assert ans <= 11;
        return 5;
    } else {
        //@ assert ans >= 3;
        //@ assert ans <= 5;
        return ans;
    }
}
