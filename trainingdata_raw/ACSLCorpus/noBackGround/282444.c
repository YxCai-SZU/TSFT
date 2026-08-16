#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(a + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == (a[0] < a[1] && a[1] < a[2]);
*/
bool func(int *a, size_t len) {
    if (len < 3) {
        return false;
    }
    if (a[0] < a[1] && a[1] < a[2]) {
        return true;
    } else {
        size_t i = 0;
        /*@
            loop invariant 0 <= i <= len-1;
            loop invariant len >= 3;
            loop invariant (\forall integer k; (0) <= k < (i) ==> (a)[k] < (a)[k+1]);
            loop invariant !(a[0] < a[1] && a[1] < a[2]);
            loop assigns i;
            loop variant len-1-i;
        */
        while (i < len - 1) {
            //@ assert i < len-1;
            if (a[i] >= a[i + 1]) {
                return false;
            }
            i++;
        }
        return true;
    }
}
