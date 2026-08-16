#include <stdbool.h>

/*@
    requires (1 <= (X) <= 100) && (1 <= (Y) <= 100) && ((Y) % 2 == 0);
    ensures \result >= 0 && \result <= X;
    assigns \nothing;
*/
int func(int X, int Y)
{
    int ans = 0;
    int remaining_y = Y;
    int x = X;

    /*@
        loop invariant 0 <= x <= X;
        loop invariant 0 <= remaining_y <= Y;
        loop invariant ans >= 0 && ans <= X;
        loop invariant x + 2 * ans == X;
        loop invariant remaining_y + 2 * ans == Y;
        loop invariant (1 <= (X) <= 100) && (1 <= (Y) <= 100) && ((Y) % 2 == 0);
        loop assigns x, remaining_y, ans;
        loop variant x + remaining_y;
    */
    while (x >= 2 && remaining_y >= 2)
    {
        x -= 2;
        remaining_y -= 2;
        ans += 1;
    }

    if (remaining_y == 0 && x == 0)
    {
        ans += 1;
    }

    return ans;
}
