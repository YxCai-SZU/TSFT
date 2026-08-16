#include <limits.h>


int func(int a)
{
    // Declare all variables at the top
    int result;

    //@ assert a >= -1290 && a <= 1290;
    
    //@ assert a * a >= -1290 * 1290 && a * a <= 1290 * 1290;
    
    //@ assert a * a * a >= -1290 * 1290 * 1290 && a * a * a <= 1290 * 1290 * 1290;
    
    result = a * a * a;
    
    //@ assert result == ((a) * (a) * (a));
    
    return result;
}
