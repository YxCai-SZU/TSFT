#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ( (a * b) / 2 >= c );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int product;
    bool is_enough;
    unsigned int temp;
    unsigned int count;

    // Precondition assertions
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    // Overflow safety
    //@ assert a * b <= 10000;

    product = a * b;
    is_enough = false;
    temp = product;
    count = 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant temp >= 0;
        loop invariant temp == product - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= product / 2;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp == product - 2 * count;
    }

    // Post-loop state
    //@ assert temp < 2;
    //@ assert count == product / 2;

    if (count >= c)
    {
        is_enough = true;
    }

    // Final verification
    //@ assert is_enough == ( (a * b) / 2 >= c );
    return is_enough;
}
