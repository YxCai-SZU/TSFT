#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == ((a) + (b)) ||
            \result == ((a) - (b)) ||
            \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) - (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int res;

    sum = a + b;
    diff = a - b;
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;

    if (sum > diff && sum > prod)
    {
        res = sum;
    }
    else if (diff > prod)
    {
        res = diff;
    }
    else
    {
        res = prod;
    }

    //@ assert res >= a + b;
    //@ assert res >= a - b;
    //@ assert res >= a * b;
    //@ assert res == sum || res == diff || res == prod;
    return res;
}
