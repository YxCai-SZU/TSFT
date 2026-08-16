#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == (k <= ((n) / 2 + (n) % 2));
    assigns \nothing;
*/
bool func(int n, int k)
{
    int n2 = n;
    int count = 0;

    /*@
        loop invariant 0 <= n2 <= n;
        loop invariant 0 <= count <= n / 2;
        loop invariant n2 == n - 2 * count;
        loop invariant 1 <= n <= 100;
        loop invariant 1 <= k <= 100;
        loop assigns n2, count;
        loop variant n2;
    */
    while (n2 >= 2)
    {
        n2 -= 2;
        count += 1;
    }

    if (n2 == 1)
    {
        count += 1;
    }

    //@ assert count == ((n) / 2 + (n) % 2);
    return count >= k;
}
