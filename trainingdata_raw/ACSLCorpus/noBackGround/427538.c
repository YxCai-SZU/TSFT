#include <stdbool.h>

/*@ requires 1 <= a && a <= 100;
    requires 0 <= b && b <= a;
    ensures \result == (a % 3 == 0 || a % 5 == 0 || b != 0);
*/
bool func(int a, int b)
{
    bool is_divisible_by_3 = false;
    bool is_divisible_by_5 = false;
    int temp;

    // Check if a is divisible by 3
    temp = a;
    /*@ loop invariant 1 <= a && a <= 100;
        loop invariant 0 <= b && b <= a;
        loop invariant temp >= 0;
        loop invariant temp <= a;
        loop invariant ((temp) % 3 == (a) % 3);
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3)
    {
        //@ assert ((temp) % 3 == (a) % 3);
        temp = temp - 3;
    }
    if (temp == 0)
    {
        is_divisible_by_3 = true;
    }

    // Check if a is divisible by 5
    temp = a;
    /*@ loop invariant 1 <= a && a <= 100;
        loop invariant 0 <= b && b <= a;
        loop invariant temp >= 0;
        loop invariant temp <= a;
        loop invariant ((temp) % 5 == (a) % 5);
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 5)
    {
        //@ assert ((temp) % 5 == (a) % 5);
        temp = temp - 5;
    }
    if (temp == 0)
    {
        is_divisible_by_5 = true;
    }

    return is_divisible_by_3 || is_divisible_by_5 || b != 0;
}
