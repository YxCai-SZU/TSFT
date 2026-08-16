#include <stdbool.h>

/*@
    requires (0 <= (a) < 10) && (0 <= (b) < 10);
    ensures \result == ((a & b) == (b & a));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool res;

    //@ assert (0 <= (a) < 10) && (0 <= (b) < 10);
    //@ assert (a & b) == (b & a);
    
    res = ((a & b) == (b & a));
    return res;
}

int main()
{
    return 0;
}
