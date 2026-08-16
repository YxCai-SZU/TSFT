#include <stdbool.h>

/*@
    requires \valid(v+(0..4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123 &&
    (v)[0] < (v)[1] < (v)[2] < (v)[3] < (v)[4]);
    requires 0 <= k <= 123;
    ensures \result == true <==> ((v)[4] - (v)[0] <= (k));
*/
bool func(int* v, int k) {
    int i;
    int vec[5];
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> vec[j] == v[j];
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123 &&
    (v)[0] < (v)[1] < (v)[2] < (v)[3] < (v)[4]);
        loop assigns i, vec[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        vec[i] = v[i];
        i = i + 1;
    }
    
    int first = vec[0];
    int last = vec[4];
    
    if (last - first > k) {
        return false;
    } else {
        //@ assert vec[4] - vec[0] <= k;
    }
    
    return true;
}
