#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == n * 800 - ((n / 15) * 200) - (((n % 15) / 6) * 80);
    assigns \nothing;
*/
int func(int n)
{
    int result = 0;
    int temp_n = n;
    int count_15 = 0;
    int count_6 = 0;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert temp_n == n && count_15 == 0 && count_6 == 0;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant count_15 >= 0;
        loop invariant temp_n == ((n) - 15 * (count_15));
        loop invariant count_15 <= n / 15;
        loop assigns temp_n, count_15;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        count_15 += 1;
        //@ assert temp_n == ((n) - 15 * (count_15));
    }

    //@ assert temp_n == n - 15 * count_15;
    //@ assert temp_n < 15;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant count_6 >= 0;
        loop invariant temp_n == ((n) - 15 * (count_15) - 6 * (count_6));
        loop invariant count_6 <= (n - 15 * count_15) / 6;
        loop assigns temp_n, count_6;
        loop variant temp_n;
    */
    while (temp_n >= 6)
    {
        //@ assert temp_n >= 6;
        temp_n -= 6;
        count_6 += 1;
        //@ assert temp_n == ((n) - 15 * (count_15) - 6 * (count_6));
    }

    //@ assert temp_n == n - 15 * count_15 - 6 * count_6;
    //@ assert temp_n < 6;

    result = n * 800 - count_15 * 200 - count_6 * 80;
    //@ assert result == n * 800 - count_15 * 200 - count_6 * 80;
    
    return result;
}

int main()
{
    return 0;
}
