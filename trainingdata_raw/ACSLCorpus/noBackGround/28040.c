#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(v + (0..4));
    requires \forall integer i; 0 <= i < 5 ==> ((v[i]) == (i) + 1 || (v[i]) == 0);
    requires (\exists integer i; (0) <= i < (5) && (v)[i] == 0);
    ensures 1 <= \result <= 5;
    ensures v[\result - 1] == 0;
    assigns \nothing;
*/
unsigned int func(int *v) {
    unsigned int index = 0;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant \forall integer i; 0 <= i < 5 ==> ((v[i]) == (i) + 1 || (v[i]) == 0);
        loop invariant (\exists integer i; (0) <= i < (5) && (v)[i] == 0);
        loop invariant index > 0 ==> (\forall integer i; 0 <= i < (index) ==> (v)[i] != 0);
        loop invariant (\exists integer i; (index) <= i < (5) && (v)[i] == 0);
        loop assigns index;
    */
    while (index < 5) {
        //@ assert index >= 0 && index < 5;
        if (v[index] == 0) {
            //@ assert v[index] == 0;
            //@ assert index + 1 >= 1 && index + 1 <= 5;
            return index + 1;
        }
        //@ assert v[index] != 0;
        index++;
    }
    
    // This point should be unreachable due to preconditions
    //@ assert false;
    return 0;
}
