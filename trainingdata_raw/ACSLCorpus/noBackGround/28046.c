#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 3 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (int)(n));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n - 2;
*/
int func(size_t n, int *p) {
    int cnt = 0;
    size_t index = 1;

    /*@ loop invariant 1 <= index <= n - 1;
        loop invariant cnt >= 0;
        loop invariant cnt <= (int)index - 1;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] <= (int)(n));
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop assigns cnt, index;
        loop variant n - 1 - index;
    */
    while (index < n - 1) {
        int left = p[index - 1];
        int middle = p[index];
        int right = p[index + 1];

        //@ assert left != middle && middle != right && left != right;
        if ((left < middle && middle < right) || (left > middle && middle > right)) {
            cnt += 1;
        }
        index += 1;
    }
    return cnt;
}
