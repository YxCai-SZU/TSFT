#include <stdbool.h>

/*@
    requires n >= 0;
    ensures \result <==> ((n) % 2 == 0);
    ensures !\result <==> ((n) % 2 != 0);
*/
bool is_even(unsigned int n)
{
    //@ assert n % 2 == 0 || n % 2 != 0;
    return n % 2 == 0;
}

/*@
    requires n >= 0;
    ensures \result <==> ((n) % 2 != 0);
    ensures !\result <==> ((n) % 2 == 0);
*/
bool is_odd(unsigned int n)
{
    //@ assert n % 2 == 0 || n % 2 != 0;
    return n % 2 != 0;
}

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result <= 1;
*/
unsigned int func(unsigned int n, unsigned int k)
{
    unsigned int res;
    
    if (n % k == 0) {
        res = 0;
    } else {
        res = 1;
    }
    
    //@ assert res <= 1;
    return res;
}

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result <= 1;
*/
unsigned int func2(unsigned int n, unsigned int k)
{
    unsigned int res;
    
    if (n % k == 0) {
        res = 0;
    } else {
        res = 1;
    }
    
    //@ assert res <= 1;
    return res;
}

int main()
{
    return 0;
}
