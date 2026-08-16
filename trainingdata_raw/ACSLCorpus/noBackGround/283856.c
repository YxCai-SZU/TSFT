#include <stdbool.h>

/*@ requires \valid(x+(0..4)) && \valid(y+(0..4));
    requires \forall integer i; 0 <= i < 5 ==> x[i] == i + 1;
    requires \forall integer i; 0 <= i < 5 ==> y[i] == i + 1;
    ensures \result == true;
    ensures (\forall integer i; 0 <= i < (5) ==> (x)[i] == (y)[i]);
*/
bool func(int *x, int *y) {
    int i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < 5 ==> x[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < 5 ==> y[j] == j + 1;
        loop invariant \forall integer k; 0 <= k < i ==> x[k] == y[k];
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] != y[i]) {
            return false;
        }
        i++;
    }
    //@ assert i == 5;
    //@ assert (\forall integer i; 0 <= i < (5) ==> (x)[i] == (y)[i]);
    return true;
}
