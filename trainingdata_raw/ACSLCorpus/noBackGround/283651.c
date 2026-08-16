#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && 
             (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) + (c)) || \result == ((b) + (c)) || 
            \result == ((a) + (d)) || \result == ((b) + (d));
*/
int func(int a, int b, int c, int d) {
    int v[4];
    int max_val;
    int i;
    
    v[0] = a + c;
    v[1] = a + d;
    v[2] = b + c;
    v[3] = b + d;
    
    max_val = v[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_val == v[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= v[k];
        loop assigns i, max_val;
    */
    while (i < 4) {
        //@ assert 0 <= i < 4;
        if (v[i] > max_val) {
            max_val = v[i];
        }
        i = i + 1;
    }
    
    //@ assert \exists integer j; 0 <= j < 4 && max_val == v[j];
    return max_val;
}
