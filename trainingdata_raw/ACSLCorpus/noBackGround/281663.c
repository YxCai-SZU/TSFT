#include <stdbool.h>

/*@ requires \valid(a+(0..4));
    requires (\forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 123);
    requires (\forall integer i; 0 <= i < (5)-1 ==> (a)[i] < (a)[i+1]);
    requires 0 <= k <= 123;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < (5) ==> (a)[j] - (a)[i] <= (k));
*/
bool func(long long *a, long long k) {
    int index = 1;
    
    /*@ loop invariant 1 <= index <= 5;
        loop invariant \forall integer i, j; 0 <= i < j < index ==> a[j] - a[i] <= k;
        loop assigns index;
        loop variant 5 - index;
    */
    while (index < 5) {
        long long diff;
        if (a[index] - a[0] < 0) {
            diff = -(a[index] - a[0]);
        } else {
            diff = a[index] - a[0];
        }
        
        //@ assert diff == a[index] - a[0];
        
        if (diff > k) {
            return false;
        }
        index += 1;
    }
    return true;
}
