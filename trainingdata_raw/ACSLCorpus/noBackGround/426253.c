#include <limits.h>

/*@
    requires (-10000 <= (A) <= 10000) && (-10000 <= (B) <= 10000) && (-10000 <= (C) <= 10000) && (-10000 <= (D) <= 10000);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
long func(long A, long B, long C, long D)
{
    long s1;
    long s2;
    long res;

    //@ assert A >= -10000 && A <= 10000;
    //@ assert B >= -10000 && B <= 10000;
    //@ assert C >= -10000 && C <= 10000;
    //@ assert D >= -10000 && D <= 10000;
    //@ assert A * B >= -1000000000 && A * B <= 1000000000;
    //@ assert C * D >= -1000000000 && C * D <= 1000000000;

    s1 = A * B;
    s2 = C * D;

    if (s1 >= s2)
    {
        res = s1;
    }
    else
    {
        res = s2;
    }

    return res;
}
