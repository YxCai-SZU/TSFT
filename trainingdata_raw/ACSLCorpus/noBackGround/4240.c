#include <stdint.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
    ensures 1 <= \result <= 3;
    ensures \result != a;
    ensures \result != b;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t res;
    
    //@ assert 1 <= a <= 3;
    //@ assert 1 <= b <= 3;
    //@ assert a != b;
    
    //@ assert 6 - a - b >= 1;
    //@ assert 6 - a - b <= 3;
    //@ assert 6 - a - b != a;
    //@ assert 6 - a - b != b;
    
    res = 6 - a - b;
    
    //@ assert res == 6 - a - b;
    //@ assert 1 <= res <= 3;
    //@ assert res != a;
    //@ assert res != b;
    
    return res;
}

int main()
{
    return 0;
}
