#include <stdbool.h>
#include <limits.h>

/*@ predicate valid_array(int *arr, integer len) =
    len >= 2 && len <= 50 &&
    \forall integer k; 0 <= k < len ==> arr[k] >= 0 && arr[k] <= 100;
*/

/*@ lemma diff_non_negative:
    \forall int *arr, integer len; valid_array(arr, len) ==>
    (\forall integer i, j; 0 <= i < len && 0 <= j < len ==> 
     (arr[i] >= arr[j] ? arr[i] - arr[j] >= 0 : arr[j] - arr[i] >= 0));
*/

/*@ requires \valid_read(numbers + (0 .. len-1));
    requires valid_array(numbers, len);
    ensures \result >= 0;
*/
int func(int *numbers, int len) {
    int diff = INT_MAX;
    int i = 0;
    int j;
    
    //@ assert diff >= 0;
    
    /*@ loop invariant 0 <= i <= len - 1;
        loop invariant valid_array(numbers, len);
        loop invariant diff >= 0;
        loop assigns i, diff, j;
        loop variant len - i;
    */
    while (i < len - 1) {
        j = i + 1;
        
        /*@ loop invariant i < j <= len;
            loop invariant valid_array(numbers, len);
            loop invariant diff >= 0;
            loop assigns j, diff;
            loop variant len - j;
        */
        while (j < len) {
            int a = numbers[i];
            int b = numbers[j];
            int abs_diff = (a > b) ? (a - b) : (b - a);
            
            //@ assert abs_diff >= 0;
            
            if (abs_diff < diff) {
                diff = abs_diff;
            }
            
            //@ assert diff >= 0;
            j++;
        }
        
        i++;
    }
    
    //@ assert diff >= 0;
    return diff;
}
