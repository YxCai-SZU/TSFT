#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
*/
int func(int n)
{
    int pay;
    int temp;
    int count;

    pay = 0;
    temp = n;
    count = 0;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant temp >= 0;
        loop invariant temp == n - 1000 * count;
        loop invariant count >= 0;
        loop invariant count <= n / 1000;
        loop assigns temp, count;
    */
    while (temp >= 1000)
    {
        //@ assert temp >= 1000;
        temp -= 1000;
        count += 1;
    }

    pay = count * 1000;

    if (temp > 0)
    {
        //@ assert temp > 0;
        pay += 1000;
    }

    //@ assert pay - n == ((1000 - (n) % 1000) % 1000);
    return pay - n;
}
