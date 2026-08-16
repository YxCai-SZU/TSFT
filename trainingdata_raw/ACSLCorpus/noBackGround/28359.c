#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(xs + (0 .. 4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> ((xs)[i] == 0 || (xs)[i] == i + 1) &&
    \exists integer i; 0 <= i < (5) && (xs)[i] == 0);
    ensures \result > 0;
    ensures \result <= 5;
    assigns \nothing;
*/
size_t func(int* xs) {
    size_t pos = 0;
    bool found = false;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> ((xs)[i] == 0 || (xs)[i] == i + 1) &&
    \exists integer i; 0 <= i < (5) && (xs)[i] == 0);
        loop invariant i > 0 ==> (!found ==> \forall integer j; 0 <= j < i ==> xs[j] != 0);
        loop invariant found ==> pos < 5;
        loop invariant found ==> xs[pos] == 0;
        loop assigns i, pos, found;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (xs[i] == 0) {
            pos = i;
            found = true;
            break;
        }
        i++;
    }
    
    //@ assert found;
    //@ assert pos < 5;
    //@ assert xs[pos] == 0;
    return pos + 1;
}

/*@ assigns \nothing;
*/
int main() {
    return 0;
}
