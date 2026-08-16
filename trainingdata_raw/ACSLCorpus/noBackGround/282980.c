#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (c - b == b - a);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int diff1;
    int diff2;
    bool result;

    diff1 = c - b;
    diff2 = b - a;
    result = (diff1 == diff2);
    //@ assert diff1 == c - b;
    //@ assert diff2 == b - a;
    //@ assert result == (c - b == b - a);
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a - c == a - b + b - c);
    assigns \nothing;
*/
bool func2(int a, int b, int c)
{
    int diff1;
    int diff2;
    int diff3;
    bool result;

    diff1 = a - c;
    diff2 = a - b;
    diff3 = b - c;
    //@ assert diff1 == a - c;
    //@ assert diff2 == a - b;
    //@ assert diff3 == b - c;
    //@ assert diff1 == diff2 + diff3;
    result = (diff1 == diff2 + diff3);
    //@ assert result == (a - c == a - b + b - c);
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a + c == a + b - b + c);
    assigns \nothing;
*/
bool func3(int a, int b, int c)
{
    int diff1;
    int diff2;
    int diff3;
    bool result;

    diff1 = a + c;
    diff2 = a + b;
    diff3 = b + c;
    //@ assert diff1 == a + c;
    //@ assert diff2 == a + b;
    //@ assert diff3 == b + c;
    //@ assert diff1 == diff2 - b + c;
    //@ assert diff1 == diff3 - b + a;
    result = (diff1 == diff2 - b + c);
    //@ assert result == (a + c == a + b - b + c);
    return result;
}
