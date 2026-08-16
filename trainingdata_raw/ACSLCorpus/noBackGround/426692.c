#include <limits.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int m1 = INT_MAX;
    int m2 = INT_MAX;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant m1 >= 0;
        loop invariant m2 >= 0;
        loop invariant \forall size_t j; 0 <= j < i ==> a[j] >= 1 && a[j] <= 1000000000;
        loop assigns i, m1, m2;
        loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        
        //@ assert ai >= 1 && ai <= 1000000000;
        
        if (ai < m1) {
            m2 = m1;
            m1 = ai;
        } else if (ai < m2) {
            m2 = ai;
        }
        
        //@ assert m1 >= 0;
        //@ assert m2 >= 0;
        
        i++;
    }
    
    int diff = m1 - m2;
    int abs_diff = diff < 0 ? -diff : diff;
    
    //@ assert abs_diff == ((m1 - m2) < 0 ? -(m1 - m2) : (m1 - m2));
    //@ assert abs_diff >= 0;
    
    return abs_diff;
}
