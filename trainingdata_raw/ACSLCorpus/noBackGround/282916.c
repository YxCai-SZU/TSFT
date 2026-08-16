#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires 2 <= len && len <= 200000;
  requires (\forall integer i; 0 <= i < (len) ==> ((arr)[i] == 0 || (arr)[i] == 1));
  assigns \nothing;
  ensures 0 <= \result <= len;
*/
int func(const int *arr, size_t len) {
    int s = 0;
    int e = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant s >= 0;
      loop invariant e >= 0;
      loop invariant s + e <= (int)index;
      loop assigns s, e, index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert arr[index] == 0 || arr[index] == 1;
        if (arr[index] == 0) {
            s++;
        } else {
            e++;
        }
        index++;
    }
    
    int min_val = (s < e) ? s : e;
    //@ assert min_val >= 0 && min_val <= (int)len;
    return min_val;
}
