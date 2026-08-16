#include <stdbool.h>
#include <stdint.h>

/*@
  requires n > 0 && n <= 200000;
  requires \valid_read(numbers + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) <= 1000000000));
  ensures \result >= 0 && \result <= n;
*/
int32_t func(uint64_t n, int64_t *numbers)
{
    int32_t count = 0;
    uint64_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) <= 1000000000));
      loop assigns index, count;
    */
    while (index < n)
    {
        //@ assert (0 <= (index) < (n));
        //@ assert ((numbers[index]) > 0 && (numbers[index]) <= 1000000000);
        
        if ((numbers[index] & 1) != 0)
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}
