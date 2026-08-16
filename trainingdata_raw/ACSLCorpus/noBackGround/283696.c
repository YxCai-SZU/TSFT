#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - (((n)) / 15) * 200);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int count;
    int temp_n;
    int i;

    // Variable declarations at scope top
    result = n * 800;
    count = 0;
    temp_n = n;
    i = 15;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant 0 <= count;
        loop invariant 0 <= temp_n;
        loop invariant temp_n == n - count * i;
        loop invariant count <= ((n) / 15);
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= i)
    {
        //@ assert count < ((n) / 15);
        count = count + 1;
        temp_n = temp_n - i;
    }

    //@ assert count == ((n) / 15);
    result = result - count * 200;

    return result;
}
