#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 2 ==> (((a) == (b) && (b) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (b) != (a)));
    ensures \result == 3 ==> ((a) != (b) && (b) != (c) && (a) != (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;

    if (a == b && b == c) {
        ans = 1;
        //@ assert ((a) == (b) && (b) == (c));
    } else if (a == b || a == c || b == c) {
        ans = 2;
        //@ assert (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (b) != (a)));
    } else {
        ans = 3;
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
    }

    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
