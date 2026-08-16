#include <stdbool.h>
#include <stddef.h>

/*@ predicate sorted(int *vec, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> vec[i] <= vec[i + 1];
*/

/*@ lemma sorted_empty: \forall int *vec; sorted(vec, 0);
    lemma sorted_single: \forall int *vec; sorted(vec, 1);
*/

/*@ requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true ==> sorted(vec, len);
    ensures \result == false ==> !sorted(vec, len);
*/
bool is_sorted(int *vec, size_t len) {
    //@ ghost size_t old_len = len;
    
    if (len <= 1) {
        //@ assert len == 0 ==> sorted(vec, len);
        return true;
    }
    
    size_t i = 0;
    /*@ loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> vec[j] <= vec[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        if (vec[i] > vec[i + 1]) {
            //@ assert !sorted(vec, old_len);
            return false;
        }
        i++;
    }
    
    //@ assert sorted(vec, old_len);
    return true;
}

/*@ predicate not_found(int *arr, integer len, int target) =
      \forall integer i; 0 <= i < len ==> arr[i] != target;
*/

/*@ lemma not_found_empty: \forall int *arr, int target; not_found(arr, 0, target);
*/

/*@ requires len < 0x80000000;
    assigns \nothing;
    ensures \result >= 0 ==> 0 <= \result < (int)len && numbers[\result] == target;
    ensures \result == -1 ==> not_found(numbers, len, target);
*/
int find_index(int *numbers, size_t len, int target) {
    //@ ghost size_t old_len = len;
    
    size_t i = 0;
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> numbers[j] != target;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (numbers[i] == target) {
            //@ assert 0 <= i < old_len;
            return (int)i;
        }
        i++;
    }
    
    //@ assert not_found(numbers, old_len, target);
    return -1;
}
