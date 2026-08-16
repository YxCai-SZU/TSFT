#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_vec(int *v, size_t len) =
    len >= 2 && len <= 200000 &&
    \forall size_t i; 0 <= i < len ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ predicate diff_nonnegative(int a, int b, int diff) =
    diff == (a > b ? a - b : b - a) && diff >= 0;
*/

/*@ logic integer absolute_diff(integer a, integer b) =
    a > b ? a - b : b - a;
*/

/*@ lemma diff_always_nonnegative:
    \forall integer a, b; a >= 1 && b >= 1 ==> absolute_diff(a, b) >= 0;
*/

/*@
    requires valid_vec(v, len);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int *v, size_t len) {
    int min_diff = 1000000001;
    size_t i = 0;
    
    //@ assert min_diff >= 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant valid_vec(v, len);
        loop invariant min_diff >= 0;
        loop invariant \forall size_t k; 0 <= k < i ==> v[k] >= 1 && v[k] <= 1000000000;
        loop assigns i, min_diff;
        loop variant len - i;
    */
    while (i < len - 1) {
        int diff;
        if (v[i] > v[i + 1]) {
            diff = v[i] - v[i + 1];
        } else {
            diff = v[i + 1] - v[i];
        }
        
        //@ assert diff >= 0;
        
        if (diff < min_diff) {
            min_diff = diff;
        }
        
        //@ assert min_diff >= 0;
        i++;
    }
    
    //@ assert min_diff >= 0;
    return min_diff;
}
