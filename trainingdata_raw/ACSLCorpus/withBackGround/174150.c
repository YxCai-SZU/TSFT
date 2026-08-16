#include <stdbool.h>

/*@
    predicate can_buy_pred(integer a, integer b, integer c) =
        a + b >= c;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <==> can_buy_pred(a, b, c);
    assigns \nothing;
*/
bool can_buy_toy(int a, int b, int c)
{
    bool can_buy;
    
    //@ assert a + b >= c <==> a + b >= c;
    
    can_buy = (a + b >= c);
    return can_buy;
}

int main()
{
    return 0;
}
