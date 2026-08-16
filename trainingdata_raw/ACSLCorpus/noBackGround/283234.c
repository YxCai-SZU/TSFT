#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) &&
             (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A + B || \result == A + C || \result == A + D ||
            \result == B + C || \result == B + D || \result == C + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int train_fee;
    int bus_fee;
    int result;

    //@ assert A >= 1 && A <= 10000;
    //@ assert B >= 1 && B <= 10000;
    train_fee = (A < B) ? A : B;

    //@ assert C >= 1 && C <= 10000;
    //@ assert D >= 1 && D <= 10000;
    bus_fee = (C < D) ? C : D;

    //@ assert train_fee >= 1 && train_fee <= 10000;
    //@ assert bus_fee >= 1 && bus_fee <= 10000;
    //@ assert train_fee + bus_fee <= 20000;
    result = train_fee + bus_fee;

    return result;
}
