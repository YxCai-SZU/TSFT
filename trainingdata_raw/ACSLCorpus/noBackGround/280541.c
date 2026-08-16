#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((N) >= 1 && (N) <= 100 &&
    (X) >= 1 && (X) <= 10000 &&
    \valid((L)+(0..(N)-1)) &&
    \forall integer i; 0 <= i < (N) ==> (L)[i] >= 1 && (L)[i] <= 100);
    ensures \result >= 0 && \result <= (int)N;
    assigns \nothing;
*/
int func(size_t N, long long X, const long long *L) {
    long long d = 0;
    int count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant 0 <= count <= (int)i <= (int)N;
        loop invariant d <= X + 100;
        loop invariant \forall integer j; 0 <= j < i ==> L[j] >= 1 && L[j] <= 100;
        loop invariant d >= 0;
        loop assigns d, count, i;
        loop variant N - i;
    */
    while (d <= X && i < N) {
        //@ assert 0 <= i < N;
        count += 1;
        d += L[i];
        i += 1;
    }
    
    //@ assert count >= 0 && count <= (int)N;
    return count;
}
