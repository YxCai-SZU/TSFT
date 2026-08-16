#include <stddef.h>
#include <stdbool.h>

/*@ predicate element_exists_in_range(int* arr, integer len, integer start, integer end, int element) =
      \exists integer j; start <= j < end && arr[j] == element;
*/

/*@ predicate element_absent_in_range(int* arr, integer len, integer start, integer end, int element) =
      \forall integer j; start <= j < end ==> arr[j] != element;
*/

/*@ lemma element_condition_lemma:
      \forall int* arr, integer len, integer i, int element;
        0 <= i < len ==>
        (arr[i] == element ==> element_exists_in_range(arr, len, 0, len, element)) ||
        (arr[i] != element ==> element_absent_in_range(arr, len, 0, len, element));
*/

/*@ requires \valid_read(lst + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==>
        (lst[i] == element ==> element_exists_in_range(lst, len, 0, len, element)) ||
        (lst[i] != element ==> element_absent_in_range(lst, len, 0, len, element));
*/
size_t count_element_sequence(const int* lst, size_t len, int element) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==>
            (lst[j] == element ==> element_exists_in_range(lst, len, 0, i, element)) ||
            (lst[j] != element ==> element_absent_in_range(lst, len, 0, i, element));
        loop invariant len < 0x80000000;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        if (lst[i] == element) {
            count++;
        }
        i++;
    }
    return count;
}
