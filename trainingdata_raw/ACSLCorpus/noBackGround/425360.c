#include <stdbool.h>

/*@
    requires 10 <= a <= 99;
    ensures \result == 1 <==> (((a) / 10) == ((a) % 10));
    assigns \nothing;
*/
bool check_digit(unsigned long long a)
{
    unsigned long long d1;
    unsigned long long d2;
    bool result;

    d1 = a / 10;
    d2 = a % 10;

    //@ assert d1 == (a / 10);
    //@ assert d2 == (a % 10);

    result = (d1 == d2);
    return result;
}

/*@
    requires 10 <= a <= 99;
    ensures \result == 1 <==> (((a) / 10) == ((a) % 10));
    assigns \nothing;
*/
bool func(unsigned long long a)
{
    unsigned long long d1;
    unsigned long long d2;
    bool result;

    d1 = a / 10;
    d2 = a % 10;

    //@ assert d1 == (a / 10);
    //@ assert d2 == (a % 10);

    result = (d1 == d2);
    return result;
}

int main(void)
{
    return 0;
}
