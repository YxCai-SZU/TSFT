#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires 2 <= n <= 1000000;
  requires \valid(a + (0..(n-2)));
  requires ((n-1) == (n) - 1 &&
      \forall integer i; 0 <= i < (n-1) ==> (a)[i] >= 1 && (a)[i] < (n));
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
int64_t func(int64_t n, const int64_t *a)
{
    int64_t counter = 0;
    int64_t x = 1;
    size_t a_len = (size_t)(n - 1);
    
    /*@
      loop invariant 1 <= x <= n;
      loop invariant 0 <= counter <= x - 1;
      loop invariant a_len == n - 1;
      loop assigns counter, x;
      loop variant n - x;
    */
    while (x < n)
    {
        size_t index = (size_t)(x - 1);
        
        //@ assert index == (size_t)(x - 1);
        
        if (index < a_len && x == a[index])
        {
            //@ assert x == a[index];
            counter = counter + 1;
        }
        
        //@ assert x < n;
        x = x + 1;
    }
    
    //@ assert 0 <= counter <= n;
    return counter;
}
