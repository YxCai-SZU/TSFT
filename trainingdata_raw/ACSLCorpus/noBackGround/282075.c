#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    ensures \result >= -1 && \result <= (int)n;
    assigns \nothing;
*/
int func(int n, int *a) {
    int count = 0;
    int x = 0;

    /*@
        loop invariant 0 <= x <= n;
        loop invariant 0 <= count <= x;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
        loop invariant (\forall integer k; 0 <= k < (x) ==> (((a)[k] & 1) != 0) ==> (count) >= 1);
        loop assigns x, count;
        loop variant n - x;
    */
    while (x < n) {
        //@ assert 0 <= x < n;
        if ((a[x] & 1) != 0) {
            //@ assert ((a[x] & 1) != 0) ==> count >= 0;
            count += 1;
        }
        x += 1;
    }

    if ((count & 1) == 0) {
        int tmp_count = 0;
        int y = 0;

        /*@
            loop invariant 0 <= y <= n;
            loop invariant 0 <= tmp_count <= count;
            loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
            loop invariant (\forall integer k; 0 <= k < (y) ==> (((a)[k] & 1) != 0) ==> (tmp_count) >= 1);
            loop assigns y, tmp_count;
            loop variant n - y;
        */
        while (y < n) {
            //@ assert 0 <= y < n;
            if ((a[y] & 1) != 0) {
                //@ assert ((a[y] & 1) != 0) ==> tmp_count >= 0;
                if (tmp_count < count) {
                    tmp_count += 1;
                } else {
                    break;
                }
            }
            y += 1;
        }
        return y;
    } else {
        return -1;
    }
}
