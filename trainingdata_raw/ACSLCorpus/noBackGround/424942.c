#include <stddef.h>
#include <stdbool.h>

/*@
  requires n >= 0;
  requires \valid(nums + (0..n-1));
  requires \valid(result + (0..n-1));
  ensures (\forall integer i; 0 <= i < (n) ==> (result)[i] == (nums)[(n) - 1 - i]);
  assigns result[0..n-1];
*/
void func(int n, int *nums, int *result) {
    int index = n - 1;
    int i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant index == n - 1 - i;
      loop invariant \forall integer j; 0 <= j < i ==> result[j] == nums[n - 1 - j];
      loop assigns i, index, result[0..n-1];
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= index < n;
        result[i] = nums[index];
        index -= 1;
        i += 1;
    }
}
