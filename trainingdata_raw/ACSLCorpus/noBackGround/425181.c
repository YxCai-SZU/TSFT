#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == (
        ((unsigned int)(b * 10 + c) % 4 < 1) ||
        ((unsigned int)(a * 10 + b) % 4 < 1) ||
        ((unsigned int)(a * 10 + c) % 4 < 1)
    );
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    int local_a = a;
    int local_b = b;
    int local_c = c;
    bool result;

    //@ assert (1 <= (local_b) <= 9);
    //@ assert 1 <= local_b * 10 <= 90;

    //@ assert (1 <= (local_a) <= 9);
    //@ assert 1 <= local_a * 10 <= 90;

    //@ assert 1 <= local_b * 10 + local_c <= 99;
    //@ assert 1 <= local_a * 10 + local_b <= 99;
    //@ assert 1 <= local_a * 10 + local_c <= 99;

    if ((unsigned int)(local_b * 10 + local_c) % 4 == 0U) {
        result = true;
        return result;
    }
    if ((unsigned int)(local_a * 10 + local_b) % 4 == 0U) {
        result = true;
        return result;
    }
    if ((unsigned int)(local_a * 10 + local_c) % 4 == 0U) {
        result = true;
        return result;
    }

    result = false;
    return result;
}
