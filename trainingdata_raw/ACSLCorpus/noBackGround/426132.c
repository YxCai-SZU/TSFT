#include <stdbool.h>

/*@
    requires (0 <= (a) < (b) < (c) < (d) < (e) <= 123);
    requires (0 <= (k) <= 123);
    ensures \result == (e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int min_val;
    int max_val;
    
    // First comparison: a and b
    if (a < b) {
        min_val = a;
        max_val = b;
    } else {
        min_val = b;
        max_val = a;
    }
    
    // Compare with c
    //@ assert min_val <= max_val;
    if (min_val < c) {
        // min_val stays the same
    } else {
        min_val = c;
    }
    if (max_val > c) {
        // max_val stays the same
    } else {
        max_val = c;
    }
    
    // Compare with d
    //@ assert min_val <= max_val;
    if (min_val < d) {
        // min_val stays the same
    } else {
        min_val = d;
    }
    if (max_val > d) {
        // max_val stays the same
    } else {
        max_val = d;
    }
    
    // Compare with e
    //@ assert min_val <= max_val;
    if (min_val < e) {
        // min_val stays the same
    } else {
        min_val = e;
    }
    if (max_val > e) {
        // max_val stays the same
    } else {
        max_val = e;
    }
    
    // Final verification properties
    //@ assert min_val == a;
    //@ assert max_val == e;
    //@ assert 0 <= e - a <= 123;
    
    return (e - a) <= k;
}
