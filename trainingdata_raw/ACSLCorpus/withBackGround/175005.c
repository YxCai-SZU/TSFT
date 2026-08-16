#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_element(integer i, integer val) =
      val == i + 1 || val == 0;
*/

/*@ predicate exists_zero(integer size, int *arr) =
      \exists integer i; 0 <= i < size && arr[i] == 0;
*/

/*@ predicate all_nonzero_up_to(integer bound, int *arr) =
      \forall integer j; 0 <= j < bound ==> arr[j] != 0;
*/

/*@ lemma zero_exists_in_range:
      \forall integer size, int *arr;
      size == 5 && (\forall integer i; 0 <= i < size ==> is_valid_element(i, arr[i])) &&
      exists_zero(size, arr) ==>
      \exists integer i; 0 <= i < size && arr[i] == 0;
*/

/*@ requires \valid(arr + (0 .. 4));
    requires \forall integer i; 0 <= i < 5 ==> is_valid_element(i, arr[i]);
    requires exists_zero(5, arr);
    ensures 1 <= \result <= 5;
    ensures arr[\result - 1] == 0;
    assigns \nothing;
*/
int64_t func(int arr[5]) {
    int64_t v = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant v == 0 || (1 <= v <= 5 && arr[v - 1] == 0);
        loop invariant all_nonzero_up_to(i, arr);
        loop invariant \forall integer k; 0 <= k < 5 ==> is_valid_element(k, arr[k]);
        loop invariant exists_zero(5, arr);
        loop assigns v, i;
        loop variant 5 - i;
    */
    while (i < 5) {
        if (arr[i] == 0) {
            v = (int64_t)i + 1;
            break;
        }
        i++;
    }
    
    //@ assert 1 <= v <= 5;
    //@ assert arr[v - 1] == 0;
    
    return v;
}
