#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <==> (((a + b + c) % 2 == 0) && ((a) == (b) || (b) == (c) || (a) == (c) ||
        (a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a)));
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long sum;
    bool is_even_val;
    bool result;

    sum = a + b + c;
    is_even_val = (sum % 2 == 0);
    //@ assert is_even_val <==> ((sum) % 2 == 0);
    
    result = is_even_val &&
             ((a == b) || (b == c) || (a == c) ||
              (a + b == c) || (a + c == b) || (b + c == a));
    
    return result;
}
