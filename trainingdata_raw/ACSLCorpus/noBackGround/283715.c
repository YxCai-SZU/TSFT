#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 1 <= x < y <= 1000;
    requires \valid(x_values + (0 .. n-1));
    requires \valid(y_values + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= (x_values)[i] <= 1000 && (x_values)[i] != (x)));
    requires (\forall integer i; 0 <= i < (m) ==> (1 <= (y_values)[i] <= 1000 && (y_values)[i] != (y)));
    ensures \result >= 0;
    ensures \result <= n + m;
*/
int func(int n, int m, int x, int y, int *x_values, int *y_values) {
    int count_x = 0;
    int count_y = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count_x <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= (x_values)[i] <= 1000 && (x_values)[i] != (x)));
        loop assigns i, count_x;
    */
    while (i < n) {
        int xi = x_values[i];
        //@ assert 1 <= xi <= 1000 && xi != x;
        if (xi > x && xi < y) {
            count_x += 1;
        }
        i += 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= count_y <= i;
        loop invariant (\forall integer i; 0 <= i < (m) ==> (1 <= (y_values)[i] <= 1000 && (y_values)[i] != (y)));
        loop assigns i, count_y;
    */
    while (i < m) {
        int yj = y_values[i];
        //@ assert 1 <= yj <= 1000 && yj != y;
        if (yj > x && yj < y) {
            count_y += 1;
        }
        i += 1;
    }

    int min_count = (count_x < count_y) ? count_x : count_y;
    //@ assert min_count <= ((n) + (m));
    return min_count;
}
