#include <stdbool.h>

/*@ requires \valid(v+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] && (v)[i] <= 123);
    requires (\forall integer i, j; 0 <= i < j < (5) ==> (v)[i] < (v)[j]);
    requires 0 <= k <= 123;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < (5) ==> (v)[j] - (v)[i] <= (k));
*/
bool func(int *v, int k) {
    int vec[5];
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> vec[j] == v[j];
        loop invariant (\forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] && (v)[i] <= 123);
        loop invariant (\forall integer i, j; 0 <= i < j < (5) ==> (v)[i] < (v)[j]);
        loop assigns i, vec[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        vec[i] = v[i];
        i++;
    }
    
    int first = vec[0];
    int last = vec[4];
    
    //@ assert first == v[0] && last == v[4];
    
    if (last - first > k) {
        //@ assert !(\forall integer i, j; 0 <= i < j < (5) ==> (v)[j] - (v)[i] <= (k));
        return false;
    } else {
        //@ assert (\forall integer i, j; 0 <= i < j < (5) ==> (v)[j] - (v)[i] <= (k));
        return true;
    }
}
