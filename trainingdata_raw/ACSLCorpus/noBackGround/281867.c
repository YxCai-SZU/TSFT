#include <stdbool.h>

/*@
    requires (\valid((v) + (0..4)) &&
        (\forall integer i; 0 <= i < 5 ==> 0 <= (v)[i] <= 123) &&
        (v)[0] < (v)[1] < (v)[2] < (v)[3] < (v)[4]);
    requires 0 <= k <= 123;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < 5 ==> (v)[j] - (v)[i] <= (k));
    assigns \nothing;
*/
bool func(int* v, int k) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\valid((v) + (0..4)) &&
        (\forall integer i; 0 <= i < 5 ==> 0 <= (v)[i] <= 123) &&
        (v)[0] < (v)[1] < (v)[2] < (v)[3] < (v)[4]);
        loop invariant \forall integer x, y; 0 <= x < y < i ==> v[y] - v[x] <= k;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        int d = v[i] - v[0];
        int abs_d = (d < 0) ? -d : d;
        
        //@ assert abs_d == v[i] - v[0] || abs_d == v[0] - v[i];
        
        if (abs_d > k) {
            //@ assert v[i] - v[0] > k || v[0] - v[i] > k;
            return false;
        }
        
        i++;
    }
    
    //@ assert i == 5;
    //@ assert \forall integer x, y; 0 <= x < y < 5 ==> v[y] - v[x] <= k;
    return true;
}
