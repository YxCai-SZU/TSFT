#include <stdint.h>

/*@
  requires (1 <= (l) && (l) <= (r) && (r) <= 100 && 1 <= (d) && (d) <= 100);
  ensures 0 <= \result && \result <= (r - l + 1);
*/
int32_t func(int32_t l, int32_t r, int32_t d)
{
    int32_t count = 0;
    int32_t i = l;
    //@ assert ((l) <= (i) && (i) <= (r) + 1 &&      0 <= (count) && (count) <= ((i) - (l)) &&      (1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 && 1 <= ((d)) && ((d)) <= 100));
    
    /*@ loop invariant ((l) <= (i) && (i) <= (r) + 1 &&
     0 <= (count) && (count) <= ((i) - (l)) &&
     (1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 && 1 <= ((d)) && ((d)) <= 100));
        loop assigns count, i;
        loop variant r - i + 1;
    */
    while (i <= r) {
        uint32_t l_unsigned = (uint32_t)l;
        uint32_t i_unsigned = (uint32_t)i;
        uint32_t d_unsigned = (uint32_t)d;
        
        //@ assert 1 <= d_unsigned && d_unsigned <= 100;
        if (i_unsigned % d_unsigned == 0) {
            count += 1;
        }
        i += 1;
        //@ assert ((l) <= (i) && (i) <= (r) + 1 &&      0 <= (count) && (count) <= ((i) - (l)) &&      (1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 && 1 <= ((d)) && ((d)) <= 100));
    }
    //@ assert i == r + 1;
    //@ assert 0 <= count && count <= (r - l + 1);
    return count;
}
