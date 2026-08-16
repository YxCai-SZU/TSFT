#include <stdbool.h>

/*@
    requires n <= 100;
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    requires 0 <= z <= 100;
    ensures \result == ((x * x <= n) || (y * y <= n) || (z * z <= n));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int x_squared;
    unsigned int y_squared;
    unsigned int z_squared;
    bool result;

    //@ assert 0 <= x <= 100 && 0 <= y <= 100 && 0 <= z <= 100;
    
    //@ assert x * x <= 10000;
    //@ assert y * y <= 10000;
    //@ assert z * z <= 10000;

    x_squared = x * x;
    y_squared = y * y;
    z_squared = z * z;

    result = (x_squared <= n) || (y_squared <= n) || (z_squared <= n);
    
    //@ assert result == ((x * x <= n) || (y * y <= n) || (z * z <= n));
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
