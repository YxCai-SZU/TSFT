#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (x + (100 - x) * 2 >= y);
*/
bool func(int x, int y)
{
    int remainder;
    int product;
    int sum;
    bool result;

    remainder = 100 - x;
    //@ assert (0 <= (remainder) <= 99);
    
    product = remainder * 2;
    //@ assert (0 <= (product) <= 198);
    
    sum = x + product;
    //@ assert sum == ((x) + (remainder) * 2);
    
    result = sum >= y;
    return result;
}
