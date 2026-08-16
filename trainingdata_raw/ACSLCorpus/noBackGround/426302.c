#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires ((len) > 0 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
  assigns \nothing;
  ensures 0 <= \result <= 100;
  ensures ((len) > 0 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
*/
int func(int *arr, size_t len) {
    int max;
    int min;
    size_t index;
    
    max = arr[0];
    min = arr[0];
    index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= arr[i] && arr[i] <= 100;
      loop invariant ((len) > 0 &&
      \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] && (arr)[i] <= 100);
      loop invariant max >= min;
      loop invariant max <= 100;
      loop invariant min >= 1;
      loop invariant \forall integer k; 0 <= k < len ==> 1 <= arr[k] && arr[k] <= 100;
      loop assigns max, min, index;
      loop variant len - index;
    */
    while (index < len) {
        int value = arr[index];
        
        //@ assert 1 <= value && value <= 100;
        
        if (max < value) {
            max = value;
        }
        if (min > value) {
            min = value;
        }
        index++;
    }
    
    //@ assert max - min >= 0;
    //@ assert max - min <= 100;
    
    return max - min;
}
