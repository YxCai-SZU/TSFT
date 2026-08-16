#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == r * r;
    assigns \nothing;
*/
int32_t func_range(int32_t r)
{
    //@ assert (1 <= (r) && (r) <= 100);
    return func(r);
}

/*@
    requires 1 <= r && r <= 100;
    ensures \result == r * r;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    int32_t result;
    result = r;
    
    if (r != 0)
    {
        //@ assert 1 <= r && r <= 100;
        //@ assert r * r <= 10000;
        result = r * r;
    }
    
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    assert(func(0) == 0);
    assert(func(1) == 1);
    assert(func(100) == 10000);
    
    assert(func_range(1) == 1);
    assert(func_range(100) == 10000);
    return 0;
}
#endif
