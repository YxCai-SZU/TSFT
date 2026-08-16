#include <stdbool.h>

/*@
    requires (0 <= (x) && (x) <= 1);
    ensures (x == 0 ==> \result == 0) && (x == 1 ==> \result == 2);
    assigns \nothing;
*/
int my_adder(int x)
{
    //@ assert (0 <= (x) && (x) <= 1);
    return x + x;
}

int main()
{
    int f;
    f = my_adder(1);
    //@ assert f == 2;
    return 0;
}
