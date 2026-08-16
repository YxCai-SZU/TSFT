#include <stdbool.h>

/*@
  requires \valid(nums + (0..4));
  requires (\forall integer i; 0 <= i < (5) ==> 1 <= (nums)[i] && (nums)[i] <= 5);
  requires (\exists integer i; 0 <= i < (5) && (nums)[i] == 0);
  ensures 1 <= \result && \result <= 5;
  ensures nums[\result - 1] == 0;
  ensures \forall integer i; 0 <= i < 5 && i != \result - 1 ==> 1 <= nums[i] && nums[i] <= 5;
*/
int search(int* nums) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant (\forall integer i; 0 <= i < (5) ==> 1 <= (nums)[i] && (nums)[i] <= 5);
      loop invariant (\exists integer i; 0 <= i < (5) && (nums)[i] == 0);
      loop invariant \forall integer j; 0 <= j < i ==> nums[j] != 0;
      loop assigns i;
      loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert (\forall integer i; 0 <= i < (5) ==> 1 <= (nums)[i] && (nums)[i] <= 5);
        if (nums[i] == 0) {
            //@ assert nums[i] == 0;
            return i + 1;
        }
        //@ assert nums[i] != 0;
        i++;
    }
    return 0;
}
