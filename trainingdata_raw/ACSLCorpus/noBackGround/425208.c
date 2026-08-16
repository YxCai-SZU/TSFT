#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100);
    requires (-100 <= (b) && (b) <= 100);
    ensures ((\result) == ((a) < (b)));
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool result;

    //@ assert -100 <= a && a <= 100;
    //@ assert -100 <= b && b <= 100;
    
    result = a < b;
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    int a = 0;
    int b = 1;
    bool result;
    
    //@ assert -100 <= a && a <= 100;
    //@ assert -100 <= b && b <= 100;
    //@ assert a < b;
    
    result = func(a, b);
    //@ assert result == (a < b);
    assert(result == true);
    
    return 0;
}
#endif
