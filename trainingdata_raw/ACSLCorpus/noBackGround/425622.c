#include <stdbool.h>
#include <limits.h>

/*@ requires 
      ((length) > 0 &&
      \forall integer i; 0 <= i < (length) ==> 1 <= (numbers)[i] <= 100);
    ensures
      0 <= \result <= 99;
    assigns \nothing;
*/
int func(int* numbers, int length)
{
    int min_val = INT_MAX;
    int index = 0;
    
    /*@ loop invariant 
          0 <= index <= length;
        loop invariant
          (((index) == 0 ==> (min_val) == INT_MAX) &&
      ((index) > 0 ==> 1 <= (min_val) <= 100) &&
      \forall integer k; 0 <= k < (index) ==> (min_val) <= (numbers)[k]);
        loop invariant
          ((length) > 0 &&
      \forall integer i; 0 <= i < (length) ==> 1 <= (numbers)[i] <= 100);
        loop assigns
          min_val, index;
        loop variant
          length - index;
    */
    while (index < length)
    {
        int a = numbers[index];
        if (a < min_val)
        {
            min_val = a;
        }
        index++;
    }
    
    //@ assert 1 <= min_val <= 100;
    //@ assert \forall integer k; 0 <= k < length ==> min_val <= numbers[k];
    
    return min_val - 1;
}
