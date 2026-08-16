#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
*/
int64_t func(int64_t a)
{
    int64_t result;

    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a * a && a * a <= 100;
    result = a;
    result = result + (a * a);
    //@ assert result == a + (a * a);

    //@ assert a * a * a >= 0;
    //@ assert a * a * a <= 1000;
    //@ assert a + (a * a) >= 0;
    //@ assert a + (a * a) <= 110;
    //@ assert a + (a * a) + (a * a * a) >= 0;
    //@ assert a + (a * a) + (a * a * a) <= 1110;

    result = result + (a * a * a);
    //@ assert result == a + (a * a) + (a * a * a);
    return result;
}
