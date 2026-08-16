#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100 && 1 <= (x) && (x) <= 100000);
    ensures \result == ((500 * (k) >= (x) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool result;
    
    //@ assert k <= 100;
    result = (500 * k >= x);
    
    return result;
}

int main()
{
    return 0;
}
