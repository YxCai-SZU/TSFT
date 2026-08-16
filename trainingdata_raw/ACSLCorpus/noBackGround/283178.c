#include <stdbool.h>
#include <stdint.h>

/*@
  requires \valid_read(arr + (0 .. len-1));
  requires (\forall integer i, j; 0 <= i <= j < (len) ==> (arr)[i] <= (arr)[j]);
  requires 0 <= len < 0x7fffffff;
  ensures \result == true <==> (\exists integer k; 0 <= k < (len) && (arr)[k] == (x));
  ensures \result == false <==> !(\exists integer k; 0 <= k < (len) && (arr)[k] == (x));
  assigns \nothing;
*/
bool contains_number(int* arr, int len, int x) {
    int low = 0;
    int high = len;
    
    /*@
      loop invariant 0 <= low <= high <= len;
      loop invariant \forall integer k; 0 <= k < low ==> arr[k] < x;
      loop invariant \forall integer k; high <= k < len ==> arr[k] > x;
      loop assigns low, high;
      loop variant high - low;
    */
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        //@ assert low <= mid < high;
        
        if (arr[mid] < x) {
            //@ assert \forall integer k; 0 <= k <= mid ==> arr[k] < x;
            low = mid + 1;
        } else if (arr[mid] > x) {
            //@ assert \forall integer k; mid <= k < len ==> arr[k] > x;
            high = mid;
        } else {
            //@ assert arr[mid] == x;
            return true;
        }
    }
    
    //@ assert \forall integer k; 0 <= k < len ==> arr[k] != x;
    return false;
}
