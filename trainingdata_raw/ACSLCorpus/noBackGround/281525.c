#include <stdbool.h>

/*@
    requires (1 <= (a) <= 123) && (1 <= (b) <= 123) && (1 <= (c) <= 123) && (1 <= (d) <= 123) && (1 <= (e) <= 123);
    ensures \result == (a + b + c + d >= e);
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e)
{
    unsigned int sum;
    unsigned int i;
    
    sum = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant sum >= 0;
        loop invariant sum <= 492;
        loop invariant sum == (((i) > 0 ? (a) : 0) + ((i) > 1 ? (b) : 0) + ((i) > 2 ? (c) : 0) + ((i) > 3 ? (d) : 0));
        loop assigns sum, i;
    */
    while (i < 4)
    {
        //@ assert i < 4;
        
        if (i == 0)
        {
            sum += a;
        }
        else if (i == 1)
        {
            sum += b;
        }
        else if (i == 2)
        {
            sum += c;
        }
        else if (i == 3)
        {
            sum += d;
        }
        
        i++;
    }
    
    //@ assert sum == a + b + c + d;
    
    return sum >= e;
}
