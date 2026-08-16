#include <limits.h>

/*@
    requires a >= 0 && b >= 0 && c >= 0 && k >= 1;
    requires k <= a + b + c;
    requires a + b + c <= 2000000000;
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;

    if (a >= k)
    {
        ans = k;
    }
    else if (a + b >= k)
    {
        ans = a;
    }
    else
    {
        ans = a - (k - a - b);
    }

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 &&         (k) <= (a) + (b) + (c) &&         (a) + (b) + (c) <= 2000000000);
    //@ assert ans == ((a) >= (k) ? (k) :         (a) + (b) >= (k) ? (a) :         (a) - ((k) - (a) - (b)));
    //@ assert ans >= -c;
    //@ assert ans <= a;

    return ans;
}
