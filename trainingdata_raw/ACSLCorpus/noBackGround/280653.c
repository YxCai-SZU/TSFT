#include <stdint.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    ensures \result == a*c || \result == a*d || \result == b*c || 
            \result == b*d || \result == c*a || \result == c*b || 
            \result == d*a || \result == d*b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d) {
    // Variable declarations at top of scope
    int64_t pattern[4];
    int64_t max_val;
    int i;
    
    //@ assert (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    
    //@ assert -1000000000000000000 <= a*c <= 1000000000000000000;
    pattern[0] = a * c;
    
    //@ assert -1000000000000000000 <= a*d <= 1000000000000000000;
    pattern[1] = a * d;
    
    //@ assert -1000000000000000000 <= b*c <= 1000000000000000000;
    pattern[2] = b * c;
    
    //@ assert -1000000000000000000 <= b*d <= 1000000000000000000;
    pattern[3] = b * d;
    
    max_val = pattern[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == pattern[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= pattern[j];
        loop invariant \forall integer k; 0 <= k < 4 ==> pattern[k] == pattern[k];
        loop invariant (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (pattern[i] > max_val) {
            max_val = pattern[i];
        }
        i++;
    }
    
    //@ assert \exists integer k; 0 <= k < 4 && max_val == pattern[k];
    //@ assert \forall integer j; 0 <= j < 4 ==> max_val >= pattern[j];
    
    return max_val;
}
