/*@
    requires ((a) < 4294967295);
    ensures \result == ((a) + 1);
    assigns \nothing;
*/
unsigned int func(unsigned int a)
{
    unsigned int result;
    //@ assert a < 4294967295;
    result = a + 1;
    //@ assert result == ((a) + 1);
    return result;
}

#ifdef TEST
#include <assert.h>
int main(void)
{
    unsigned int a;
    unsigned int result;
    
    a = 10;
    result = func(a);
    assert(result == a + 1);
    return 0;
}
#endif
