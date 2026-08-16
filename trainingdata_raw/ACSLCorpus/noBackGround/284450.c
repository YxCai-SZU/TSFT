#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        (a) == (int64_t)(a) &&
        (b) == (int64_t)(b));
    ensures \result >= 0;
    ensures \result == ((a) - 2 * (b)) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         (a) == (int64_t)(a) &&         (b) == (int64_t)(b));
    result = a - 2 * b;
    
    if (result > 0)
    {
        //@ assert result == ((a) - 2 * (b));
        return result;
    }
    else
    {
        //@ assert result <= 0;
        return 0;
    }
}

int main()
{
    int64_t a;
    int64_t b;
    int64_t result;
    
    a = 10;
    b = 3;
    result = func(a, b);
    //@ assert result == ((a) - 2 * (b)) || result == 0;
    
    a = 5;
    b = 3;
    result = func(a, b);
    //@ assert result == 0;
    
    return 0;
}
