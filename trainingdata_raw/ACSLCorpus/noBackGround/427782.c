#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ( (a * b) % 2 != 0 );
*/
bool func(unsigned long a, unsigned long b)
{
    unsigned long product = a * b;
    long remainder = (long)product;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 0 <= remainder <= product;
    
    /*@
        loop invariant 0 <= remainder <= product;
        loop invariant (product - remainder) % 2 == 0;
        loop assigns remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }
    
    //@ assert remainder < 2;
    
    /*@
        loop invariant -1 <= remainder < 2;
        loop invariant (product - remainder) % 2 == 0;
        loop assigns remainder;
    */
    while (remainder < 0)
    {
        remainder += 2;
    }
    
    //@ assert 0 <= remainder < 2;
    //@ assert remainder == (((a) * (b)) % 2);
    
    return remainder != 0;
}
