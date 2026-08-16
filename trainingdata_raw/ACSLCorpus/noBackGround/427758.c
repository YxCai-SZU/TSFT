#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid_read(nums + (0 .. len-1));
  requires (\forall integer i, j; 0 <= i <= j < (len) ==> (nums)[i] <= (nums)[j]);
  ensures \result <==> (\exists integer i; 0 <= i < (len) && (nums)[i] == (target));
  assigns \nothing;
*/
bool contains_num(int *nums, size_t len, int target) {
    size_t start = 0;
    size_t end = len;
    
    /*@
      loop invariant 0 <= start <= end <= len;
      loop invariant (\forall integer i, j; 0 <= i <= j < (len) ==> (nums)[i] <= (nums)[j]);
      loop invariant \forall integer i; 0 <= i < start ==> nums[i] < target;
      loop invariant \forall integer i; end <= i < len ==> nums[i] > target;
      loop assigns start, end;
      loop variant end - start;
    */
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        
        //@ assert start <= mid < end;
        
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return false;
}
