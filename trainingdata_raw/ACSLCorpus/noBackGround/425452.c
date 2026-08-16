#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int min1;
    int min2;
    int cnt;
    int i;
    int pi;

    min1 = p[0];
    min2 = p[0];
    cnt = 1;
    i = 1;

    /*@
        loop invariant (1 <= (i) <= (n) &&
        1 <= (cnt) <= (i) &&
        (((n)) >= 1 && ((n)) <= 200000 &&
        \valid(((p)) + (0 .. ((n))-1)) &&
        (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((p))[i] <= ((n))) &&
        (\forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j])) &&
        (min1) >= 1 && (min2) >= 1);
        loop assigns i, min1, min2, cnt, pi;
        loop variant n - i;
    */
    while (i < n) {
        pi = p[i];

        //@ assert 1 <= pi <= n;
        if (min1 >= pi) {
            min2 = min1;
            min1 = pi;
            cnt += 1;
        } else if (min2 >= pi) {
            min2 = pi;
            cnt += 1;
        }

        i += 1;
    }

    //@ assert cnt >= 1 && cnt <= n;
    return cnt;
}
