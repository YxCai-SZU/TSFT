#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer x) = (x & 1) == 0; */

/*@
    requires \valid(arr + (0..len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer k; 0 <= k < len ==> (is_even(arr[k]) ==> \result <= len);
*/
int32_t count_even_elements(int32_t* arr, int32_t len) {
    int32_t num = 0;
    int32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= num <= i;
        loop invariant \forall integer k; 0 <= k < i ==> (is_even(arr[k]) ==> num <= i);
        loop assigns num, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((arr[i] & 1) == 0) {
            num = num + 1;
        }
        i = i + 1;
    }
    return num;
}
