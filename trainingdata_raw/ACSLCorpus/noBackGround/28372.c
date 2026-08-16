#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 3142) / 1000);
*/
int func(int r)
{
    int pi;
    int ans;
    int temp;
    int count;

    pi = 3142;
    ans = 0;
    temp = 2 * r * pi;
    count = 0;

    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi) == 3142 &&
        (temp) >= 0 &&
        (temp) == 2 * (r) * (pi) - 1000 * (count) &&
        (count) >= 0 &&
        (count) <= (2 * (r) * (pi)) / 1000 &&
        (ans) == (count));
        loop assigns temp, ans, count;
        loop variant temp;
    */
    while (temp >= 1000) {
        //@ assert temp >= 1000;
        temp -= 1000;
        ans += 1;
        count += 1;
    }

    //@ assert ans == ((2 * (r) * 3142) / 1000);
    return ans;
}
