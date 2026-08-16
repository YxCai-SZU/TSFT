#include <limits.h>

/*@
    requires (3 <= (a) && (a) <= 20 && 3 <= (b) && (b) <= 20);
    ensures ((\result) == (((a)) + ((a)) - 1) || (\result) == (((b)) + ((b)) - 1) ||
        (\result) == (((a)) + ((b))) || (\result) == (((b)) + ((a)) - 1));
*/
int func(int a, int b) {
    int ans;
    int tmp;

    ans = INT_MIN;

    tmp = a + a - 1;
    //@ assert tmp == ((a) + (a) - 1);
    if (tmp > ans) {
        ans = tmp;
    }

    tmp = b + b - 1;
    //@ assert tmp == ((b) + (b) - 1);
    if (tmp > ans) {
        ans = tmp;
    }

    tmp = a + b;
    //@ assert tmp == ((a) + (b));
    if (tmp > ans) {
        ans = tmp;
    }

    tmp = b + a - 1;
    //@ assert tmp == ((b) + (a) - 1);
    if (tmp > ans) {
        ans = tmp;
    }

    //@ assert ((ans) == (((a)) + ((a)) - 1) || (ans) == (((b)) + ((b)) - 1) ||         (ans) == (((a)) + ((b))) || (ans) == (((b)) + ((a)) - 1));
    return ans;
}
