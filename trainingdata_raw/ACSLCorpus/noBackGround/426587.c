#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((((a)) + ((b)) + ((c))) + (((a)) * ((b)) * ((c))));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int sum;
    int product;
    int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    sum = a + b + c;
    //@ assert sum == ((a) + (b) + (c));
    
    //@ assert 1 <= a * b <= 10000;
    product = a * b * c;
    //@ assert product == ((a) * (b) * (c));
    
    //@ assert sum <= 300;
    //@ assert product <= 1000000;
    
    result = sum + product;
    //@ assert result == ((((a)) + ((b)) + ((c))) + (((a)) * ((b)) * ((c))));
    
    return result;
}
