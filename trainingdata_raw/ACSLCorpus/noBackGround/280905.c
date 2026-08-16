#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (k * 500 >= x);
*/
bool func(int k, int x) {
    bool ans = false;
    int a = 1;

    /*@
        loop invariant 1 <= a <= k + 1;
        loop invariant ((ans) == ( ((a) - 1) <= (k) && 500 * ((a) - 1) >= (x) ));
        loop assigns a, ans;
        loop variant k - a + 1;
    */
    while (a <= k) {
        if (500 * a >= x) {
            ans = true;
        }
        a = a + 1;
    }
    return ans;
}
