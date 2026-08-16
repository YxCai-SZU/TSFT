#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (((a)) - ((b)) * 2) || (\result) == 0);
*/
int func(int a, int b)
{
    int res;
    int tmp;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    tmp = a - b * 2;
    
    //@ assert tmp >= 0 || tmp == ((a) - (b) * 2);
    
    if (tmp > 0) {
        res = tmp;
    } else {
        res = 0;
    }
    
    //@ assert ((res) >= 0);
    //@ assert ((res) == (((a)) - ((b)) * 2) || (res) == 0);
    
    return res;
}
