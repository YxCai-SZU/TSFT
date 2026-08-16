#include <stdint.h>

/*@
    requires (\valid((input) + (0..3)) &&
        1 <= (input)[0] <= 100 &&
        1 <= (input)[1] <= 100 &&
        1 <= (input)[2] <= 100 &&
        1 <= (input)[3] <= 100);
    ensures \result == ((input)[0] * (input)[1]) || \result == ((input)[2] * (input)[3]);
    ensures \result >= ((input)[0] * (input)[1]);
    ensures \result >= ((input)[2] * (input)[3]);
    assigns \nothing;
*/
int64_t func(const int64_t *input)
{
    int64_t product1;
    int64_t product2;
    int64_t result;

    //@ assert 1 <= input[0] <= 100;
    product1 = input[0] * input[1];
    
    //@ assert 1 <= input[2] <= 100;
    product2 = input[2] * input[3];

    if (product1 > product2)
    {
        result = product1;
    }
    else
    {
        result = product2;
    }

    return result;
}
