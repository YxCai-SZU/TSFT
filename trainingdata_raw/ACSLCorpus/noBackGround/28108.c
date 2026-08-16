#include <stdbool.h>

/*@ requires \valid(v+(0..4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123 &&
    (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
    requires 0 <= k <= 123;
    ensures ((\result) == ((v)[4] - (v)[0] <= (k)));
    assigns \nothing;
*/
bool func(int *v, int k) {
    int v2[5];
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> v2[j] == v[j];
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (v)[i] <= 123 &&
    (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]);
        loop assigns i, v2[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        v2[i] = v[i];
        i++;
    }
    
    int d = v2[4] - v2[0];
    
    //@ assert d == v[4] - v[0];
    //@ assert d <= 123;
    
    return d <= k;
}
