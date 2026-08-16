#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * (3142)) / (1000));
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3142;
    int two = 2;
    int scale = 1000;
    int circumference = 0;
    int temp_r = r * pi * two;

    //@ assert temp_r == r * pi * (2);

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 3142;
        loop invariant (2)== 2;
        loop invariant scale == 1000;
        loop invariant circumference * scale + temp_r == r * pi * (2);
        loop invariant circumference >= 0;
        loop invariant temp_r >= 0;
        loop assigns circumference, temp_r;
        loop variant temp_r;
    */
    while (temp_r >= scale)
    {
        circumference += 1;
        temp_r -= scale;
    }

    //@ assert circumference * scale + temp_r == r * pi * (2);
    //@ assert circumference == ((2 * (r) * (3142)) / (1000));

    return circumference;
}

int main()
{
    return 0;
}
