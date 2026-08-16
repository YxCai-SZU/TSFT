#include <stdbool.h>

/*@ requires (3 <= (n) <= 100 && 1 <= (a) < (b) < 20);
    requires (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] <= 20);
    requires \valid(p + (0 .. n-1));
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int a, int b, int *p) {
    int count = 0;
    int count_a = 0;
    int count_b = 0;
    int i = 0;

    /*@ loop invariant 0 <= i <= n;
        loop invariant count >= 0 && count <= i;
        loop invariant count_a >= 0 && count_a <= i;
        loop invariant count_b >= 0 && count_b <= i;
        loop invariant (\forall integer j; 0 <= j < (n) ==> 1 <= (p)[j] <= 20);
        loop invariant (3 <= (n) <= 100 && 1 <= (a) < (b) < 20);
        loop invariant count <= n;
        loop invariant count_a <= n;
        loop invariant count_b <= n;
        loop assigns i, count, count_a, count_b;
        loop variant n - i;
    */
    while (i < n) {
        int value = p[i];
        if (value <= a) {
            count++;
            count_a++;
            count_b++;
        } else if (value <= b) {
            count_a++;
        } else {
            count_b++;
        }
        i++;
    }

    int min_val = (count_a < count_b) ? count_a : count_b;
    //@ assert min_val >= 0 && min_val <= n;
    return min_val;
}
