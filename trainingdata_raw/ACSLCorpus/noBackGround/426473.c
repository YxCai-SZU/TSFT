#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == true <==> a * b > c * d;
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    
    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;
    
    unsigned long long product1;
    unsigned long long product2;
    bool result;
    
    product1 = a * b;
    product2 = c * d;
    result = product1 > product2;
    
    return result;
}
