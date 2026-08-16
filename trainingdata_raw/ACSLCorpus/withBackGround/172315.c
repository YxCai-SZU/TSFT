#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(int *arr, size_t n) =
        n > 0 && n <= 100000 &&
        \valid(arr + (0 .. n-1)) &&
        \forall size_t i; 0 <= i < n ==> 1 <= arr[i] <= 1000000000;

    logic integer max(integer a, integer b) =
        a >= b ? a : b;

    lemma dist_max_bounds:
        \forall integer n, integer dist_max;
        n > 0 && dist_max >= 0 && dist_max <= n ==> dist_max <= n;
*/

/*@
    requires valid_array(h, n);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, int *h) {
    int dist_max = 0;
    int dist = 0;
    int prev = 0;
    size_t i = 0;

    //@ ghost size_t initial_n = n;
    //@ assert n > 0 && n <= 100000;

    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant 0 <= dist <= (int)i;
        loop invariant 0 <= dist_max <= (int)i;
        loop invariant valid_array(h, initial_n);
        loop assigns i, dist, dist_max, prev;
        loop variant n-1-i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < initial_n-1;
        //@ assert 1 <= h[i] <= 1000000000;
        //@ assert 1 <= h[i+1] <= 1000000000;

        int old_dist = dist;

        if (h[i] < h[i + 1]) {
            dist = 0;
            //@ assert dist == 0;
        } else {
            dist += 1;
            //@ assert dist == old_dist + 1;
        }

        //@ assert dist >= 0;
        //@ assert dist <= (int)(i+1);

        int old_dist_max = dist_max;

        if (dist > dist_max) {
            dist_max = dist;
            //@ assert dist_max == dist;
        }

        //@ assert dist_max >= old_dist_max;
        //@ assert dist_max <= (int)(i+1);

        prev = h[i];
        i += 1;
    }

    //@ assert i == n-1;
    //@ assert 0 <= dist_max <= (int)(n-1);
    //@ assert dist_max <= (int)n;
    return dist_max;
}
