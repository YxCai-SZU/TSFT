#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    int result;
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (3 * (r) * (r)) <= 3 * 100 * 100;
    result = 3 * r * r;
    //@ assert result == (3 * (r) * (r));
    return result;
}

int main()
{
    int r;
    int result;
    
    r = 3;
    //@ assert (1 <= (r) && (r) <= 100);
    result = func(r);
    //@ assert result == (3 * (r) * (r));
    return 0;
}
