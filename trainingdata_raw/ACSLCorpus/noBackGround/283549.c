#include <stdbool.h>

/*@
    requires 100 <= a <= 999;
    ensures \result == true <==> (((a) / 100) == 7 ||
        (((a) / 10) % 10) == 7 ||
        ((a) % 10) == 7);
    assigns \nothing;
*/
bool func(int a)
{
    bool ans = false;
    int temp_a = a;
    int last_digit;
    int mid_digit;

    last_digit = temp_a % 10;
    //@ assert last_digit == a % 10;
    if (last_digit == 7)
    {
        ans = true;
    }

    temp_a /= 10;
    mid_digit = temp_a % 10;
    //@ assert mid_digit == (a / 10) % 10;
    if (mid_digit == 7)
    {
        ans = true;
    }

    temp_a /= 10;
    //@ assert temp_a == a / 100;
    if (temp_a == 7)
    {
        ans = true;
    }

    //@ assert ans == true <==> (((a) / 100) == 7 ||         (((a) / 10) % 10) == 7 ||         ((a) % 10) == 7);
    return ans;
}
