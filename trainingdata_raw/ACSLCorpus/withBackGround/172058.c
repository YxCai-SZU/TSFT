#include <stdint.h>

/*@
    predicate input_in_range(integer i) = -1290 <= i && i <= 1290;
    
    logic integer poly_result(integer i) = i * i * i - 3 * i;
*/

/*@
    requires input_in_range(input);
    ensures \result == poly_result(input);
    assigns \nothing;
*/
int64_t func(int64_t input)
{
    int64_t result;
    
    //@ assert input >= -1290 && input <= 1290;
    //@ assert input * input >= -1290 * 1290 && input * input <= 1290 * 1290;
    //@ assert input * input * input >= -1290 * 1290 * 1290 && input * input * input <= 1290 * 1290 * 1290;
    //@ assert 3 * input >= -3 * 1290 && 3 * input <= 3 * 1290;
    //@ assert input * input * input - 3 * input >= -1290 * 1290 * 1290 - 3 * 1290 && input * input * input - 3 * input <= 1290 * 1290 * 1290 - 3 * 1290;
    
    result = input * input * input - 3 * input;
    return result;
}

int main()
{
    return 0;
}
