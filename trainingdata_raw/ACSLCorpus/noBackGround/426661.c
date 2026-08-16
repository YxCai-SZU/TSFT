#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 10000) && (1 <= (y) && (y) <= 10000);
    ensures \result == (((((x) * (y))) % 2) == 0);
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int z;
    bool is_even = false;
    unsigned int temp;

    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= y && y <= 10000;
    
    //@ assert 1 <= ((x) * (y)) && ((x) * (y)) <= 10000 * 10000;
    z = x * y;
    temp = z;

    /*@
        loop invariant 0 <= temp && temp <= ((x) * (y));
        loop invariant ((temp) % 2) == ((z) % 2);
        loop assigns temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (((((x) * (y))) % 2) == 0);
    return is_even;
}
