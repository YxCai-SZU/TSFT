#include <stdbool.h>
/*@
    requires 1 <= n && n <= 100;
    ensures \result == 1;
    ensures (n % 2 == 0 ==> \result == 1);
    ensures (n % 2 != 0 ==> \result == 1);
*/
int func(int n)
{
    int result;
    
    //@ assert 1 <= n && n <= 100;
    
    if (n % 2 == 0) {
        //@ assert n % 2 == 0;
        //@ assert 1 == 1;
        return 1;
    } else {
        result = 1;
        
        //@ assert n * 2 >= 0 && n * 2 <= 200;
        //@ assert n * 2 - 1 >= 0 && n * 2 - 1 <= 199;
        //@ assert 100 * n >= 0 && 100 * n <= 10000;
        //@ assert 100 * n - 1 >= 0 && 100 * n - 1 <= 9999;
        //@ assert 100 * n + 1 >= 1 && 100 * n + 1 <= 10001;
        //@ assert (100 * n + 1) / 2 >= 0 && (100 * n + 1) / 2 <= 5000;
        //@ assert result == 1;
        
        return result;
    }
}
