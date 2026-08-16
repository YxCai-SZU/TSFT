#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000) && (1 <= (b) <= 1000) &&
             (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
    ensures \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d;
*/
int func(int a, int b, int c, int d) {
    int ans[4];
    int max_val;
    int i;

    ans[0] = a + c;
    ans[1] = a + d;
    ans[2] = b + c;
    ans[3] = b + d;

    max_val = ans[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_val == ans[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= ans[k];
        loop invariant (1 <= (a) <= 1000) && (1 <= (b) <= 1000) &&
                      (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
        loop assigns i, max_val;
    */
    while (i < 4) {
        //@ assert 0 <= i < 4;
        if (ans[i] > max_val) {
            max_val = ans[i];
        }
        i += 1;
    }

    //@ assert \exists integer j; 0 <= j < 4 && max_val == ans[j];
    return max_val;
}
