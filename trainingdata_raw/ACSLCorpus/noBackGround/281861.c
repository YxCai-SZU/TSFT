#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == ((a) + (b) + (c)) ||
            \result == ((a) + (c) + (d)) ||
            \result == ((a) + (b) + (d)) ||
            \result == ((b) + (c) + (d));
    ensures -300 <= \result <= 300;
*/
int func(int a, int b, int c, int d)
{
    int max_value;
    int temp_value;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);

    max_value = a + b + c;
    //@ assert max_value == ((a) + (b) + (c));

    temp_value = a + c + d;
    //@ assert temp_value == ((a) + (c) + (d));

    if (temp_value > max_value)
    {
        max_value = temp_value;
    }

    temp_value = a + b + d;
    //@ assert temp_value == ((a) + (b) + (d));

    if (temp_value > max_value)
    {
        max_value = temp_value;
    }

    temp_value = b + c + d;
    //@ assert temp_value == ((b) + (c) + (d));

    if (temp_value > max_value)
    {
        max_value = temp_value;
    }

    //@ assert max_value == ((a) + (b) + (c)) || max_value == ((a) + (c) + (d)) || max_value == ((a) + (b) + (d)) || max_value == ((b) + (c) + (d));
    return max_value;
}
