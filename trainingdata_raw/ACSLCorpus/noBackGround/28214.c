#include <stdbool.h>

/*@ requires \valid(v+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 40);
    ensures \result == true <==> (\forall integer i; 0 <= i < (5) ==> (v)[i] >= 20);
    assigns \nothing;
*/
bool func(int *v) {
    int i;
    i = 0;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 40);
        loop invariant \forall integer j; 0 <= j < i ==> v[j] >= 20;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] < 20) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
