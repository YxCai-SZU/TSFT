#include <stddef.h>

/*@ predicate is_valid_index(integer i, integer len) = 0 <= i < len; */
/*@ predicate is_valid_value(integer v) = 0 <= v <= 2147483647; */
/*@ predicate is_valid_array(int *arr, integer len) = 
      \forall integer i; is_valid_index(i, len) ==> is_valid_value(arr[i]); */

/*@ logic integer max_value(integer a, integer b) = a > b ? a : b; */

/*@ lemma max_value_bound: 
      \forall integer a, b; is_valid_value(a) && is_valid_value(b) ==> 
      is_valid_value(max_value(a, b)); */

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    requires is_valid_array(arr, len);
    ensures is_valid_value(\result);
    ensures \forall integer i; is_valid_index(i, len) ==> \result >= arr[i];
    ensures \forall integer i; is_valid_index(i, len) ==> is_valid_value(arr[i]);
    assigns \nothing;
 */
int func(int *arr, size_t len) {
    int max_val;
    size_t i;
    
    max_val = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant is_valid_array(arr, len);
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> is_valid_value(arr[k]);
        loop invariant is_valid_value(max_val);
        loop assigns max_val, i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert is_valid_index(i, len);
        //@ assert is_valid_value(arr[i]);
        
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        
        i++;
    }
    
    return max_val;
}
