#include <stdbool.h>

/*@
    predicate is_positive(integer x) = x > 30;
    predicate is_non_positive(integer x) = x <= 30;
*/

/*@
    requires -40 <= x <= 40;
    requires x != 40;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> x > 30;
    ensures \result == 0 ==> x <= 30;
*/
int func(int x)
{
    int ans;
    
    //@ assert -40 <= x <= 40;
    //@ assert x != 40;
    
    if (x > 30) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans == 0 || ans == 1;
    //@ assert ans == 1 ==> x > 30;
    //@ assert ans == 0 ==> x <= 30;
    
    return ans;
}

int main()
{
    return 0;
}
