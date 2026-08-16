#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(xs + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer j; 0 <= j < (5) ==> (1 <= (xs)[j] && (xs)[j] <= 5) &&
        \exists integer j; 0 <= j < (5) && (xs)[j] == 0);
    ensures 1 <= \result <= 5;
    ensures xs[\result - 1] == 0;
    assigns \nothing;
*/
size_t func(const int *xs) {
    size_t pos = 0;
    bool found = false;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
        \forall integer j; 0 <= j < (5) ==> (1 <= (xs)[j] && (xs)[j] <= 5) &&
        \exists integer j; 0 <= j < (5) && (xs)[j] == 0);
        loop invariant \forall integer k; 0 <= k < i ==> xs[k] != 0;
        loop assigns i, pos, found;
        loop variant 5 - i;
    */
    while (i < 5) {
        if (xs[i] == 0) {
            pos = i;
            found = true;
            break;
        }
        i++;
    }
    
    if (found) {
        //@ assert pos < 5;
        //@ assert xs[pos] == 0;
        return pos + 1;
    } else {
        return 0;
    }
}
