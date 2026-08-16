#include <stdbool.h>

/*@
    requires 1 <= l <= r <= 100;
    requires 1 <= d <= 100;
    ensures \result >= 0;
    ensures \result <= r - l + 1;
*/
int func(int l, int r, int d) {
    int count;
    int i;
    int temp;
    bool is_multiple;

    count = 0;
    i = l;

    /*@
        loop invariant l <= i <= r + 1;
        loop invariant count >= 0;
        loop invariant count <= i - l;
        loop invariant 1 <= l <= r <= 100;
        loop invariant 1 <= d <= 100;
        loop assigns i, count, temp, is_multiple;
        loop variant r - i + 1;
    */
    while (i <= r) {
        is_multiple = false;
        temp = i;

        /*@
            loop invariant 1 <= d <= 100;
            loop invariant temp >= 0;
            loop invariant temp <= i;
            loop invariant 1 <= l <= r <= 100;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= d) {
            temp -= d;
        }

        if (temp == 0) {
            is_multiple = true;
        }

        if (is_multiple) {
            count += 1;
        }

        i += 1;
    }

    return count;
}
