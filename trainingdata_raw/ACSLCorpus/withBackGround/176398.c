#include <stddef.h>
#include <stdint.h>

/*@
    predicate is_odd(integer x) = (x & 1) != 0;
    
    logic integer list_len{L}(int32_t *list, integer length) = length;
    
    predicate valid_list(int32_t *list, integer length) = 
        length >= 0 && length < 0x80000000;
*/

/*@
    requires valid_list(list, length);
    ensures \result >= 0;
    ensures \result <= length;
    ensures (\forall integer i; 0 <= i < length && is_odd(list[i]) ==> 
             (\exists integer j; 0 <= j < length && is_odd(list[j])));
    assigns \nothing;
*/
int32_t odd_count(int32_t *list, int32_t length) {
    int32_t count = 0;
    int32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= length;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer j; 0 <= j < i && is_odd(list[j]) ==> 
                       (\exists integer k; 0 <= k < length && is_odd(list[k])));
        loop invariant length < 0x80000000;
        loop assigns i, count;
        loop variant length - i;
    */
    while (i < length) {
        //@ assert 0 <= i < length;
        if ((list[i] & 1) != 0) {
            //@ assert is_odd(list[i]);
            count = count + 1;
        }
        i = i + 1;
    }
    
    //@ assert count >= 0;
    //@ assert count <= length;
    return count;
}

/*@
    lemma odd_exists_preserved:
        \forall int32_t *list, integer length, integer i;
        valid_list(list, length) && 0 <= i < length &&
        (\forall integer j; 0 <= j < i && is_odd(list[j]) ==> 
         (\exists integer k; 0 <= k < length && is_odd(list[k]))) ==>
        (\forall integer j; 0 <= j < i+1 && is_odd(list[j]) ==> 
         (\exists integer k; 0 <= k < length && is_odd(list[k])));
*/

int main() {
    //@ ghost int32_t arr[3] = {1, 2, 3};
    //@ ghost int32_t res = odd_count(arr, 3);
    return 0;
}
