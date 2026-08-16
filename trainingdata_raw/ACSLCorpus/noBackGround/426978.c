#include <limits.h>

/*@
    requires (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);
    ensures \result == A + C || \result == A + D || \result == B + C || \result == B + D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int min_val;
    int max_val;
    int min2;
    int max2;
    int res;

    //@ assert (1 <= (A) <= 10000) && (1 <= (B) <= 10000) && (1 <= (C) <= 10000) && (1 <= (D) <= 10000);

    min_val = A < B ? A : B;
    max_val = A > B ? A : B;
    min2 = C < D ? C : D;
    max2 = C > D ? C : D;

    //@ assert min_val == ((A) < (B) ? (A) : (B));
    //@ assert max_val == ((A) > (B) ? (A) : (B));
    //@ assert min2 == ((C) < (D) ? (C) : (D));
    //@ assert max2 == ((C) > (D) ? (C) : (D));

    //@ assert (1 <= (min_val) <= 10000);
    //@ assert (1 <= (max2) <= 10000);

    //@ assert min_val + max2 <= 20000;

    res = min_val + max2;

    //@ assert res == ((A) < (B) ? (A) : (B)) + ((C) > (D) ? (C) : (D));

    return res;
}
