#include <stdbool.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 100 && (m) <= 100);
    ensures \result == (n > m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Declare all variables at the top
    bool result;

    // Function logic
    if (n > m) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (n > m);
    return result;
}

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 100 && (m) <= 100);
    ensures \result == ((n) > (m) ? (n) - (m) : (m) - (n));
    assigns \nothing;
*/
unsigned int func2(unsigned int n, unsigned int m)
{
    // Declare all variables at the top
    unsigned int result;

    // Function logic
    if (n > m) {
        //@ assert n > m;
        result = n - m;
    } else {
        //@ assert m >= n;
        result = m - n;
    }

    //@ assert result == ((n) > (m) ? (n) - (m) : (m) - (n));
    return result;
}
