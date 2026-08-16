#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(integer N, int *A) =
        N > 0 && N <= 200000 &&
        \valid(A + (0 .. N-1)) &&
        \forall integer j; 0 <= j < N ==> A[j] > 0 && A[j] <= 1000000000;
*/

/*@
    requires valid_array(N, A);
    ensures \result >= 0 && \result <= N;
    ensures \forall integer i; 0 <= i < N ==> 
            (i + 1) % 2 == 0 && A[i] % 2 == 0 ==> \result > 0;
    assigns \nothing;
*/
size_t func(size_t N, const int *A) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant ans >= 0 && ans <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (j + 1) % 2 == 0 && A[j] % 2 == 0 ==> ans > 0;
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N) {
        if ((i + 1) % 2 == 0) {
            int a = A[i];
            if (a % 2 == 0) {
                ans += 1;
            }
        }
        i += 1;
    }
    return ans;
}
