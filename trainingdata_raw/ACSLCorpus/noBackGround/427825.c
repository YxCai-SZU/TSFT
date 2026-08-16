#include <stdint.h>

/*@
  requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
  ensures \result == (a * b) / 2;
  assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t product;
    uint32_t result;
    uint32_t count;
    uint32_t temp;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    
    product = a * b;
    
    //@ assert 1 <= product <= 100;
    
    result = 0;
    count = 0;
    temp = product;
    
    /*@
      loop invariant 1 <= a <= 10;
      loop invariant 1 <= b <= 10;
      loop invariant 1 <= c <= 10;
      loop invariant temp >= 0;
      loop invariant temp == product - 2 * count;
      loop invariant 0 < count ==> count <= product / 2;
      loop assigns temp, count;
      loop variant temp;
    */
    while (temp >= 2) {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp == product - 2 * count;
    }
    
    result = count;
    
    //@ assert result == (a * b) / 2;
    return result;
}
