#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    ensures \result == ((A) + (B)) || \result == ((A) - (B)) || \result == ((A) * (B));
    ensures \result >= ((A) + (B));
    ensures \result >= ((A) - (B));
    ensures \result >= ((A) * (B));
    assigns \nothing;
*/
int func(int A, int B)
{
    int add;
    int sub;
    int mul;
    int res;

    //@ assert (-100 <= (A) <= 100) && (-100 <= (B) <= 100);
    add = A + B;
    sub = A - B;
    
    //@ assert -10000 <= A * B <= 10000;
    mul = A * B;

    if (add > sub && add > mul)
    {
        res = add;
    }
    else if (sub > mul)
    {
        res = sub;
    }
    else
    {
        res = mul;
    }

    //@ assert res == ((A) + (B)) || res == ((A) - (B)) || res == ((A) * (B));
    //@ assert res >= ((A) + (B));
    //@ assert res >= ((A) - (B));
    //@ assert res >= ((A) * (B));
    return res;
}
