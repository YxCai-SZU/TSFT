#include <stddef.h>
#include <stdbool.h>

/*@ predicate count_in_range(integer i, integer len, integer cnt) =
      0 <= i <= len && cnt <= i;
*/

/*@ predicate element_matches(int *arr, integer i, int num, integer cnt) =
      \forall integer k; 0 <= k < i ==> (arr[k] == num ==> cnt > 0);
*/

/*@ lemma count_bounded: \forall integer cnt, integer len;
      cnt <= len ==> cnt <= len;
*/

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer k; 0 <= k < len ==> (arr[k] == num ==> \result > 0);
*/
size_t count_occurrences(int *arr, size_t len, int num) {
    size_t i = 0;
    size_t count = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer k; 0 <= k < i ==> (arr[k] == num ==> count > 0);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] == num) {
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert count <= len;
    return count;
}
