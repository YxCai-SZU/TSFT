#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == ((a == b + 1 && b + 1 == c + 1) ||
                        (b == a + 1 && a + 1 == c + 1) ||
                        (c == a + 1 && a + 1 == b + 1) ||
                        (a == b - 1 && b - 1 == c - 1) ||
                        (b == a - 1 && a - 1 == c - 1) ||
                        (c == a - 1 && a - 1 == b - 1));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    if (a == b + 1 && b + 1 == c + 1)
    {
        result = true;
    }
    else if (b == a + 1 && a + 1 == c + 1)
    {
        result = true;
    }
    else if (c == a + 1 && a + 1 == b + 1)
    {
        result = true;
    }
    else if (a == b - 1 && b - 1 == c - 1)
    {
        result = true;
    }
    else if (b == a - 1 && a - 1 == c - 1)
    {
        result = true;
    }
    else if (c == a - 1 && a - 1 == b - 1)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == ((a == b + 1 && b + 1 == c + 1) || (b == a + 1 && a + 1 == c + 1) || (c == a + 1 && a + 1 == b + 1) || (a == b - 1 && b - 1 == c - 1) || (b == a - 1 && a - 1 == c - 1) || (c == a - 1 && a - 1 == b - 1));

    return result;
}
