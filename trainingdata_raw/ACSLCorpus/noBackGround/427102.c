#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((((a)) - ((c))) * (((b)) - ((d))));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    
    x = a - c;
    //@ assert x == ((a) - (c));
    
    y = b - d;
    //@ assert y == ((b) - (d));
    
    //@ assert -99 <= x <= 99;
    //@ assert -99 <= y <= 99;
    
    //@ assert -9801 <= x * y <= 9801;
    
    result = x * y;
    //@ assert result == ((((a)) - ((c))) * (((b)) - ((d))));
    
    return result;
}
