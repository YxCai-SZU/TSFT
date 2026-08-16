#include <stdbool.h>

/*@ requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && 
            (x == 1 ==> \result == 0);
    assigns \nothing;
 */
int func(int x)
{
    int ans;
    
    //@ assert 0 <= x <= 1;
    
    if (x == 0) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert (x == 0 ==> ans == 1) && (x == 1 ==> ans == 0);
    return ans;
}
