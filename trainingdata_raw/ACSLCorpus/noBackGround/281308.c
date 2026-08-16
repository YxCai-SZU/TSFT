#include <stdbool.h>
#include <stdint.h>

/*@
  requires 0 <= x <= 9;
  requires 0 <= a <= 9;
  ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
*/
uint32_t func(uint32_t x, uint32_t a)
{
    uint32_t res;
    //@ assert 0 <= x <= 9;
    //@ assert 0 <= a <= 9;
    
    if (x < a) {
        res = 0;
    } else {
        res = 10;
    }
    
    //@ assert (x < a ==> res == 0) && (x >= a ==> res == 10);
    return res;
}

/*@
  requires 1 <= a <= 10;
  requires 1 <= b <= 10;
  requires 1 <= c <= 10;
  ensures \result <==> ((a) < (b) && (b) < (c));
*/
bool test_range(uint32_t a, uint32_t b, uint32_t c)
{
    bool result;
    //@ assert 1 <= a <= 10;
    //@ assert 1 <= b <= 10;
    //@ assert 1 <= c <= 10;
    
    result = (a < b) && (b < c);
    
    //@ assert result <==> ((a) < (b) && (b) < (c));
    return result;
}
