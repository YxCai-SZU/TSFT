#include <stddef.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100);
    ensures ((\result) <= (a) &&
      ((\result) == 0 || ((a) >= (b) * 2 && (a) <= (b) * 4 && (a) % 2 == 0 && (b) <= (a) / 2)));
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 100);
    
    if (a >= b * 2 && a <= b * 4 && a % 2 == 0 && b <= a / 2)
    {
        //@ assert a / 2 <= a;
        result = a / 2;
    }
    else
    {
        //@ assert 0 <= a;
        result = 0;
    }

    //@ assert ((result) <= (a) &&       ((result) == 0 || ((a) >= (b) * 2 && (a) <= (b) * 4 && (a) % 2 == 0 && (b) <= (a) / 2)));
    return result;
}
