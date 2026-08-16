#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;

    logic integer mod_two(integer x) = x % 2;

    lemma mod_preserved:
        \forall integer a, b, temp;
        in_range(a) && in_range(b) && temp <= a + b && temp >= 0 && (temp - (a + b)) % 2 == 0 ==>
        mod_two(temp) == mod_two(a + b);
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == ((a + b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    bool is_even;
    unsigned int temp_c;

    c = a + b;
    is_even = false;
    temp_c = c;

    /*@
        loop invariant temp_c <= a + b;
        loop invariant temp_c >= 0;
        loop invariant (temp_c - (a + b)) % 2 == 0;
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant c == a + b;
        loop assigns temp_c;
        loop variant temp_c;
    */
    while (temp_c >= 2)
    {
        temp_c -= 2;
    }

    if (temp_c == 0)
    {
        is_even = true;
    }

    //@ assert is_even == ((a + b) % 2 == 0);

    return is_even;
}
