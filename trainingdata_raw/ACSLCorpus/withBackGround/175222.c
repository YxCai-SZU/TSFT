#include <stdbool.h>

/*@ predicate element_exists(int* arr, integer len, integer idx, int val) =
      0 <= idx < len && arr[idx] == val;
*/

/*@ predicate is_max(int* arr, integer len, integer idx, int val) =
      0 <= idx < len && arr[idx] == val &&
      (\forall integer j; 0 <= j < len ==> arr[j] <= val);
*/

/*@ lemma max_exists_property:
      \forall int* arr, integer len, int max_val;
        len > 0 ==>
        (\exists integer i; 0 <= i < len && arr[i] == max_val) ==>
        element_exists(arr, len, 0, max_val) ||
        (\exists integer i; 0 <= i < len && arr[i] == max_val);
*/

/*@ lemma max_universal_property:
      \forall int* arr, integer len, int max_val;
        (\forall integer i; 0 <= i < len ==> arr[i] <= max_val) ==>
        (\forall integer j; 0 <= j < len ==> arr[j] <= max_val);
*/

/*@ requires \valid(arr + (0 .. len-1));
    requires len > 0;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer i; 0 <= i < len ==> arr[i] <= \result;
    assigns \nothing;
*/
int max(int* arr, int len) {
    int max_value;
    int i;
    
    max_value = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max_value;
        loop invariant \exists integer j; 0 <= j < i && arr[j] == max_value;
        loop assigns max_value, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        i++;
    }
    
    //@ assert \exists integer j; 0 <= j < len && arr[j] == max_value;
    
    return max_value;
}
