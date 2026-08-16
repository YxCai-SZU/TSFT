#include <stdbool.h>

/*@
    requires (\valid((v)) &&
        (v)[0] >= 0 && (v)[0] <= 100 &&
        (v)[1] >= 0 && (v)[1] <= 100 &&
        (v)[2] >= 0 && (v)[2] <= 100 &&
        ((v)[0] == 0 || (v)[1] == 0 || (v)[2] == 0));
    ensures \result >= -1 && \result <= 2;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < 3 ==> v[i] != 0);
    ensures \result >= 0 ==> v[\result] == 0;
    assigns \nothing;
*/
int func(int *v) {
    int index;
    int found;
    
    index = 0;
    found = -1;
    
    /*@
        loop invariant 0 <= index <= 3;
        loop invariant found == -1 || (found >= 0 && found < index);
        loop invariant \forall integer i; 0 <= i < index ==> v[i] != 0;
        loop assigns index, found;
        loop variant 3 - index;
    */
    while (index < 3) {
        //@ assert v[index] >= 0 && v[index] <= 100;
        
        if (v[index] == 0) {
            found = index;
            break;
        }
        
        index = index + 1;
    }
    
    return found;
}
