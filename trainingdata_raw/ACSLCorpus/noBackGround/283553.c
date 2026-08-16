#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ( (a * b * 2) % 2 != 0 );
*/
bool func(int a, int b)
{
    int product;
    int remainder;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    
    product = a * b * 2;
    remainder = product;
    
    /*@
        loop invariant 1 <= a <= 3;
        loop invariant 1 <= b <= 3;
        loop invariant remainder <= product;
        loop invariant remainder >= 0;
        loop invariant remainder % 2 == product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }
    
    //@ assert remainder == product % 2;
    
    return remainder != 0;
}
