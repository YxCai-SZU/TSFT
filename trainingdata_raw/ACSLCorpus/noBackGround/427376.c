#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert a - 2 * b >= 0 || 0 >= 0;
    result = (a - 2 * b > 0) ? (a - 2 * b) : 0;
    //@ assert result >= 0;
    //@ assert result == a - 2 * b || result == 0;
    return result;
}

/*@
    ensures \result >= a && \result >= b;
    ensures \result == a || \result == b;
    assigns \nothing;
*/
int max(int a, int b)
{
    int result;
    if (a > b) {
        result = a;
        //@ assert result >= a && result >= b;
        //@ assert result == a;
    } else {
        result = b;
        //@ assert result >= a && result >= b;
        //@ assert result == b;
    }
    //@ assert result >= a && result >= b;
    //@ assert result == a || result == b;
    return result;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result == a + b - 2 * c || \result == 0;
    assigns \nothing;
*/
int func2(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert a + b - 2 * c >= 0 || 0 >= 0;
    result = (a + b - 2 * c > 0) ? (a + b - 2 * c) : 0;
    //@ assert result >= 0;
    //@ assert result == a + b - 2 * c || result == 0;
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    int res1, res2, res3;
    
    res1 = func(1, 2);
    assert(res1 == 0);
    
    res1 = func(10, 3);
    assert(res1 == 4);
    
    res2 = max(1, 2);
    assert(res2 == 2);
    
    res2 = max(10, 3);
    assert(res2 == 10);
    
    res3 = func2(1, 2, 3);
    assert(res3 == 0);
    
    res3 = func2(10, 3, 1);
    assert(res3 == 12);
    
    return 0;
}
#endif
