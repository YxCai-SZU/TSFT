#include <stdbool.h>
/*@
    requires \valid(x + (0..4));
    requires (\forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 5);
    requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures 1 <= \result <= 5;
    ensures x[\result - 1] == 0;
    assigns \nothing;
*/
int func(int* x) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 5);
        loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant \forall integer j; 0 <= j < i ==> x[j] != 0;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            //@ assert x[i] == 0;
            return i + 1;
        }
        //@ assert 1 <= x[i] && x[i] <= 5;
        i++;
    }
    return -1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
