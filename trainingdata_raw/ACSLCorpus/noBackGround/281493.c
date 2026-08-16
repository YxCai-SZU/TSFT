#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    int sum;
    int diff;
    int prod;

    sum = a + b;
    diff = a - b;
    prod = a * b;

    //@ assert INT_MIN <= sum <= INT_MAX;
    //@ assert INT_MIN <= diff <= INT_MAX;
    //@ assert -10000 <= prod <= 10000;

    if (sum > diff)
    {
        result = sum;
    }
    else
    {
        result = diff;
    }

    //@ assert result >= sum && result >= diff;

    if (prod > result)
    {
        result = prod;
    }

    //@ assert result >= sum && result >= diff && result >= prod;
    return result;
}
