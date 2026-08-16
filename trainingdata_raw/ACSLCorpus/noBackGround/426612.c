#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * 800 - (((a)) / 15) * 200);
*/
int func(int a)
{
    int result;
    int quotient;
    int temp_a;
    
    result = a * 800;
    quotient = 0;
    temp_a = a;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_a;
        loop invariant temp_a == a - quotient * 15;
        loop assigns quotient, temp_a;
    */
    while (temp_a >= 15)
    {
        quotient += 1;
        temp_a -= 15;
    }
    
    //@ assert 0 <= quotient * 200 <= 200 * 6;
    
    result -= quotient * 200;
    
    //@ assert result == ((a) * 800 - (((a)) / 15) * 200);
    
    return result;
}
