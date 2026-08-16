#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
*/
int func(int n)
{
    unsigned int n_unsigned;
    unsigned int pay;
    int pay_signed;
    int result;

    //@ assert (1 <= (n) <= 10000);

    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }

    //@ assert n_unsigned == (n < 0 ? (unsigned int)(-n) : (unsigned int)n);

    pay = (n_unsigned + 999) / 1000;

    //@ assert pay == (n_unsigned + 999) / 1000;

    pay_signed = (int)pay;

    //@ assert pay_signed == (int)pay;

    result = pay_signed * 1000 - n;

    //@ assert result == pay_signed * 1000 - n;

    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == ((1000 - (n) % 1000) % 1000);

    return result;
}
