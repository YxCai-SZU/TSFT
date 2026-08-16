#include <stdbool.h>


bool func(long s, long w)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= s <= 100;
    //@ assert 1 <= w <= 100;

    result = (s <= w);
    return result;
}

#ifdef TEST
#include <assert.h>

int main()
{
    // Test 1
    {
        long s = 10;
        long w = 15;
        bool result = func(s, w);
        assert(result == true);
    }

    // Test 2
    {
        long s = 20;
        long w = 15;
        bool result = func(s, w);
        assert(result == false);
    }

    return 0;
}
#endif
