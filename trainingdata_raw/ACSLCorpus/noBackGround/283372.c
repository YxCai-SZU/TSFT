#include <stdbool.h>
#include <stdint.h>

/*@ requires 0 <= length <= 0xFFFFFFFF;
    ensures \result == (length % 2 == 0);
    assigns \nothing;
*/
bool is_even_func(uint32_t length)
{
    //@ assert 0 <= length <= 0xFFFFFFFF;
    return length % 2 == 0;
}

/*@ requires 0 <= length <= 0xFFFFFFFF && length > 0;
    ensures \result <= length;
    assigns \nothing;
*/
uint32_t min_even_odd(uint32_t length)
{
    //@ assert length > 0;
    //@ assert length >= 1;
    
    bool even = is_even_func(length);
    
    if (even) {
        //@ assert length % 2 == 0;
        //@ assert 2 <= length;
        return 2;
    } else {
        //@ assert length % 2 != 0;
        //@ assert 1 <= length;
        return 1;
    }
}
