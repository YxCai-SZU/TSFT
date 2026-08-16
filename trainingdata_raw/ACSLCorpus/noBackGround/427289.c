#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= (n));
    ensures -1 <= \result <= n-1;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    size_t i = 0;
    size_t break_count = 0;
    size_t count = 0;
    int ans = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= break_count <= i;
        loop invariant 0 <= count <= i;
        loop invariant break_count <= ((i) > 0 ? (i) - (count) : 0);
        loop assigns i, break_count, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] == (int)(count + 1)) {
            count++;
        } else {
            break_count++;
        }
        i++;
    }

    if (count == 0) {
        ans = -1;
    } else {
        ans = (int)break_count;
    }

    //@ assert -1 <= ans <= (int)n-1;
    return ans;
}
