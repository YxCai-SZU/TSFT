#include <limits.h>
#include <stdbool.h>

/*@
  requires \valid_read(arr + (0..len-1));
  requires len > 0;
  assigns \nothing;
  ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result));
  ensures (\forall integer j; 0 <= j < (len) ==> (arr)[j] <= (\result));
*/
int find_max(int *arr, int len) {
    int max_val = INT_MIN;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= len;
      loop invariant i == 0 ==> max_val == INT_MIN;
      loop invariant i > 0 ==> \exists integer k; 0 <= k < i && max_val == arr[k];
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= max_val;
      loop assigns max_val, i;
      loop variant len - i;
    */
    while (i < len) {
        int num = arr[i];
        if (num > max_val) {
            max_val = num;
        }
        //@ assert arr[i] <= max_val;
        i++;
    }
    return max_val;
}
