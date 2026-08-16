#include <stdint.h>

/*@
  requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
      1 <= (C) && (C) <= 20);
  ensures \result >= 0 && \result <= C;
  ensures \result == C - (A - B) || \result == 0;
*/
int32_t func(int32_t A, int32_t B, int32_t C)
{
    int32_t X;
    //@ assert (1 <= (B) && (B) <= (A) && (A) <= 20 &&       1 <= (C) && (C) <= 20);
    X = B + C - A;
    if (X < 0) {
        //@ assert X < 0;
        X = 0;
    } else {
        //@ assert X >= 0;
        //@ assert X <= C;
        //@ assert X == C - (A - B) || X == 0;
    }
    return X;
}
