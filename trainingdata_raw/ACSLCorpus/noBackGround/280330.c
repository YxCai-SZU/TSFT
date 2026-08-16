#include <stdbool.h>
#include <stddef.h>

/*@
    requires (3 <= (N) <= 20);
    requires (\valid((p) + (0 .. (N)-1)));
    requires (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N));
    requires (\forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
    ensures \result >= 0;
    ensures \result <= N-2;
    assigns \nothing;
*/
long func(long N, const long *p) {
    long ans = 0;
    long i = 1;

    /*@
        loop invariant 1 <= i <= N-1;
        loop invariant ans >= 0;
        loop invariant ans <= i-1;
        loop assigns ans, i;
        loop variant N-i;
    */
    while (i < N - 1) {
        //@ assert 0 <= i-1 < N && 0 <= i < N && 0 <= i+1 < N;
        
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            ans += 1;
        }
        if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
