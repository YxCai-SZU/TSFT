#include <stdbool.h>
/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    ensures \result == 0 || \result == 1;
    ensures \result == (((n) % (k) == 0) ? 0 : 1);
*/
unsigned int func(unsigned int n, unsigned int k)
{
    unsigned int result;
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (k) && (k) <= 100);
    //@ assert n % k == 0 || n % k != 0;
    if (n % k == 0) {
        result = 0;
    } else {
        result = 1;
    }
    //@ assert result == 0 || result == 1;
    return result;
}

#ifdef TEST
#include <assert.h>
int main()
{
    unsigned int n;
    unsigned int k;
    unsigned int result;
    
    n = 10;
    k = 2;
    result = func(n, k);
    //@ assert result == (((n) % (k) == 0) ? 0 : 1);
    assert(result == 1);
    
    n = 20;
    k = 5;
    result = func(n, k);
    //@ assert result == (((n) % (k) == 0) ? 0 : 1);
    assert(result == 0);
    
    return 0;
}
#endif
