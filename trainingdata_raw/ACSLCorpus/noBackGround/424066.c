#include <limits.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert 1 <= r <= 100;
    //@ assert r * r <= 10000;
    //@ assert r * r >= 1;
    
    int result;
    result = r * r;
    
    //@ assert result == r * r;
    return result;
}

int main()
{
    return 0;
}
