#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 100) >= ((((x) % 100)) / 5 + (((x) % 100)) % 5));
*/
bool func(unsigned int x)
{
    unsigned int t;
    unsigned int Y;
    unsigned int ans;
    unsigned int temp_y;

    t = x / 100;
    Y = x % 100;
    ans = 0;
    temp_y = Y;

    /*@
        loop invariant 0 <= temp_y <= Y;
        loop invariant 0 <= ans <= Y / 5;
        loop invariant temp_y == Y - 5 * ans;
        loop invariant (1 <= (x) <= 100000);
        loop assigns ans, temp_y;
    */
    while (temp_y >= 5)
    {
        //@ assert temp_y >= 5;
        ans += 1;
        temp_y -= 5;
    }

    //@ assert temp_y == Y % 5;
    ans += temp_y;

    //@ assert ans == Y / 5 + Y % 5;
    return t >= ans;
}
