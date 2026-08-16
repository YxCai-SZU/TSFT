#include <stdbool.h>
/*@
  requires \valid_read(arr + (0 .. len-1));
  requires len > 0;
  assigns \nothing;
  ensures \result == true ==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
  ensures \result == false ==> (\exists integer i; 0 <= i < (len) - 1 && (arr)[i] > (arr)[i + 1]);
*/
bool non_decreasing_subarray(int *arr, int len) {
    int index = 0;
    /*@
      loop invariant 0 <= index <= len;
      loop invariant \forall integer i; 0 <= i < index ==> arr[i] <= arr[i + 1];
      loop assigns index;
      loop variant len - index;
    */
    while (index < len - 1) {
        //@ assert 0 <= index < len - 1;
        if (arr[index] > arr[index + 1]) {
            //@ assert (\exists integer i; 0 <= i < (len) - 1 && (arr)[i] > (arr)[i + 1]);
            return false;
        }
        //@ assert arr[index] <= arr[index + 1];
        index++;
        //@ assert \forall integer i; 0 <= i < index ==> arr[i] <= arr[i + 1];
    }
    //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    return true;
}
