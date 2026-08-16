#include <stdbool.h>

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures ((x) < (a)) ==> \result == 0;
    ensures ((x) >= (a)) ==> \result == 10;
*/
int func(int x, int a)
{
    int ans;
    //@ assert 0 <= x <= 9 && 0 <= a <= 9;
    
    if (x < a) {
        ans = 0;
    } else {
        ans = 10;
    }
    
    //@ assert (x < a ==> ans == 0) && (x >= a ==> ans == 10);
    return ans;
}
