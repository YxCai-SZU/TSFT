#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 20 &&
        1 <= (M) && (M) <= 20 &&
        1 <= (A) && (A) <= (N) &&
        1 <= (B) && (B) <= (M));
    ensures \result == ((((N)) * ((M))) - ((((A)) * ((M))) + (((B)) * ((N))) - (((A)) * ((B)))));
*/
int64_t func(int64_t N, int64_t M, int64_t A, int64_t B)
{
    int64_t result;
    
    //@ assert 1 <= N && N <= 20;
    //@ assert 1 <= M && M <= 20;
    //@ assert 1 <= A && A <= N;
    //@ assert 1 <= B && B <= M;
    
    //@ assert N * M <= 400;
    //@ assert A * M <= 400;
    //@ assert B * N <= 400;
    //@ assert A * B <= 400;
    
    //@ assert N * M >= A * M + B * N - A * B;
    
    result = N * M - (A * M + B * N - A * B);
    return result;
}
