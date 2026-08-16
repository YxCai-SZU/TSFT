#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) + (b) + (c) + (d)) || \result == ((a) + (b) + (d) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int train_1;
    int train_2;
    int ans;

    train_1 = a + b;
    train_2 = c + d;

    //@ assert train_1 == a + b;
    //@ assert train_2 == c + d;

    if (train_1 > train_2)
    {
        ans = train_1 + train_2;
    }
    else
    {
        ans = train_2 + train_1;
    }

    //@ assert ans == ((a) + (b) + (c) + (d)) || ans == ((a) + (b) + (d) + (c));

    return ans;
}
