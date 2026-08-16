#include <stdint.h>

/*@
    requires (-100 <= (x) <= 100);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int32_t cubical(int32_t x)
{
    // Variable declarations at top
    int32_t result;
    
    //@ assert (-100 <= (x) <= 100);
    //@ assert -10000 <= x * x <= 10000;
    
    result = x * x * x;
    
    //@ assert result == ((x) * (x) * (x));
    return result;
}

/*@
    assigns \nothing;
*/
void print_result(int32_t i)
{
    // Implementation omitted for verification
}

/*@
    assigns \nothing;
*/
int main()
{
    // Variable declarations at top
    int32_t n;
    
    n = cubical(5);
    //@ assert n == 125;
    print_result(n);
    
    return 0;
}
