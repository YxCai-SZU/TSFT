#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    if (n == m)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    //@ assert result == (n == m);
    return result;
}

/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ensures \result == (n != m);
    assigns \nothing;
*/
bool func2(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    if (n == m)
    {
        result = false;
    }
    else
    {
        result = true;
    }
    //@ assert result == (n != m);
    return result;
}

/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ensures \result == (n < m);
    assigns \nothing;
*/
bool func3(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    if (n < m)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    //@ assert result == (n < m);
    return result;
}

/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    ensures \result == (n <= m);
    assigns \nothing;
*/
bool func4(unsigned int n, unsigned int m)
{
    bool result;
    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (m) && (m) <= (n));
    if (n <= m)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    //@ assert result == (n <= m);
    return result;
}
