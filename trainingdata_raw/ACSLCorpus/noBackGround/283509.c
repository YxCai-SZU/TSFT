#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == ((A) * (B)) || \result == ((C) * (D));
    ensures 1 <= \result <= 100000000;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int S1;
    int S2;
    int ans;

    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000);
    //@ assert ((A) * (B)) <= 100000000;
    S1 = A * B;

    //@ assert (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    //@ assert ((C) * (D)) <= 100000000;
    S2 = C * D;

    if (S1 > S2) {
        ans = S1;
    } else {
        ans = S2;
    }

    //@ assert ans == ((A) * (B)) || ans == ((C) * (D));
    //@ assert ans >= 1;
    //@ assert ans <= 100000000;

    return ans;
}
