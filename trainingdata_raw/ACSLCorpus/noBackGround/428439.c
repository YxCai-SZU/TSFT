#include <stdbool.h>
/*@
    requires (1 <= (N) <= 100 && 1 <= (X) <= 10000);
    requires ((N) == (N) && \forall integer i; 0 <= i < (N) ==> 1 <= (L)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= N;
*/
int func(int N, int X, int *L) {
    int d = 0;
    int count = 0;
    unsigned int i = 0;

    /*@
        loop invariant (0 <= (d) <= (X) + 100 &&
        0 <= (count) <= (i) <= (N) &&
        (i) <= (N) &&
        \forall integer j; 0 <= j < (i) ==> (d) >= (L)[j] &&
        (((N)) == ((N)) && \forall integer i; 0 <= i < ((N)) ==> 1 <= ((L))[i] <= 100) &&
        (1 <= ((N)) <= 100 && 1 <= ((X)) <= 10000) &&
        (count) >= 0);
        loop assigns d, count, i;
        loop variant N - i;
    */
    while (d <= X && i < (unsigned int)N) {
        //@ ghost int old_d = d;
        //@ ghost int old_count = count;
        //@ ghost int old_i = i;

        count += 1;
        d += L[i];
        i += 1;

        //@ assert count == old_count + 1;
    }

    //@ assert count >= 0;
    return count;
}
