#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 100000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool can_buy_toy(int a, int b, int c)
{
    //@ assert 1 <= a && a <= 5000;
    //@ assert 1 <= b && b <= 5000;
    //@ assert 1 <= c && c <= 100000;
    
    bool result;
    result = (a + b) >= c;
    
    //@ assert result == (((a) + (b)) >= c);
    return result;
}
