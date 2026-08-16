#include <stdbool.h>
#include <limits.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires ((len) > 0);
    assigns \nothing;
    ensures \result >= arr[0];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
 */
int func(int *arr, int len) {
    int max_value = INT_MIN;
    int index = 0;
    
    /*@ loop invariant (0 <= (index) <= (len));
        loop invariant ((len) > 0);
        loop invariant (\forall integer j; 0 <= j < (index) ==> (max_value) >= (arr)[j]);
        loop invariant index > 0 ==> max_value >= INT_MIN;
        loop assigns max_value, index;
        loop variant len - index;
     */
    while (index < len) {
        int value = arr[index];
        if (value > max_value) {
            max_value = value;
        }
        index++;
    }
    return max_value;
}
