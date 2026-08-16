#include <stdbool.h>

/*@
    requires \valid(p + (0..4));
    requires (\forall integer i; 0 <= i < 5 ==> 0 <= (p)[i] <= 123);
    requires ((p)[0] < (p)[1] && (p)[1] < (p)[2] && (p)[2] < (p)[3] && (p)[3] < (p)[4]);
    requires 0 <= k <= 123;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < 5 ==> (p)[j] - (p)[i] <= (k));
*/
bool func(int *p, int k) {
    int i;
    int d;
    int abs_d;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; 0 <= i < 5 ==> 0 <= (p)[i] <= 123);
        loop invariant ((p)[0] < (p)[1] && (p)[1] < (p)[2] && (p)[2] < (p)[3] && (p)[3] < (p)[4]);
        loop invariant 0 <= k <= 123;
        loop invariant \forall integer a, b; 0 <= a < b < i ==> p[b] - p[a] <= k;
        loop assigns i, d, abs_d;
        loop variant 5 - i;
    */
    while (i < 5) {
        d = p[i] - p[0];
        if (d < 0) {
            abs_d = -d;
        } else {
            abs_d = d;
        }
        
        //@ assert abs_d == (d < 0 ? -d : d);
        
        if (abs_d > k) {
            //@ assert !(\forall integer i, j; 0 <= i < j < 5 ==> (p)[j] - (p)[i] <= (k));
            return false;
        }
        i = i + 1;
    }
    //@ assert (\forall integer i, j; 0 <= i < j < 5 ==> (p)[j] - (p)[i] <= (k));
    return true;
}
