#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(x + (0 .. 4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> ((x)[i] == i + 1 || (x)[i] == 0) &&
    \exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures \result > 0 && \result <= 5;
    ensures x[\result - 1] == 0;
    assigns \nothing;
*/
unsigned long func(unsigned long* x) {
    size_t i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> ((x)[i] == i + 1 || (x)[i] == 0) &&
    \exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (x)[k] != 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            //@ assert x[i] == 0;
            return (unsigned long)(i + 1);
        }
        //@ assert x[i] != 0;
        i++;
    }
    return 0;
}
