#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_odd(integer x) = (x & 1) != 0;
    
    predicate odd_exists_between(int32_t *arr, integer len, integer start, integer end) =
        \forall integer j; start <= j < end ==>
            (is_odd(arr[j]) ==>
                (\exists integer k; start <= k < end && is_odd(arr[k])));
    
    lemma odd_preservation: \forall int32_t *arr, integer len, integer i;
        odd_exists_between(arr, len, 0, i) && i < len && is_odd(arr[i]) ==>
            odd_exists_between(arr, len, 0, i+1);
*/

/*@
    requires \valid(list_data + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures odd_exists_between(list_data, len, 0, len);
*/
unsigned int odd_count(const int32_t *list_data, unsigned int len) {
    unsigned int count = 0;
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant odd_exists_between(list_data, len, 0, i);
        loop invariant len < 0x80000000;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        if (list_data[i] & 1) {
            count = count + 1;
            //@ assert count <= i + 1;
        }
        i = i + 1;
    }
    return count;
}
