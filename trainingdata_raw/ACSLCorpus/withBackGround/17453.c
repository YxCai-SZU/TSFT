#include <stdbool.h>

/*@
    predicate sorted_params(integer A, integer B, integer C, integer D, integer E) =
        A < B && B < C && C < D && D < E;
*/

/*@
    logic integer distance(integer A, integer E) = E - A;
*/

/*@
    lemma dist_non_negative:
        \forall integer A, E; A <= E ==> distance(A, E) >= 0;
*/

/*@
    requires 0 <= A <= 123 && 0 <= B <= 123 && 0 <= C <= 123 && 0 <= D <= 123 && 0 <= E <= 123;
    requires sorted_params(A, B, C, D, E);
    requires 0 <= K <= 123;
    ensures \result == (E - A <= K);
*/
bool func(unsigned long long A, unsigned long long B, unsigned long long C,
          unsigned long long D, unsigned long long E, unsigned long long K)
{
    unsigned long long dist;
    bool result;

    //@ assert A <= 123 && B <= 123 && C <= 123 && D <= 123 && E <= 123;
    //@ assert A < B && B < C && C < D && D < E;
    //@ assert 0 <= K <= 123;

    dist = E - A;
    //@ assert dist == distance(A, E);

    if (dist <= K)
    {
        //@ assert dist <= K;
        result = true;
    }
    else
    {
        //@ assert dist > K;
        result = false;
    }

    //@ assert result == (E - A <= K);
    return result;
}
