#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == 1 <==> (((n) / 100) == 7 ||
        (((n) / 10) % 10) == 7 ||
        ((n) % 10) == 7);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    a0 = n / 100;
    a1 = (n / 10) % 10;
    a2 = n % 10;
    result = (a0 == 7) || (a1 == 7) || (a2 == 7);

    //@ assert result == 1 <==> (((n) / 100) == 7 ||         (((n) / 10) % 10) == 7 ||         ((n) % 10) == 7);
    return result;
}

/*@
    requires 100 <= n <= 999;
    ensures \result == 1 <==> (((n) / 100) == 7 ||
        (((n) / 10) % 10) == 7 ||
        ((n) % 10) == 7);
    assigns \nothing;
*/
bool func_sub(unsigned int n)
{
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    a0 = n / 100;
    a1 = (n / 10) % 10;
    a2 = n % 10;
    result = (a0 == 7) || (a1 == 7) || (a2 == 7);

    //@ assert result == 1 <==> (((n) / 100) == 7 ||         (((n) / 10) % 10) == 7 ||         ((n) % 10) == 7);
    return result;
}

int main()
{
    bool test_result = func(777);
    //@ assert test_result == true;
    return 0;
}
