#include <stdbool.h>

/*@
    requires (0 <= (a) <= 20) && (0 <= (b) <= 20) && (0 <= (c) <= 20);
    ensures \result == true <==> 
            (((a) * (b)) <= 100 && ((b) * (c)) <= 100 && ((a) * (c)) <= 100);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (0 <= (a) <= 20);
    //@ assert (0 <= (b) <= 20);
    //@ assert (0 <= (c) <= 20);

    //@ assert 0 <= ((a) * (b)) <= 400;
    //@ assert 0 <= ((b) * (c)) <= 400;
    //@ assert 0 <= ((a) * (c)) <= 400;

    result = (a * b <= 100) && (b * c <= 100) && (a * c <= 100);
    return result;
}
