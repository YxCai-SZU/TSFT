#include <stdbool.h>

/*@
    requires 0 <= A < B < C < D < E <= 123;
    requires 0 <= K <= 123;
    ensures \result == true <==> E - A <= K;
    ensures \result == false <==> E - A > K;
*/
bool func(int A, int B, int C, int D, int E, int K)
{
    int diff;

    //@ assert 0 <= A && A < B && B < C && C < D && D < E && E <= 123;
    //@ assert 0 <= K && K <= 123;

    if (E > A) {
        diff = E - A;
    } else {
        diff = A - E;
    }

    //@ assert diff == (E > A ? E - A : A - E);

    if (diff <= K) {
        //@ assert (((E) > (A) ? (E) - (A) : (A) - (E)) <= (K));
        return true;
    } else {
        //@ assert !(((E) > (A) ? (E) - (A) : (A) - (E)) <= (K));
        return false;
    }
}
