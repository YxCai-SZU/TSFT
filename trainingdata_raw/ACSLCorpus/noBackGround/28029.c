#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == (((a + b) >= (a - b) && (a + b) >= (a * b)) ? (a + b) :
        ((a - b) >= (a + b) && (a - b) >= (a * b)) ? (a - b) : (a * b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int add;
    int sub;
    int mul;
    int result;

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert a * b >= -10000 && a * b <= 10000;

    add = a + b;
    sub = a - b;
    mul = a * b;

    //@ assert mul >= -10000 && mul <= 10000;

    if (add > sub)
    {
        if (add > mul)
        {
            result = add;
        }
        else
        {
            result = mul;
        }
    }
    else
    {
        if (sub > mul)
        {
            result = sub;
        }
        else
        {
            result = mul;
        }
    }

    //@ assert result >= add && result >= sub && result >= mul;
    return result;
}
