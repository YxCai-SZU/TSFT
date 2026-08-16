#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == ((((n) % 10 == 9) ? 1 : ((n) >= 90 ? 1 : 0)) == 1);
    assigns \nothing;
*/
bool func(int n)
{
    int i;
    bool result;
    
    //@ assert (10 <= (n) && (n) <= 99);
    
    if (n % 10 == 9 || n >= 90) {
        result = true;
    } else {
        i = n;
        /*@
            loop invariant 10 <= n <= 99;
            loop invariant n <= i <= 100;
            loop assigns i;
            loop variant 100 - i;
        */
        while (i < 100) {
            //@ assert i < 100;
            i = i + 1;
        }
        result = false;
    }
    
    //@ assert result == ((((n) % 10 == 9) ? 1 : ((n) >= 90 ? 1 : 0)) == 1);
    return result;
}
