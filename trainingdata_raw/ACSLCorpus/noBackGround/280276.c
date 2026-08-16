#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert a * b <= 100 * 100;
    int product = a * b;
    
    //@ assert a + b - 1 <= 199;
    int sum = a + b - 1;
    
    //@ assert product - sum == ((a) * (b) - ((a) + (b) - 1));
    return product - sum;
}
