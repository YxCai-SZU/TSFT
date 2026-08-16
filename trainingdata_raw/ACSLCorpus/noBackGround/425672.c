#include <stdint.h>

/*@
  requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
  ensures ((\result) >= 0 || (\result) == -1);
  ensures \result >= 0 ==> (((\result) * 8) / 100 == (a)) && (((\result) * 10) / 100 == (b));
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t x = 0;
    //@ ghost uint32_t original_a = a;
    //@ ghost uint32_t original_b = b;
    
    /*@
      loop invariant 0 <= x <= 1001;
      loop invariant (1 <= (original_a) && (original_a) <= 100) && (1 <= (original_b) && (original_b) <= 100);
      loop assigns x;
      loop variant 1001 - x;
    */
    while (x <= 1000)
    {
        uint32_t aa = (x * 8) / 100;
        uint32_t bb = (x * 10) / 100;
        
        if (aa == a && bb == b)
        {
            //@ assert aa == (x * 8) / 100;
            //@ assert bb == (x * 10) / 100;
            //@ assert aa == original_a;
            //@ assert bb == original_b;
            //@ assert (((x) * 8) / 100 == (original_a));
            //@ assert (((x) * 10) / 100 == (original_b));
            return (int32_t)x;
        }
        x = x + 1;
    }
    return -1;
}
