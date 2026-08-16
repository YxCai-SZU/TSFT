#include <stdbool.h>

/*@
    requires x < 1000;
    ensures \result <==> (x % 3 == 0 || x % 5 == 0);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    bool is_divisible_by_3 = false;
    bool is_divisible_by_5 = false;
    unsigned int temp_x;

    // Check divisibility by 3
    temp_x = x;
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x % 3 == x % 3;
        loop assigns temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        temp_x -= 3;
    }
    if (temp_x == 0)
    {
        is_divisible_by_3 = true;
    }

    // Check divisibility by 5
    temp_x = x;
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x % 5 == x % 5;
        loop assigns temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        temp_x -= 5;
    }
    if (temp_x == 0)
    {
        is_divisible_by_5 = true;
    }

    return is_divisible_by_3 || is_divisible_by_5;
}

int main()
{
    return 0;
}
