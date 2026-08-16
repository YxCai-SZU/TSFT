#include <limits.h>

/*@
    requires 3 <= a <= 20;
    requires 3 <= b <= 20;
    ensures \result == (((a) * 2 - 1) * 2) || \result == (((b) * 2 - 1) * 2);
    ensures \result >= 0;
*/
int func(int a, int b)
{
    int a_is_odd;
    int b_is_odd;
    int ans;
    int temp;

    a_is_odd = (a & 1) != 0;
    b_is_odd = (b & 1) != 0;

    if (a_is_odd)
    {
        temp = a * 2 - 1;
        //@ assert temp >= 0 && temp <= INT_MAX / 2;
        ans = temp * 2;
    }
    else
    {
        temp = b * 2 - 1;
        //@ assert temp >= 0 && temp <= INT_MAX / 2;
        ans = temp * 2;
    }

    //@ assert ans >= 0 && ans <= INT_MAX;
    return ans;
}
