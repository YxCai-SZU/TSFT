#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1000 * (x / 500) + 5 * ((x % 500) / 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t number_500;
    uint32_t remain;
    uint32_t number_5;
    uint32_t result;

    //@ assert (1 <= (x) <= 100000);
    
    number_500 = x / 500;
    remain = x % 500;
    number_5 = remain / 5;

    //@ assert number_500 == ((x) / 500);
    //@ assert remain == ((x) % 500);
    //@ assert number_5 == (((x) % 500) / 5);
    
    //@ assert number_500 <= 200;
    //@ assert number_5 <= 100;
    //@ assert 1000 * number_500 <= 200000;
    //@ assert 5 * number_5 <= 500;
    //@ assert 1000 * number_500 + 5 * number_5 <= 200500;

    result = 1000 * number_500 + 5 * number_5;
    
    //@ assert result == 1000 * (x / 500) + 5 * ((x % 500) / 5);
    return result;
}
