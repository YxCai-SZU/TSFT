#include <stdbool.h>

/*@
    requires (0 <= (A) <= 123) && (0 <= (B) <= 123) && (0 <= (C) <= 123) && (0 <= (D) <= 123) && (0 <= (E) <= 123) && (0 <= (K) <= 123);
    requires ((A) < (B) < (C) < (D) < (E));
    ensures \result == true <==> (B - A <= K || C - A <= K || D - A <= K || E - A <= K);
*/
bool func(int A, int B, int C, int D, int E, int K)
{
    bool ans = false;

    //@ assert B >= A;
    //@ assert C >= A;
    //@ assert D >= A;
    //@ assert E >= A;

    if (B - A <= K)
    {
        ans = true;
    }
    else if (C - A <= K)
    {
        ans = true;
    }
    else if (D - A <= K)
    {
        ans = true;
    }
    else if (E - A <= K)
    {
        ans = true;
    }

    //@ assert ans == true <==> (B - A <= K || C - A <= K || D - A <= K || E - A <= K);
    return ans;
}
