#include <stdbool.h>

/*@
    requires (-16 <= (x1) < 16);
    ensures \result == (8 * (x1));
    assigns \nothing;
*/
int octuple(int x1)
{
    int x2;
    int x4;
    int result;

    x2 = x1 + x1;
    //@ assert x2 == 2 * x1;

    x4 = x2 + x2;
    //@ assert x4 == 4 * x1;

    result = x4 + x4;
    //@ assert result == 8 * x1;

    return result;
}

int main()
{
    int n;
    bool print_value;

    n = octuple(5);
    //@ assert n == 40;

    print_value = (n == 40);
    //@ assert print_value == true;

    return 0;
}
