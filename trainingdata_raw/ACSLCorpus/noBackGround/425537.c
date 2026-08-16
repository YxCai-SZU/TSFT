#include <stdint.h>

/*@
    requires (-46340 <= (x) && (x) <= 46340);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int32_t square(int32_t x)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert (-46340 <= (x) && (x) <= 46340);
    //@ assert -46340 * 46340 <= x * x && x * x <= 46340 * 46340;
    
    result = x * x;
    //@ assert result == ((x) * (x));
    return result;
}

void print_square(int32_t i);

int main()
{
    // Variable declarations at top of scope
    int32_t result;
    
    result = square(100);
    //@ assert result == 10000;
    print_square(result);
    
    return 0;
}
