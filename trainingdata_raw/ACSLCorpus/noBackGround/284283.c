#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(v + (0 .. 4));
    requires \forall integer i; 0 <= i < 5 ==> ((v[i]) == (i) + 1 || (v[i]) == 0);
    requires \exists integer i; 0 <= i < 5 && v[i] == 0;
    ensures \result > 0 && \result < 6;
    ensures v[\result - 1] == 0;
    assigns \nothing;
*/
size_t func(const size_t v[5]) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\exists integer j; 0 <= j < (5) && (v)[j] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (v)[k] != 0);
        loop invariant \forall integer j; 0 <= j < 5 ==> ((v[j]) == (j) + 1 || (v[j]) == 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            //@ assert i + 1 > 0 && i + 1 < 6;
            //@ assert v[(i + 1) - 1] == 0;
            return i + 1;
        }
        //@ assert v[i] != 0;
        i += 1;
    }
    
    return 0;
}

int main() {
    return 0;
}
