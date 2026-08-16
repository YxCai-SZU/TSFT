#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \valid((numbers) + (0 .. 2)) &&
        (-100 <= ((numbers)[0]) <= 100) &&
        (-100 <= ((numbers)[1]) <= 100) &&
        (-100 <= ((numbers)[2]) <= 100));
    ensures \result == ((((numbers[0]) <= (numbers[2]) && (numbers[2]) <= (numbers[1])) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int *numbers)
{
    int a;
    int b;
    int c;

    a = numbers[0];
    b = numbers[1];
    c = numbers[2];

    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);

    return a <= c && c <= b;
}
