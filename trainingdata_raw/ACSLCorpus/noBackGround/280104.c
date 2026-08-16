#include <stdbool.h>

/*@ requires \valid(v + (0..4));
    requires ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> ((v)[i] == i + 1 || (v)[i] == 0)) &&
      (\exists integer i; 0 <= i < (5) && (v)[i] == 0));
    ensures \result > 0;
    ensures \result <= 6;
    ensures v[\result - 1] == 0;
*/
int func(int *v) {
    int i;
    i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \exists integer j; i <= j < 5 && v[j] == 0;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] != 0;
        loop invariant ((5) == 5 &&
      (\forall integer i; 0 <= i < (5) ==> ((v)[i] == i + 1 || (v)[i] == 0)) &&
      (\exists integer i; 0 <= i < (5) && (v)[i] == 0));
        loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            //@ assert i + 1 > 0;
            //@ assert i + 1 <= 6;
            //@ assert v[(i + 1) - 1] == 0;
            return i + 1;
        }
        //@ assert v[i] != 0;
        i = i + 1;
    }
    
    return -1;
}
