#include <stddef.h>

/*@ requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
      1 <= (c) && (c) <= 20);
    ensures ((\result) >= 0 &&
      (\result) <= (c) &&
      ((a) > (b) + (c) ==> (\result) == 0) &&
      ((a) == (b) + (c) ==> (\result) == 1) &&
      ((a) < (b) + (c) ==> (\result) == (b) + (c) - (a)));
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&       1 <= (c) && (c) <= 20);
    
    if (a > b + c) {
        result = 0;
        //@ assert result == 0;
    } else if (a == b + c) {
        result = 1;
        //@ assert result == 1;
    } else {
        //@ assert b + c <= 40;
        //@ assert b + c - a <= 40;
        result = b + c - a;
        //@ assert result == b + c - a;
    }
    
    //@ assert ((result) >= 0 &&       (result) <= (c) &&       ((a) > (b) + (c) ==> (result) == 0) &&       ((a) == (b) + (c) ==> (result) == 1) &&       ((a) < (b) + (c) ==> (result) == (b) + (c) - (a)));
    return result;
}
