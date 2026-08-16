#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint64_t a, uint64_t b)
{
    uint64_t total;
    uint64_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    
    total = a + (b * 2);
    //@ assert total == ((a) + ((b) * 2));
    
    result = total / 2;
    //@ assert result == ((((a)) + (((b)) * 2)) / 2);
    
    if (result == total - result)
    {
        //@ assert result == total - result;
        return 0;
    }
    else
    {
        //@ assert result != total - result;
        return 1;
    }
}
