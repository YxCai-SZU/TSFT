#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == (((a + b) >= (b + c) ? (a + b) : (b + c)) >= ((c + d) >= (d + a) ? (c + d) : (d + a)) ?
        ((a + b) >= (b + c) ? (a + b) : (b + c)) : ((c + d) >= (d + a) ? (c + d) : (d + a)));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans;

    //@ assert -10000 <= a * b <= 10000;
    //@ assert -10000 <= b * c <= 10000;
    //@ assert -10000 <= c * d <= 10000;
    //@ assert -10000 <= d * a <= 10000;

    if (a + b > b + c)
        ans = a + b;
    else
        ans = b + c;

    if (ans > c + d)
        ans = ans;
    else
        ans = c + d;

    if (ans > d + a)
        ans = ans;
    else
        ans = d + a;

    //@ assert ans == (((a + b) >= (b + c) ? (a + b) : (b + c)) >= ((c + d) >= (d + a) ? (c + d) : (d + a)) ?         ((a + b) >= (b + c) ? (a + b) : (b + c)) : ((c + d) >= (d + a) ? (c + d) : (d + a)));
    return ans;
}
