#include <stdbool.h>

/*@ predicate element_exists(int* arr, integer len, integer idx, int val) =
      0 <= idx < len && arr[idx] == val;
*/

/*@ predicate is_min(int* arr, integer len, int val) =
      \exists integer i; 0 <= i < len && arr[i] == val &&
      (\forall integer j; 0 <= j < len ==> arr[j] >= val);
*/

/*@ requires \valid(arr + (0 .. len-1)) && len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && arr[i] == \result;
    ensures \forall integer j; 0 <= j < len ==> arr[j] >= \result;
*/
int find_min(int* arr, int len) {
    int min_val;
    int i;
    
    min_val = arr[0];
    i = 1;
    
    /*@ loop invariant 1 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && arr[k] == min_val;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] >= min_val;
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i++;
    }
    
    //@ assert \exists integer k; 0 <= k < len && arr[k] == min_val;
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] >= min_val;
    
    return min_val;
}
