#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures ((n) < 10 && (m) < 10) ==> \result == ((n) * (m));
    ensures ((n) >= 10 || (m) >= 10) ==> \result == -1;
*/
int func(int n, int m)
{
    bool is_negative_one;
    int result;
    
    is_negative_one = n >= 10 || m >= 10;
    
    if (is_negative_one)
    {
        //@ assert ((n) >= 10 || (m) >= 10);
        return -1;
    }
    
    //@ assert 1 <= n && n < 10;
    //@ assert 1 <= m && m < 10;
    //@ assert 1 <= ((n) * (m)) && ((n) * (m)) < 100;
    
    result = n * m;
    return result;
}
