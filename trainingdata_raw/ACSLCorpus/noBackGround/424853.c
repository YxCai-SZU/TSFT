#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((ps) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (ps)[i] >= 1 && (ps)[i] <= (n));
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, size_t *ps) {
    size_t ans = 0;
    size_t min = n + 1;
    size_t index = 0;

    /*@
        loop invariant ((index) <= (n) &&
        (ans) <= (index) &&
        (ans) <= (n) &&
        ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (ps)[i] >= 1 && (ps)[i] <= (n)) &&
        \forall integer i; 1 <= i < (n) ==> (ps)[i] >= 1 && (ps)[i] <= (n));
        loop invariant index <= n;
        loop assigns ans, min, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert ((index) <= (n) &&         (ans) <= (index) &&         (ans) <= (n) &&         ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (ps)[i] >= 1 && (ps)[i] <= (n)) &&         \forall integer i; 1 <= i < (n) ==> (ps)[i] >= 1 && (ps)[i] <= (n));
        if (min >= ps[index]) {
            ans += 1;
            min = ps[index];
        }
        index += 1;
    }
    //@ assert ans <= n;
    return ans;
}
