#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int ans = 1;
    int min_bound = p[0];
    size_t i = 1;

    //@ assert ((n) >= 1 && (n) <= 200000 &&         \valid((p) + (0 .. (n)-1)) &&         (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&         (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    //@ assert 1 <= i && i <= n;
    //@ assert 1 <= ans && ans <= i;
    //@ assert min_bound <= p[0];

    /*@
        loop invariant (1 <= (i) && (i) <= (n) &&
        1 <= (ans) && (ans) <= (i) &&
        (min_bound) <= (p)[0] &&
        (\forall integer k; 0 <= k < (i) ==> (p)[k] >= 1 && (p)[k] <= (n)) &&
        (\forall integer k, j; 0 <= k < j < (i) ==> (p)[k] != (p)[j]) &&
        (((n)) >= 1 && ((n)) <= 200000 &&
        \valid(((p)) + (0 .. ((n))-1)) &&
        (\forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n))) &&
        (\forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j])));
        loop assigns i, ans, min_bound;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        int j = p[i];
        if (j <= min_bound) {
            min_bound = j;
            ans += 1;
        }
        i += 1;

        //@ assert (1 <= (i) && (i) <= (n) &&         1 <= (ans) && (ans) <= (i) &&         (min_bound) <= (p)[0] &&         (\forall integer k; 0 <= k < (i) ==> (p)[k] >= 1 && (p)[k] <= (n)) &&         (\forall integer k, j; 0 <= k < j < (i) ==> (p)[k] != (p)[j]) &&         (((n)) >= 1 && ((n)) <= 200000 &&         \valid(((p)) + (0 .. ((n))-1)) &&         (\forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n))) &&         (\forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j])));
    }

    //@ assert ans >= 1 && ans <= n;
    return ans;
}
