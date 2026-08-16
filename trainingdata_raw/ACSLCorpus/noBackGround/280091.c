#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000 &&
        1 <= (b) <= 5000 &&
        1 <= (c) <= 10000);
    ensures \result == true <==> a + b >= c;
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int money = 0;

    money += a;
    //@ assert money == a;

    if (money >= c)
    {
        //@ assert money >= c;
        return true;
    }

    money += b;
    //@ assert money == a + b;

    if (money >= c)
    {
        //@ assert money >= c;
        return true;
    }

    //@ assert money < c;
    return false;
}
