#include <stdbool.h>


bool func(int k, int x)
{
    int k_converted;
    
    //@ assert (1 <= (k) && (k) <= 100 &&         1 <= (x) && (x) <= 100000);
    k_converted = k * 500;
    
    //@ assert k_converted == ((k) * 500);
    
    return k_converted >= x;
}
