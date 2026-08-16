#include <stdbool.h>

/*@
    requires 0 <= A <= 123;
    requires 0 <= B <= 123;
    requires 0 <= C <= 123;
    requires 0 <= D <= 123;
    requires 0 <= E <= 123;
    requires 0 <= K <= 123;
    requires ((A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    ensures \result == true <==> E - A <= K;
*/
bool func(int A, int B, int C, int D, int E, int K) {
    bool result;
    //@ assert ((A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    result = (E - A) <= K;
    //@ assert result == true <==> E - A <= K;
    return result;
}
