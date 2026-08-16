#include <stdbool.h>

/*@
    requires (0 <= (x) <= 100000000000000000) && (0 <= (y) <= 100000000000000000);
    ensures ((\result) == ((x) % 2 == 0 && (y) % 2 == 0 && (y) >= 2*(x) && (y) <= 4*(x)));
    assigns \nothing;
*/
bool func(long long x, long long y)
{
    bool is_even_x = false;
    bool is_even_y = false;
    long long temp_x = x;
    long long temp_y = y;
    bool result;

    // Check if x is even
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x % 2 == x % 2;
        loop assigns temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 2)
    {
        temp_x -= 2;
    }
    if (temp_x == 0)
    {
        is_even_x = true;
    }

    // Check if y is even
    /*@
        loop invariant 0 <= temp_y <= y;
        loop invariant temp_y % 2 == y % 2;
        loop assigns temp_y;
        loop variant temp_y;
    */
    while (temp_y >= 2)
    {
        temp_y -= 2;
    }
    if (temp_y == 0)
    {
        is_even_y = true;
    }

    if (is_even_x && is_even_y && y >= 2 * x && y <= 4 * x)
    {
        result = true;
        //@ assert result == true;
        return result;
    }
    else
    {
        result = false;
        //@ assert result == false;
        return result;
    }
}

int main()
{
    return 0;
}
