#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer x) = (x & 1) == 0; */

/*@ predicate count_invariant(int32_t *arr, integer len, integer i, integer count) =
       0 <= i <= len &&
       0 <= count <= i &&
       \forall integer j; 0 <= j < i ==> 
           (is_even(arr[j]) ==> count >= 1); */

/*@ lemma count_bounds: 
      \forall int32_t *arr, integer len, integer i, integer count;
      count_invariant(arr, len, i, count) ==> 0 <= count <= len; */

/*@ requires \valid(arr + (0..len-1));
    requires 0 <= len < 0x80000000;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
                (is_even(arr[i]) ==> \result >= 1);
 */
int32_t count_even_numbers(int32_t *arr, int32_t len) {
    int32_t count = 0;
    int32_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
                         (is_even(arr[j]) ==> count >= 1);
        loop assigns i, count;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((arr[i] & 1) == 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

/*@ assigns \nothing;
 */
int main() {
    return 0;
}
