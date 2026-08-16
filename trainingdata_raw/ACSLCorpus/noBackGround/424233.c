#include <limits.h>

/*@
    requires ((x) >= 0) && ((y) >= 0) && ((x) + (y) <= INT_MAX);
    ensures \result == x + y;
    assigns \nothing;
*/
int func(int x, int y) {
    int sum = x + y;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= sum;
        loop invariant ((x) >= 0) && ((y) >= 0) && ((x) + (y) <= INT_MAX);
        loop invariant sum == x + y;
        loop assigns i;
        loop variant sum - i;
    */
    while (i < sum) {
        i = i + 1;
    }
    
    //@ assert sum == x + y;
    return sum;
}
