#include <stddef.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
size_t func(size_t a)
{
    size_t a_2;
    size_t a_3;
    size_t a_4;
    size_t a_5;
    size_t a_6;
    size_t result;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_3 = a_2 * a;
    a_4 = a_3;
    a_5 = a_2;
    a_6 = a;
    result = a_4 + a_5 + a_6;
    //@ assert result == a + a * a + a * a * a;
    return result;
}
