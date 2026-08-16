#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (n * 800) - ((n / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int count;
    int temp_n;

    result = n * 800;
    count = 0;
    temp_n = n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant 0 <= count <= n / 15;
        loop invariant temp_n + count * 15 == n;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        count = count + 1;
        temp_n = temp_n - 15;
    }

    //@ assert count == n / 15;
    //@ assert temp_n == n - count * 15;

    result = result - count * 200;

    return result;
}
