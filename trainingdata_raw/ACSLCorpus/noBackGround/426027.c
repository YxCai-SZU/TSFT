#include <stdbool.h>

/*@ ensures \result == (n % 2 == 0); */
bool is_even_func(unsigned int n)
{
    return n % 2 == 0;
}

/*@ ensures \result == (n % 2 != 0); */
bool is_odd_func(unsigned int n)
{
    return n % 2 != 0;
}

/*@ requires 0 <= x <= 62;
    ensures \result == true; */
bool test_is_even_and_odd(unsigned int x)
{
    bool ret = true;
    
    if (is_even_func(x)) {
        //@ assert x % 2 == 0;
    } else {
        //@ assert x % 2 != 0;
    }
    
    return ret;
}
