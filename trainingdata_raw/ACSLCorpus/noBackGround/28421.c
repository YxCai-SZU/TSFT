#include <stdbool.h>
#include <stdint.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
  requires 0 <= len < 0x80000000;
  ensures \result == true ==> (\exists integer i; 0 <= i < (len) && (arr)[i] == (x));
  ensures \result == false ==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] != (x));
  assigns \nothing;
*/
bool does_exist(int *arr, int32_t len, int x) {
    int32_t low = 0;
    int32_t high = len;
    
    /*@
      loop invariant 0 <= low <= high <= len;
      loop invariant \forall integer i; 0 <= i < low ==> arr[i] < x;
      loop invariant \forall integer i; high <= i < len ==> arr[i] > x;
      loop assigns low, high;
      loop variant high - low;
    */
    while (low < high) {
        int32_t mid = low + (high - low) / 2;
        
        //@ assert low <= mid < high;
        
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid;
        } else {
            //@ assert arr[mid] == x;
            return true;
        }
    }
    
    //@ assert \forall integer i; 0 <= i < len ==> arr[i] != x;
    return false;
}
