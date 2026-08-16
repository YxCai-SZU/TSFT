#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
      \valid((nums) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (nums)[i] >= 1 && (nums)[i] <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *nums) {
    int max = -1;
    int result = 0;
    int index = 0;
    
    /*@ loop invariant ((index) <= (n) &&
      (result) >= 0 &&
      (result) <= (index) &&
      (((n)) >= 1 && ((n)) <= 100 &&
      \valid(((nums)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((nums))[i] >= 1 && ((nums))[i] <= 100));
        loop assigns max, result, index;
        loop variant n - index;
    */
    while (index < n) {
        int num = nums[index];
        //@ assert num >= 1 && num <= 100;
        if (max < num) {
            max = num;
            result += 1;
        }
        index += 1;
    }
    //@ assert result >= 0 && result <= n;
    return result;
}
