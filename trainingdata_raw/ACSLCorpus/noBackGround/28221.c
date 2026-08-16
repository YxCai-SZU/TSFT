#include <stdbool.h>

/*@
    requires 0 <= x <= 1;
    ensures \result == 1 - x;
    assigns \nothing;
*/
int func(int x)
{
    //@ assert ((x) == 0 || (x) == 1);
    int result;
    result = 1 - x;
    //@ assert result == 1 - x;
    return result;
}

/*@
    requires 0 <= a <= 1 && 0 <= b <= 1;
    ensures \result == ((a) ^ (b));
    assigns \nothing;
*/
int func2(int a, int b)
{
    //@ assert ((a) == 0 || (a) == 1);
    //@ assert ((b) == 0 || (b) == 1);
    int result;
    result = a ^ b;
    //@ assert result == ((a) ^ (b));
    return result;
}

/*@
    requires 0 <= x <= 1;
    ensures \result == x;
    assigns \nothing;
*/
int func3(int x)
{
    //@ assert ((x) == 0 || (x) == 1);
    int result;
    result = x;
    //@ assert result == x;
    return result;
}
