#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n/10 == 9 || n%10 == 9);
*/
bool func(int n)
{
    int div;
    int temp_n;
    int count;
    int mod_val;
    bool result;

    div = 0;
    temp_n = n;
    count = 0;

    /*@
        loop invariant 10 <= n <= 99;
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - 10 * count;
        loop invariant 0 <= count <= n / 10;
        loop assigns temp_n, count;
    */
    while (temp_n >= 10)
    {
        //@ assert temp_n == n - 10 * count;
        temp_n -= 10;
        count += 1;
        //@ assert temp_n == n - 10 * count;
    }
    div = count;

    mod_val = temp_n;

    result = false;
    if (div == 9 || mod_val == 9)
    {
        result = true;
    }

    //@ assert result == (div == 9 || mod_val == 9);
    return result;
}
