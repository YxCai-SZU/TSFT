#include <limits.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
long func(long A, long B, long C, long D)
{
    long AB;
    long CD;
    long res;

    //@ assert (-10000 <= (A * B) <= 10000);
    AB = A * B;

    //@ assert (-10000 <= (C * D) <= 10000);
    CD = C * D;

    //@ assert AB >= A * B;
    //@ assert CD >= C * D;

    if (AB > CD)
    {
        res = AB;
    }
    else
    {
        res = CD;
    }

    //@ assert res == AB || res == CD;
    //@ assert res >= AB && res >= CD;
    return res;
}
