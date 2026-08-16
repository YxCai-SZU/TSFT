#include <stdint.h>

/*@
requires (\valid((input)) &&
    \valid((input) + 1) &&
    \valid((input) + 2) &&
    1 <= (input)[0] && (input)[0] <= 20 &&
    1 <= (input)[1] && (input)[1] <= 20 &&
    1 <= (input)[2] && (input)[2] <= 20);
ensures \result == ((input[2]) * (input[1]) - (input[0]));
*/
int32_t func(int32_t* input)
{
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t volume;
    
    //@ assert input[0] >= 1 && input[0] <= 20;
    a = input[0];
    
    //@ assert input[1] >= 1 && input[1] <= 20;
    b = input[1];
    
    //@ assert input[2] >= 1 && input[2] <= 20;
    c = input[2];
    
    //@ assert 1 <= c && c <= 20;
    //@ assert 1 <= b && b <= 20;
    
    //@ assert 1 <= c * b && c * b <= 400;
    
    volume = c * b - a;
    
    //@ assert volume == ((c) * (b) - (a));
    return volume;
}
