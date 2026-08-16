#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid(v + (0 .. 1));
    requires ((2) == 2 &&
        1 <= (v)[0] && (v)[0] <= 12 &&
        1 <= (v)[1] && (v)[1] <= 31);
    ensures (((\result) == 1) ? 1 : ((\result) == 0) ? 1 : 0) == 1;
    assigns \nothing;
*/
unsigned int func(unsigned int *v)
{
    unsigned int ans;
    //@ assert ((2) == 2 &&         1 <= (v)[0] && (v)[0] <= 12 &&         1 <= (v)[1] && (v)[1] <= 31);
    
    if (v[0] <= 9) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert (((ans) == 1) ? 1 : ((ans) == 0) ? 1 : 0) == 1;
    return ans;
}
