#include <stdbool.h>

/*@ predicate is_valid_index(integer i) = 0 <= i < 7;
  @ predicate in_range(integer v) = 1 <= v <= 9;
  @ predicate array_valid(int *arr) = 
  @   \forall integer i; is_valid_index(i) ==> in_range(arr[i]);
  @ predicate exists_seven(int *arr, integer bound) = 
  @   \exists integer i; 0 <= i < bound && arr[i] == 7;
*/

/*@ requires \valid(nums+(0..6));
  @ requires array_valid(nums);
  @ ensures \result == true <==> exists_seven(nums, 7);
*/
bool exists_number(int nums[7]) {
    int count = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= 7;
      @ loop invariant 0 <= count <= index;
      @ loop invariant array_valid(nums);
      @ loop invariant \forall integer k; 0 <= k < index ==> 
      @   (nums[k] != 7 || count > 0);
      @ loop invariant count > 0 <==> exists_seven(nums, index);
      @ loop assigns count, index;
    */
    while (index < 7) {
        int x = nums[index];
        if (x == 7) {
            //@ assert x == 7;
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count > 0 <==> exists_seven(nums, 7);
    return count > 0;
}

int main() {
    return 0;
}
