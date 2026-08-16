#include <stdbool.h>

/*@
    requires (0 <= (A) && (A) < 124 &&
        0 <= (B) && (B) < 124 &&
        0 <= (C) && (C) < 124 &&
        0 <= (D) && (D) < 124 &&
        0 <= (E) && (E) < 124 &&
        0 <= (K) && (K) <= 123 &&
        (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    ensures \result == (((E) - (A)) <= K);
*/
bool func(unsigned int A, unsigned int B, unsigned int C, 
          unsigned int D, unsigned int E, unsigned int K)
{
    unsigned int dist;
    
    //@ assert A < B && B < C && C < D && D < E;
    dist = E - A;
    //@ assert dist == ((E) - (A));
    return dist <= K;
}
