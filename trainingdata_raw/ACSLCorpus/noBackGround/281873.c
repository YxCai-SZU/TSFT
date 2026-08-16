#include <stdbool.h>

/*@
    requires \valid(result);
    requires A >= 0 && B >= 0 && C >= 0 && D >= 0 && E >= 0;
    requires A < 123 && B < 123 && C < 123 && D < 123 && E < 123;
    requires K >= 0 && K <= 123;
    requires A <= B && B <= C && C <= D && D <= E;
    assigns *result;
    ensures *result == (E - A <= K);
*/
void func(int A, int B, int C, int D, int E, int K, bool *result)
{
    // Variable declarations at the top
    bool local_result;

    //@ assert ((A) >= 0 && (B) >= 0 && (C) >= 0 && (D) >= 0 && (E) >= 0 &&         (A) < 123 && (B) < 123 && (C) < 123 && (D) < 123 && (E) < 123 &&         (A) <= (B) && (B) <= (C) && (C) <= (D) && (D) <= (E));
    local_result = (E - A) <= K;
    *result = local_result;
}
