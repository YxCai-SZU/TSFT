#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 9 &&
        1 <= (g) && (g) <= 9 &&
        1 <= (b) && (b) <= 9);
    ensures \result == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    int sum;
    bool is_divisible_by_4;
    int temp_sum;

    sum = r * 100 + g * 10 + b;
    is_divisible_by_4 = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum;
        loop invariant (1 <= (r) && (r) <= 9 &&
        1 <= (g) && (g) <= 9 &&
        1 <= (b) && (b) <= 9);
        loop invariant 1 <= ((r) * 100 + (g) * 10 + (b)) && ((r) * 100 + (g) * 10 + (b)) <= 999;
        loop invariant temp_sum == ((r) * 100 + (g) * 10 + (b)) - 4 * ((((r) * 100 + (g) * 10 + (b)) - temp_sum) / 4);
        loop invariant (((r) * 100 + (g) * 10 + (b)) - temp_sum) % 4 == 0;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4)
    {
        temp_sum -= 4;
    }

    if (temp_sum == 0)
    {
        is_divisible_by_4 = true;
    }

    //@ assert (((r) * 100 + (g) * 10 + (b)) - temp_sum) % 4 == 0;
    //@ assert ((r) * 100 + (g) * 10 + (b)) % 4 == temp_sum % 4;
    //@ assert is_divisible_by_4 == (((r) * 100 + (g) * 10 + (b)) % 4 == 0);

    return is_divisible_by_4;
}
