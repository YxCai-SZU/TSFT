#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *arr, integer n) =
      n >= 2 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate loop_invariant(int *arr, integer n, integer idx, integer num) =
      0 <= idx <= n &&
      num >= 1 &&
      num <= idx + 1 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ lemma index_bound: \forall int *arr, integer n, integer idx, integer num;
      loop_invariant(arr, n, idx, num) ==> idx <= n;
*/

/*@ lemma num_bound: \forall int *arr, integer n, integer idx, integer num;
      loop_invariant(arr, n, idx, num) ==> num <= idx + 1;
*/

/*@
  requires valid_array(a, n);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result < n;
*/
int func(int n, int *a)
{
    int num = 1;
    size_t index = 0;
    
    /*@ loop invariant loop_invariant(a, n, index, num);
        loop assigns num, index;
        loop variant n - index;
    */
    while (index < (size_t)n)
    {
        //@ assert loop_invariant(a, n, index, num);
        if (num <= a[index])
        {
            num++;
        }
        index++;
    }
    
    if (num == n)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
