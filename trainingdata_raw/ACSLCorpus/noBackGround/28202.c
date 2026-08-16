#include <stdbool.h>

/*@ requires 
      0 <= length && 
      \valid(nums + (0 .. length-1));
    ensures
      (\result == true) ==> (\exists integer i; 0 <= i < (length) && (nums)[i] < 0);
    ensures
      (\result == false) ==> (\forall integer i; 0 <= i < (length) ==> (nums)[i] >= 0);
    assigns \nothing;
*/
bool find_negative(int* nums, int length)
{
    int index = 0;
    
    /*@ loop invariant 0 <= index <= length;
        loop invariant (\forall integer i; 0 <= i < (index) ==> (nums)[i] >= 0);
        loop assigns index;
        loop variant length - index;
    */
    while (index < length) {
        //@ assert 0 <= index < length;
        if (nums[index] < 0) {
            //@ assert (\exists integer i; 0 <= i < (length) && (nums)[i] < 0);
            return true;
        }
        //@ assert nums[index] >= 0;
        index++;
    }
    //@ assert (\forall integer i; 0 <= i < (length) ==> (nums)[i] >= 0);
    return false;
}
