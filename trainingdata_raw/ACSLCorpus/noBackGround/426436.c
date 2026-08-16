#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_value;
    int result;
    int ans;
    int temp_result;
    int count;

    min_value = a < b ? a : b;
    result = min_value;
    if (c < min_value)
    {
        result = c;
    }

    ans = 0;
    temp_result = result;
    count = 0;

    /*@
        loop invariant 0 <= temp_result <= result;
        loop invariant 0 <= count <= result / 2;
        loop invariant temp_result == result - 2 * count;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns temp_result, count;
        loop variant temp_result;
    */
    while (temp_result >= 2)
    {
        temp_result -= 2;
        count += 1;
    }
    ans = count;

    //@ assert ans <= c;
    //@ assert ans >= 0;

    return ans;
}
