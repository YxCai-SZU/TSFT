#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires \valid(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> ((h)[i] >= 1 && (h)[i] <= 500));
  ensures \result >= 0 && \result <= n;
*/
long func(long n, long k, long *h)
{
    long count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant (\forall integer i; 0 <= i < (n) ==> ((h)[i] >= 1 && (h)[i] <= 500));
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < (size_t)n)
    {
        //@ assert 0 <= index < n;
        if (h[index] >= k)
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}
