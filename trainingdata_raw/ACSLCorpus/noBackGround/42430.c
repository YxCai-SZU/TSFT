#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(x + (0..4));
    requires \forall integer i; 0 <= i < 5 ==> ((x[i]) == 0 || (x[i]) == 1 || (x[i]) == 2 || (x[i]) == 3 || (x[i]) == 4);
    requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures \result > 0 && \result < 6;
    ensures x[\result - 1] == 0;
    assigns \nothing;
*/
unsigned int func(int *x) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (x)[k] != 0);
        loop invariant \forall integer j; 0 <= j < 5 ==> ((x[j]) == 0 || (x[j]) == 1 || (x[j]) == 2 || (x[j]) == 3 || (x[j]) == 4);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            //@ assert x[i] == 0;
            //@ assert i + 1 > 0 && i + 1 < 6;
            return (unsigned int)(i + 1);
        }
        //@ assert x[i] != 0;
        i++;
    }
    return 0;
}

int main() {
    return 0;
}
