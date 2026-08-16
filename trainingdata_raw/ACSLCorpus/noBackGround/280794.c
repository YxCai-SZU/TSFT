#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 31415 * r) / 10000;
*/
int func(int r)
{
    int pi_approx = 31415;
    int circumference = 0;
    int temp = 2 * pi_approx * r;
    int divisor = 10000;

    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (31415)== 31415;
    //@ assert divisor == 10000;
    //@ assert temp == 2 * (31415)* r;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= circumference <= (2 * 31415 * 100) / 10000;
        loop invariant temp >= 0;
        loop invariant temp == (2 * (31415)* r) - (circumference * divisor);
        loop invariant circumference * 10000 + temp == 2 * (31415)* r;
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        circumference += 1;
    }

    //@ assert circumference * 10000 + temp == 2 * (31415)* r;
    //@ assert temp < 10000;

    return circumference;
}

int main()
{
    return 0;
}
