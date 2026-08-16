#include <stdbool.h>


bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int div_result;
    unsigned int scaled;
    bool result;

    //@ assert (1 <= (k) <= 1000 &&         1 <= (a) <= (b) <= 1000);
    
    div_result = b / k;
    //@ assert div_result <= b;
    
    scaled = div_result * k;
    //@ assert scaled == (((b) / (k)) * (k));
    
    //@ assert scaled <= b;
    
    result = (scaled >= a) && (b >= a);
    return result;
}
