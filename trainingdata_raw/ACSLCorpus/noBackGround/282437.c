#include <stdbool.h>

/*@
    requires (1 <= (a) <= 16 &&
        1 <= (b) <= 16 &&
        (a) + (b) <= 16);
    ensures ((\result) == ((a) <= 8 && (b) <= 8));
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a <= 16;
    //@ assert 1 <= b <= 16;
    //@ assert a + b <= 16;

    result = (a <= 8 && b <= 8);
    return result;
}

int main()
{
    // Variable declarations at top of scope
    int a;
    int b;
    bool res;

    a = 5;
    b = 6;
    //@ assert (1 <= (a) <= 16 &&         1 <= (b) <= 16 &&         (a) + (b) <= 16);
    res = func(a, b);
    return 0;
}
