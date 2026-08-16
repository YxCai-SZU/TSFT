#include <stdbool.h>
#include <stddef.h>

/*@
    requires n >= 3 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *p) {
    int result = 0;
    int max = p[0];
    int min = p[0];
    size_t j = 1;

    /*@
        loop invariant 1 <= j <= n;
        loop invariant 0 <= result <= (int)j;
        loop invariant max >= min;
        loop invariant 1 <= min <= max <= n;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (n));
        loop assigns result, max, min, j;
        loop variant n - j;
    */
    while (j < (size_t)n) {
        //@ assert p[j] <= max && p[j] <= min ==> result + 1 >= 0;
        if (p[j] <= max && p[j] <= min) {
            result += 1;
        }
        if (p[j] > max) {
            max = p[j];
        }
        if (p[j] < min) {
            min = p[j];
        }
        j += 1;
    }
    return result;
}
