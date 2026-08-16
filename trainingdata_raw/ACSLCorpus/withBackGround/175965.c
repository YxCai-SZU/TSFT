#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int* a, integer len) =
    len >= 1 && len <= 200000 &&
    \forall integer i; 0 <= i < len ==> a[i] >= 1 && a[i] <= 1000000;
*/

/*@ predicate count_invariant(integer i, integer count, integer len) =
    i <= len && count <= i;
*/

/*@ lemma array_unchanged:
    \forall int* a, integer len; valid_array(a, len) ==> 
    \forall integer i; 0 <= i < len ==> a[i] >= 1 && a[i] <= 1000000;
*/

/*@
requires valid_array(a, len);
assigns \nothing;
ensures 0 <= \result <= len;
*/
size_t func(int* a, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
    loop invariant 0 <= i <= len;
    loop invariant 0 <= count <= i;
    loop invariant valid_array(a, len);
    loop assigns i, count;
    loop variant len - i;
    */
    while (i < len) {
        bool is_divisible = false;
        size_t j = 0;
        
        /*@
        loop invariant 0 <= j <= len;
        loop invariant is_divisible == false || is_divisible == true;
        loop invariant valid_array(a, len);
        loop assigns j, is_divisible;
        loop variant len - j;
        */
        while (j < len) {
            if (i == j) {
                j++;
                continue;
            }
            int div_result = a[j] / a[i];
            int rem_result = a[j] % a[i];
            if (rem_result == 0 && div_result > 1) {
                is_divisible = true;
            }
            j++;
        }
        if (!is_divisible) {
            count++;
        }
        i++;
    }
    return count;
}
