#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000);
    requires n >= 0;
    requires \valid(l + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (l)[i] && (l)[i] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int x, int *l) {
    int d = 0;
    int num = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= d <= x + 100;
        loop invariant 0 <= num <= index;
        loop assigns d, num, index;
        loop variant n - index;
    */
    while (d <= x && index < n) {
        //@ assert 0 <= num < n;
        num += 1;
        //@ assert 1 <= l[index] <= 100;
        d += l[index];
        index += 1;
    }

    //@ assert 0 <= num <= n;
    return num;
}
