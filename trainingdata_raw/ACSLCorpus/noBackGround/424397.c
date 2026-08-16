#include <stdbool.h>

/*@
    requires 0 <= A && A < B && B < C && C < D && D < E && E <= 123;
    requires 0 <= K && K <= 123;
    ensures \result == (E - A <= K);
*/
bool func(int A, int B, int C, int D, int E, int K)
{
    int ans = 0;
    int max_val;

    //@ assert (0 <= (A) && (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E) && (E) <= 123);

    if (A < B)
    {
        //@ assert A < B;
        ans += B - A;
    }

    if (B < C)
    {
        //@ assert B < C;
        ans += C - B;
    }

    if (C < D)
    {
        //@ assert C < D;
        ans += D - C;
    }

    if (D < E)
    {
        //@ assert D < E;
        ans += E - D;
    }

    //@ assert ans == (((A) < (B) ? (B) - (A) : 0) +         ((B) < (C) ? (C) - (B) : 0) +         ((C) < (D) ? (D) - (C) : 0) +         ((D) < (E) ? (E) - (D) : 0));

    if (E - A > ans)
    {
        max_val = E - A;
    }
    else
    {
        max_val = ans;
    }

    //@ assert max_val == E - A || max_val == ans;

    return max_val <= K;
}
