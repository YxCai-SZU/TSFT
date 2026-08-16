#include <stdbool.h>
#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 50 &&
        0 <= (b) && (b) <= 50 &&
        0 <= (c) && (c) <= 50);
    ensures \result >= 0 && \result <= 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ans = 0;

    //@ assert (0 <= (a) && (a) <= 50 &&         0 <= (b) && (b) <= 50 &&         0 <= (c) && (c) <= 50);
    
    if (a == b && b == c && a > 0) {
        ans = 1;
        //@ assert ans >= 0 && ans <= 2;
    } else if (a != b && b != c && c != a) {
        ans = 0;
        //@ assert ans >= 0 && ans <= 2;
    } else {
        ans = 2;
        //@ assert ans >= 0 && ans <= 2;
    }

    //@ assert ans >= 0 && ans <= 2;
    return ans;
}
