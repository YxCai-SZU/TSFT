#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(int *arr, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate loop_invariant(int *arr, integer n, integer index, integer a) =
      0 <= index <= n &&
      a >= 0 &&
      a <= index &&
      \forall integer i; 0 <= i < index ==> arr[i] >= 1 && arr[i] <= 1000000000 &&
      n >= 1 && n <= 200000;
*/

/*@ lemma index_bound: \forall integer n, index; 
      loop_invariant((int *)0, n, index, 0) ==> index <= n;
*/

/*@ lemma a_non_negative: \forall integer n, index, a; 
      loop_invariant((int *)0, n, index, a) ==> a >= 0;
*/

/*@
  requires n >= 1 && n <= 200000;
  requires \valid_read(numbers + (0 .. n-1));
  requires is_valid_range(numbers, n);
  ensures \result >= 0;
*/
int func(int n, int *numbers)
{
    int a = 0;
    int index = 0;
    
    /*@
      loop invariant loop_invariant(numbers, n, index, a);
      loop assigns a, index;
      loop variant n - index;
    */
    while (index < n)
    {
        int num = numbers[index];
        bool is_even = (num & 1) == 0;
        
        //@ assert num >= 1 && num <= 1000000000;
        
        if (is_even)
        {
            a += 1;
        }
        
        index += 1;
    }
    
    //@ assert a >= 0;
    return a;
}
