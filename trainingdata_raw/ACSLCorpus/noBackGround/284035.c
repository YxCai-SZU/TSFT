#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool func(int n)
{
    int count = 0;
    int temp = n;

    /*@
        loop invariant 0 <= count;
        loop invariant count <= n / 2;
        loop invariant temp == ((n) - 2 * (count));
        loop assigns count, temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        count += 1;
        temp -= 2;
    }

    //@ assert count * 2 == n ==> ((n) % 2 == 0);
    return count * 2 == n;
}
