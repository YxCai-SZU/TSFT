#include <stdint.h>
#include <stdbool.h>

/*@
  requires 1 <= n <= 200000;
  requires \valid(p + (0 .. n-1));
  requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] < (p)[j]);
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result < (int64_t)n;
*/
int64_t func(uint64_t n, uint64_t *p)
{
    uint64_t target = 1;
    uint64_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n;
      loop invariant target >= 1;
      loop assigns index, target;
    */
    while (index < n)
    {
        //@ assert index < n;
        if (p[index] < target)
        {
            //@ assert p[index] < target;
            return -1;
        }
        //@ assert p[index] >= target;
        target = p[index];
        index++;
    }
    //@ assert index == n;
    return 0;
}
