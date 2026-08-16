#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int res;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    //@ assert n * a <= 1000;
    //@ assert b <= 50;
    
    if (n * a < b) {
        res = n * a;
    } else {
        res = b;
    }
    
    //@ assert res == n * a || res == b;
    //@ assert res <= b;
    
    return res;
}

#ifdef TEST
#include <assert.h>

int main()
{
    assert(func(2, 3, 5) == 6);
    assert(func(5, 5, 5) == 5);
    assert(func(2, 2, 2) == 2);
    assert(func(1, 1, 100) == 1);
    assert(func(20, 50, 1000) == 1000);
    return 0;
}
#endif
