#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    int result;
    //@ assert 1 <= r && r <= 100;
    //@ assert 1 <= r * r && r * r <= 10000;
    result = r * r;
    return result;
}

int main()
{
    return 0;
}
