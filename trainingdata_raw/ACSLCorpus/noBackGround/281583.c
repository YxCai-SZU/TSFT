#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100);
    requires ((a) != (b) && (a) != (c) && (b) != (c));
    ensures \result == ((((a) < (b) && (c) > (a) && (c) < (b)) || ((a) > (b) && (c) < (a) && (c) > (b)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (b) && (b) <= 100 &&         0 <= (c) && (c) <= 100);
    //@ assert ((a) != (b) && (a) != (c) && (b) != (c));
    
    result = (a < b && c > a && c < b) || (a > b && c < a && c > b);
    
    //@ assert result == ((((a) < (b) && (c) > (a) && (c) < (b)) || ((a) > (b) && (c) < (a) && (c) > (b)) ? 1 : 0) == 1);
    return result;
}

int main(void)
{
    return 0;
}
