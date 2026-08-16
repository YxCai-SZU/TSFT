#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == 1 ==> ((n) % 100 <= 5 * ((n) / 100));
    ensures \result == 0 ==> ((n) % 100 > 5 * ((n) / 100));
    ensures \result == 0 || \result == 1;
*/
int func(int n)
{
    int x;
    int y;
    int ans;

    x = n / 100;
    y = n % 100;

    //@ assert y <= 5 * x || y > 5 * x;

    if (y <= 5 * x) {
        ans = 1;
    } else {
        ans = 0;
    }

    return ans;
}
