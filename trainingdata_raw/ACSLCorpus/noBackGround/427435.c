#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(xs + (0..4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> (1 <= (xs)[i] && (xs)[i] <= 5) &&
        \exists integer i; 0 <= i < (5) && (xs)[i] == 0);
    ensures \result > 0 && \result <= 5;
    ensures xs[\result - 1] == 0;
    assigns \nothing;
*/
unsigned int func(const int *xs) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer k; 0 <= k < i ==> xs[k] != 0;
        loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (xs[i] == 0) {
            //@ assert xs[i] == 0;
            return (unsigned int)(i + 1);
        }
        //@ assert xs[i] != 0;
        i++;
    }
    //@ assert i == 5;
    return 0;
}
