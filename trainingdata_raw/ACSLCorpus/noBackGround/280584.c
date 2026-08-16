#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 20 && (v) >= 1 && (v) <= 50);
    requires \valid_read(c + (0 .. n-1));
    requires \valid_read(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (c)[i] >= 1 && (c)[i] <= 50);
    requires (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= 50);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int v, int *c, int *p) {
    int sum = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= i * 50;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (c)[i] >= 1 && (c)[i] <= 50);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= 50);
        loop invariant ((n) >= 1 && (n) <= 20 && (v) >= 1 && (v) <= 50);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (v < c[i]) {
            i++;
            continue;
        }
        //@ assert p[i] >= 1 && p[i] <= 50;
        sum += p[i];
        //@ assert sum >= 0;
        i++;
    }
    return sum;
}
