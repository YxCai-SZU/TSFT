#include <stdbool.h>

/*@ requires \valid(v+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> ((v)[i] == i+1 || (v)[i] == 0));
    requires (\exists integer i; 0 <= i < (5) && (v)[i] == 0);
    ensures \result == true <==> (\exists integer i; 0 <= i < (5) && (v)[i] == 0);
*/
bool func(int v[5]) {
    bool found_zero = false;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant !found_zero ==> 
            \forall integer j; 0 <= j < i ==> v[j] != 0;
        loop invariant found_zero ==> 
            \exists integer j; 0 <= j < i && v[j] == 0;
        loop invariant (\forall integer i; 0 <= i < (5) ==> ((v)[i] == i+1 || (v)[i] == 0));
        loop assigns found_zero, i;
    */
    while (i < 5) {
        if (v[i] == 0) {
            found_zero = true;
        }
        i++;
    }
    return found_zero;
}
