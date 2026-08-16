#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_array(integer N, int64_t *H) =
        N >= 1 && N <= 20 &&
        \valid(H + (0 .. N-1)) &&
        \forall integer j; 0 <= j < N ==> 1 <= H[j] <= 100;

    logic integer max_in_prefix(integer N, int64_t *H, integer i) =
        i == 0 ? 0 : \max(0, i-1, \lambda integer k; H[k]);
*/

/*@
    requires valid_array(N, H);
    ensures 1 <= \result <= N;
    assigns \nothing;
*/
int64_t func(size_t N, const int64_t *H) {
    int64_t max_h;
    int64_t ans;
    size_t i;

    //@ assert valid_array(N, H);
    max_h = H[0];
    ans = 1;
    i = 1;

    /*@
        loop invariant 1 <= i <= N;
        loop invariant 1 <= ans <= i;
        loop invariant \forall integer k; 0 <= k < i ==> H[k] <= max_h;
        loop invariant valid_array(N, H);
        loop assigns i, ans, max_h;
        loop variant N - i;
    */
    while (i < N) {
        int64_t h = H[i];
        //@ assert 1 <= h <= 100;
        if (max_h <= h) {
            ans += 1;
            max_h = h;
        }
        //@ assert 1 <= ans <= i+1;
        i += 1;
    }
    //@ assert 1 <= ans <= N;
    return ans;
}
