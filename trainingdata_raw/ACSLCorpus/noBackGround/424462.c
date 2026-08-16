#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(numbers + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000;
  ensures \result >= 0 && \result <= n;
*/
size_t func(size_t n, const long long *numbers)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < n ==> numbers[j] >= 1 && numbers[j] <= 1000;
      loop invariant count >= 0;
      loop invariant count <= i;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n)
    {
        long long x = numbers[i];
        
        //@ assert x >= 1 && x <= 1000;
        
        if ((x & 1) == 0)
        {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}
