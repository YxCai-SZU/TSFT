#include <stdbool.h>

/*@
  requires 0 <= len < 0x80000000;
  ensures \result >= 0;
  ensures \result <= len;
  ensures len == 0 ==> \result == 0;
*/
int count_odd_occurrences(int* nums, int len) {
    int count = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= len;
      loop invariant 0 <= count <= index;
      loop invariant len < 0x80000000;
      loop invariant \forall integer k; 0 <= k < index ==> 
                    ((((nums[k]) & 1) != 0) ==> count > 0);
      loop assigns count, index;
      loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len;
        if ((nums[index] & 1) != 0) {
            //@ assert (((nums[index]) & 1) != 0);
            count += 1;
        }
        index += 1;
    }
    
    //@ assert index == len;
    //@ assert count >= 0 && count <= len;
    return count;
}
