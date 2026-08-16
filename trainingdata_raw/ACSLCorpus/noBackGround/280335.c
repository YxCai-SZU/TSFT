#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool result;
    
    //@ assert 500 <= 500 * k <= 50000;
    result = (500 * k >= x);
    
    //@ assert result == (500 * k >= x);
    return result;
}

int main()
{
    int k;
    int x;
    bool res;
    
    k = 50;
    x = 10000;
    
    //@ assert (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    res = func(k, x);
    return 0;
}
