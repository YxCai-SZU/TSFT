#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(x+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 5);
    requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures \result > 0;
    ensures \result <= 5;
    assigns \nothing;
*/
unsigned int func(int *x) {
    unsigned int pos = 0;
    bool found = false;
    unsigned int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < (5) ==> 1 <= (x)[i] && (x)[i] <= 5);
        loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant i > 0 ==> (!found ==> \forall integer j; 0 <= j < i ==> x[j] != 0);
        loop invariant found ==> pos > 0 && pos <= 5;
        loop assigns i, pos, found;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            pos = i + 1;
            found = true;
            break;
        }
        i++;
    }
    
    if (found) {
        //@ assert pos > 0 && pos <= 5;
        return pos;
    } else {
        //@ assert false;
        return 0;
    }
}

int main() {
    return 0;
}
