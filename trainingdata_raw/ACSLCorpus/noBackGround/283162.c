#include <stdbool.h>

/*@
  requires (\valid((input) + (0..2)) &&
      1 <= (input)[0] <= 100 &&
      1 <= (input)[1] <= 100 &&
      1 <= (input)[2] <= 100);
  ensures \result == input[0] + input[1] || 
          \result == input[0] + input[2] || 
          \result == input[1] + input[2];
*/
int func(int *input)
{
    int max_val;
    int min_val;
    int mid_val;
    int i;
    
    max_val = input[0];
    i = 1;
    /*@ loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= input[k];
        loop invariant \exists integer k; 0 <= k < i && max_val == input[k];
        loop assigns max_val, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 0 <= i < 3;
        if (input[i] > max_val) {
            max_val = input[i];
        }
        i++;
    }
    
    min_val = input[0];
    i = 1;
    /*@ loop invariant 0 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= input[k];
        loop invariant \exists integer k; 0 <= k < i && min_val == input[k];
        loop assigns min_val, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 0 <= i < 3;
        if (input[i] < min_val) {
            min_val = input[i];
        }
        i++;
    }
    
    mid_val = input[0] + input[1] + input[2] - max_val - min_val;
    
    //@ assert max_val >= min_val;
    //@ assert max_val >= mid_val;
    //@ assert min_val <= mid_val;
    
    if (max_val == min_val) {
        //@ assert max_val == min_val && min_val == mid_val;
        return max_val + mid_val;
    } else if (max_val == mid_val) {
        //@ assert max_val == mid_val && min_val < max_val;
        return max_val + min_val;
    } else {
        //@ assert max_val > mid_val && mid_val >= min_val;
        return max_val + mid_val;
    }
}
