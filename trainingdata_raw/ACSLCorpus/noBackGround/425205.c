#include <stdbool.h>

/*@ requires (1 <= (N) <= 100 && 0 <= (M) <= (N));
    ensures \result == (N == M);
    assigns \nothing;
*/
bool func(int N, int M) {
    //@ assert N == M ==> N == M;
    return N == M;
}

/*@ requires (\valid((A)) && \valid((A)+1) &&
      1 <= (A)[0] <= 100 && 0 <= (A)[1] <= (A)[0]);
    ensures \result == ((A)[0] - (A)[1]);
    assigns \nothing;
*/
int func2(int *A) {
    int N = A[0];
    int M = A[1];
    //@ assert N == A[0] && M == A[1];
    return N - M;
}
