#include <stdbool.h>
#include <stdint.h>

/*@
  requires 0 <= len < 0x80000000;
  requires \valid_read(arr + (0 .. len-1));
  assigns \nothing;
  ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < (arr)[i + 1]);
*/
bool is_strictly_increasing(int32_t *arr, int32_t len) {
    if (len <= 1) {
        return true;
    }
    
    int32_t i = 1;
    /*@
      loop invariant 1 <= i <= len;
      loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
      loop assigns i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i - 1 < len;
        //@ assert 0 <= i < len;
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
        i++;
    }
    return true;
}
