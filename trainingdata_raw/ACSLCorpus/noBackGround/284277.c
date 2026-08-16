#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000) && (1 <= (b) <= 1000) && (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    ensures \result >= 2;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int ans;

    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }

    if (c > d) {
        max2 = c;
    } else {
        max2 = d;
    }

    ans = max1 + max2;

    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    //@ assert ans >= 2;

    return ans;
}

/*@
    requires (1 <= (x) <= 1000) && (1 <= (y) <= 1000) && ((y) % 2 == 0);
    ensures \result == x + y / 2;
    ensures \result >= 1;
    assigns \nothing;
*/
int func2(int x, int y)
{
    int half_y;
    int i;

    half_y = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= y;
        loop invariant half_y * 2 == i;
        loop invariant (1 <= (x) <= 1000) && (1 <= (y) <= 1000) && ((y) % 2 == 0);
        loop assigns half_y, i;
        loop variant y - i;
    */
    while (i < y)
    {
        half_y += 1;
        i += 2;
    }

    int ans = x + half_y;

    //@ assert ans == x + y / 2;
    //@ assert ans >= 1;

    return ans;
}
