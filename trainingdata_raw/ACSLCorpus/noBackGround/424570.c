#include <stdint.h>

/*@
  requires 1 <= N && N <= 100;
  requires 1 <= X && X <= 10000;
  requires \valid(L + (0 .. N-1));
  requires \forall integer i; 0 <= i < N ==> 1 <= L[i] && L[i] <= 100;
  ensures \result >= 0 && \result <= N;
*/
int64_t func(int64_t N, int64_t X, int64_t *L)
{
    int64_t d = 0;
    int64_t count = 0;
    int64_t i = 0;
    
    /*@ loop invariant 0 <= i <= N;
        loop invariant d >= 0;
        loop invariant d <= X + 100 * i;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < N ==> 1 <= L[j] && L[j] <= 100;
        loop invariant 1 <= N && N <= 100;
        loop invariant 1 <= X && X <= 10000;
        loop assigns d, count, i;
        loop variant N - i;
    */
    while (d <= X && i < N) {
        //@ assert 0 <= i < N;
        count += 1;
        d += L[i];
        i += 1;
        //@ assert d <= X + 100 * i;
    }
    return count;
}
