#include <stdbool.h>
#include <limits.h>

/*@ requires 1 <= n && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *p) {
    int min = INT_MAX;
    int count = 0;
    int index = 0;

    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant 1 <= n <= 200000;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
        loop assigns min, count, index;
        loop variant n - index;
    */
    while (index < n) {
        int num = p[index];
        if (min >= num) {
            count++;
            min = num;
        }
        index++;
        //@ assert index <= n;
    }
    return count;
}
