#include <stdbool.h>

/*@
    predicate is_valid_params(integer A, integer B, integer C, integer D, integer E, integer K) =
        0 <= A <= 123 &&
        0 <= B <= 123 &&
        0 <= C <= 123 &&
        0 <= D <= 123 &&
        0 <= E <= 123 &&
        0 <= K <= 123 &&
        A < B &&
        B < C &&
        C < D &&
        D < E;

    logic integer distance(integer A, integer E) = E - A;
*/


bool func(int A, int B, int C, int D, int E, int K)
{
    int dist;

    dist = E - A;

    //@ assert dist == distance(A, E);

    return dist <= K;
}
