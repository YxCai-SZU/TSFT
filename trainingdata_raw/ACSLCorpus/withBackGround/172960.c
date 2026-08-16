#include <stdbool.h>

/*@
    predicate is_even(integer n) = n % 2 == 0;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires is_even(y);
    ensures \result >= 0;
    ensures (x <= y ==> \result == y - x) && (x > y ==> \result == 0);
*/
int func(int x, int y)
{
    int ans;
    //@ assert is_even(y);
    if (x > y) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = y - x;
        //@ assert ans == y - x;
    }
    return ans;
}
