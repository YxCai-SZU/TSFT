#include <stdint.h>
#include <stddef.h>

/*@
    predicate a_in_range(int64_t* a, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;

    predicate b_in_range(int64_t* b, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= b[i] <= 1000000000;

    lemma sum_bound:
        \forall integer ai, bi, n;
        0 <= ai <= n && 0 <= bi <= n ==>
        (ai + bi) * 1000000000 >= 0;
*/

/*@
    requires n > 0 && n <= 100000;
    requires \valid_read(a + (0 .. n-1));
    requires \valid_read(b + (0 .. n-1));
    requires a_in_range(a, n);
    requires b_in_range(b, n);
    ensures \result >= 0;
*/
int64_t func(size_t n, const int64_t* a, const int64_t* b) {
    int64_t sum = 0;
    size_t ai = 0;
    size_t bi = 0;

    /*@
        loop invariant 0 <= ai <= n;
        loop invariant 0 <= bi <= n;
        loop invariant sum >= 0;
        loop invariant sum <= (ai + bi) * 1000000000;
        loop invariant a_in_range(a, n);
        loop invariant b_in_range(b, n);
        loop assigns sum, ai, bi;
    */
    while (ai < n && bi < n) {
        int64_t na = a[ai];
        int64_t nb = b[bi];

        if (na < nb) {
            sum += na;
            ai += 1;
        } else if (na > nb) {
            sum += nb;
            bi += 1;
        } else {
            sum += na;
            ai += 1;
            bi += 1;
        }
        //@ assert sum >= 0;
    }

    /*@
        loop invariant 0 <= ai <= n;
        loop invariant 0 <= bi <= n;
        loop invariant sum >= 0;
        loop invariant sum <= (ai + bi) * 1000000000;
        loop invariant a_in_range(a, n);
        loop invariant b_in_range(b, n);
        loop assigns sum, ai;
    */
    while (ai < n) {
        sum += a[ai];
        ai += 1;
        //@ assert sum >= 0;
    }

    /*@
        loop invariant 0 <= ai <= n;
        loop invariant 0 <= bi <= n;
        loop invariant sum >= 0;
        loop invariant sum <= (ai + bi) * 1000000000;
        loop invariant a_in_range(a, n);
        loop invariant b_in_range(b, n);
        loop assigns sum, bi;
    */
    while (bi < n) {
        sum += b[bi];
        bi += 1;
        //@ assert sum >= 0;
    }

    return sum;
}
