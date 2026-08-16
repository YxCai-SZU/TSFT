#include <stdint.h>


uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t ans;
    uint32_t tmp;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    tmp = b / a;
    //@ assert tmp == b / a;
    
    if (c < tmp) {
        ans = c;
        //@ assert ans == c;
    } else {
        ans = tmp;
        //@ assert ans == b / a;
    }
    
    //@ assert ans <= c;
    //@ assert ans <= b / a;
    //@ assert ans == b / a || ans == c;
    return ans;
}
