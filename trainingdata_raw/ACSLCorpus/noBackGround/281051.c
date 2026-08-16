#include <stdbool.h>

/*@
    requires 0 <= A < 124 && 0 <= B < 124 && 0 <= C < 124 && 
             0 <= D < 124 && 0 <= E < 124 && 0 <= K < 124;
    requires ((A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    ensures \result == (E - A <= K);
*/
bool func(unsigned int A, unsigned int B, unsigned int C, 
          unsigned int D, unsigned int E, unsigned int K)
{
    //@ assert A < 124 && B < 124 && C < 124 && D < 124 && E < 124 && K < 124;
    //@ assert A < B && B < C && C < D && D < E;
    return (E - A) <= K;
}
