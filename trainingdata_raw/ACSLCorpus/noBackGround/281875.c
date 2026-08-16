#include <stddef.h>
#include <stdint.h>

/*@
  requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (x)[i] && (x)[i] <= 5);
  ensures 0 <= \result <= 5;
*/
int64_t func(int64_t* x)
{
    int64_t ans = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= 5;
      loop invariant 0 <= ans <= index;
      loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (x)[i] && (x)[i] <= 5);
      loop assigns ans, index;
    */
    while (index < 5)
    {
        //@ assert 0 <= x[index] <= 5;
        ans += (x[index] > 0) ? 1 : 0;
        index++;
    }
    //@ assert ans >= 0;
    //@ assert ans <= 5;
    return ans;
}
