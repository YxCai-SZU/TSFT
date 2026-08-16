#include <stddef.h>
#include <stdint.h>

/*@
    requires ((len) >= 1 && (len) <= 100000 &&
        \forall size_t i; 0 <= i < (len) ==> 1 <= (xs)[i] && (xs)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= 1000000000;
*/
int32_t func(int32_t *xs, size_t len) {
    int32_t max_value;
    int32_t min_value;
    size_t i;

    max_value = xs[0];
    min_value = xs[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t k; 0 <= k < i ==> max_value >= xs[k];
        loop invariant \forall size_t k; 0 <= k < i ==> min_value <= xs[k];
        loop invariant max_value >= min_value;
        loop invariant (\exists size_t k; 0 <= k < (i) && (max_value) == (xs)[k]);
        loop invariant (\exists size_t k; 0 <= k < (i) && (min_value) == (xs)[k]);
        loop assigns max_value, min_value, i;
        loop variant len - i;
    */
    while (i < len) {
        if (xs[i] > max_value) {
            max_value = xs[i];
        }
        
        if (xs[i] < min_value) {
            min_value = xs[i];
        }
        
        i++;
    }

    //@ assert max_value - min_value >= 0;
    
    return max_value - min_value;
}
