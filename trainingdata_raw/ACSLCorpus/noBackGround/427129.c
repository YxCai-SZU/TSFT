#include <stdbool.h>

/*@ requires (1 <= (n) <= 100 &&
      1 <= (m) <= 100 &&
      1 <= (x) <= (n) - 1);
    requires \valid(a + (0 .. m-1));
    requires (\forall integer i; 0 <= i < (m) ==> 
        ((a)[i] >= 1 && (a)[i] <= (n) && (a)[i] != (x)));
    ensures \result >= 0 && \result <= m;
    assigns \nothing;
*/
int func(int n, int m, int x, int *a) {
    int l = 0;
    int r = 0;
    unsigned int i = 0;
    
    /*@ loop invariant 0 <= i <= m;
        loop invariant 0 <= l <= i;
        loop invariant 0 <= r <= i;
        loop invariant l + r == i;
        loop assigns i, l, r;
        loop variant m - i;
    */
    while (i < (unsigned int)m) {
        int value = a[i];
        
        //@ assert value != x;
        
        if (value > x) {
            r = r + 1;
        } else if (value < x) {
            l = l + 1;
        }
        
        i = i + 1;
    }
    
    int min_val;
    if (r < l) {
        min_val = r;
    } else {
        min_val = l;
    }
    
    //@ assert min_val >= 0;
    return min_val;
}
