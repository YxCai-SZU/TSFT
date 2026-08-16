#include <stdbool.h>

/*@
    requires ((((a)) > 0) && (((b)) > 0) && (((a)) < 0x80000000) && (((b)) < 0x80000000));
    ensures \result == (a <= b ? 1 : 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert ((a) > 0);
    result = (a <= b);
    
    return result;
}

int main(void)
{
    return 0;
}
