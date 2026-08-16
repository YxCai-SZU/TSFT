#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
    ensures \result >= 0 && \result <= n - 1;
    assigns \nothing;
*/
int32_t func(size_t n, int32_t *h) {
    int32_t dist = 0;
    size_t cur = 0;
    size_t next = 1;
    int32_t max_dist = 0;

    // First loop: increasing sequence
    /*@
        loop invariant 0 <= cur < n;
        loop invariant 1 <= next <= n;
        loop invariant dist >= 0;
        loop invariant dist <= next - 1;
        loop invariant next - 1 <= n - 1;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
        loop assigns cur, next, dist;
        loop variant n - next;
    */
    while (next < n) {
        //@ assert 0 <= cur < n && 0 <= next < n;
        if (h[cur] < h[next]) {
            cur = next;
            dist += 1;
        }
        next += 1;
    }
    max_dist = dist;

    // Reset for second loop
    cur = 0;
    next = 1;
    dist = 0;

    // Second loop: decreasing sequence
    /*@
        loop invariant 0 <= cur < n;
        loop invariant 1 <= next <= n;
        loop invariant dist >= 0;
        loop invariant dist <= next - 1;
        loop invariant next - 1 <= n - 1;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
        loop assigns cur, next, dist;
        loop variant n - next;
    */
    while (next < n) {
        //@ assert 0 <= cur < n && 0 <= next < n;
        if (h[cur] > h[next]) {
            cur = next;
            dist += 1;
        }
        next += 1;
    }

    //@ assert dist >= 0 && dist <= n - 1;
    if (dist > max_dist) {
        max_dist = dist;
    }

    //@ assert max_dist >= 0 && max_dist <= n - 1;
    return max_dist;
}
