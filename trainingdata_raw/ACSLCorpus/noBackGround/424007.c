#include <stdbool.h>
#include <stdint.h>

/*@
  requires 3 <= n <= 20;
  requires \valid(p+(0..n-1));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
  ensures \result >= 0;
  ensures \result <= n - 2;
*/
int32_t func(uint32_t n, int32_t *p)
{
    int32_t count = 0;
    int32_t i = 2;
    /*@
      loop invariant 2 <= i <= n-1;
      loop invariant count >= 0;
      loop invariant count <= i-2;
      loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
      loop assigns i, count;
      loop variant n-1-i;
    */
    while (i < (int32_t)n - 1)
    {
        //@ assert (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        //@ assert (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
        if ((p[i] < p[i-1] && p[i-1] < p[i+1]) ||
            (p[i] > p[i-1] && p[i-1] > p[i+1]))
        {
            count += 1;
        }
        i += 1;
    }
    return count;
}
