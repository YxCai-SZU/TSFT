#include <stdbool.h>
#include <stdint.h>

/*@
    requires n >= 0;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 0 < (a)[i] && (a)[i] <= 100);
    assigns \nothing;
    ensures \result <= n;
    ensures \result >= 0;
    ensures (\forall integer i; 0 <= i < (n) && i % 2 == 0 && (a)[i] % 2 == 1 ==> (\result) > 0);
*/
unsigned int func(unsigned int n, unsigned int *a) {
    unsigned int res = 0;
    unsigned int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant res <= i;
        loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 && a[j] % 2 == 1 ==> res > 0;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 0 < (a)[i] && (a)[i] <= 100);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int v = a[i];
        //@ assert 0 < v && v <= 100;
        if (i % 2 == 0 && v % 2 == 1) {
            res = res + 1;
        }
        i = i + 1;
    }
    return res;
}
