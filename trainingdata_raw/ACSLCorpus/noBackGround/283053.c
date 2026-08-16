#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int add;
    int sub;
    int mul;
    int ans;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    add = a + b;
    //@ assert add == ((a) + (b));
    sub = a - b;
    //@ assert sub == ((a) - (b));
    //@ assert -10000 <= a * b <= 10000;
    mul = a * b;
    //@ assert mul == ((a) * (b));
    ans = add;

    if (sub > ans)
    {
        ans = sub;
    }
    //@ assert ans >= ((a) + (b)) && ans >= ((a) - (b));
    if (mul > ans)
    {
        ans = mul;
    }
    //@ assert ans >= ((a) + (b)) && ans >= ((a) - (b)) && ans >= ((a) * (b));
    //@ assert ans == ((a) + (b)) || ans == ((a) - (b)) || ans == ((a) * (b));
    return ans;
}
