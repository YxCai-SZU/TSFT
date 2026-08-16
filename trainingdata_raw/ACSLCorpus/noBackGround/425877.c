#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s) {
    int min_val;
    int max_val;
    bool ans;
    int v[3];
    int i;
    
    // Calculate min
    min_val = d < t ? d : t;
    //@ assert min_val == (d < t ? d : t);
    min_val = min_val < s ? min_val : s;
    //@ assert min_val == (((d) < (t) ? ((d) < (s) ? (d) : (s)) : ((t) < (s) ? (t) : (s))));
    
    // Calculate max
    max_val = d > t ? d : t;
    //@ assert max_val == (d > t ? d : t);
    max_val = max_val > s ? max_val : s;
    //@ assert max_val == (((d) > (t) ? ((d) > (s) ? (d) : (s)) : ((t) > (s) ? (t) : (s))));
    
    // Check product bound
    //@ assert t * s <= 10000 * 10000;
    ans = (t * s >= d);
    
    // Initialize vector with zeros
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] == 0;
        loop assigns i, v[0..2];
        loop variant 3 - i;
    */
    while (i < 3) {
        v[i] = 0;
        i = i + 1;
    }
    
    // Set values
    v[0] = d;
    v[1] = t;
    v[2] = s;
    
    // Loop through vector
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant v[0] == d && v[1] == t && v[2] == s;
        loop assigns i;
        loop variant 3 - i;
    */
    while (i < 3) {
        i = i + 1;
    }
    
    return ans;
}
