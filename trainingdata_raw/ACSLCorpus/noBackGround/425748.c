#include <stdbool.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
    ensures \result >= 0 && \result <= 100;
    ensures \exists integer i; 0 <= i < n && a[i] == \result;
*/
int func(int n, int *a) {
    int best;
    int index;

    best = a[0];
    index = 1;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant \valid(a + (0 .. n-1));
        loop invariant \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
        loop invariant \exists integer i; 0 <= i < index && a[i] == best;
        loop assigns index, best;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (a[index] > best) {
            best = a[index];
        }
        index++;
    }

    //@ assert \exists integer i; 0 <= i < n && a[i] == best;
    return best;
}
