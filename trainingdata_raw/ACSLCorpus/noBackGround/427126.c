#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) * (b)) || \result == ((a) * ((b) + 1));
*/
int func(int a, int b)
{
    int res_b;
    int res_b_plus_1;
    int res;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    res_b = a * b;
    //@ assert res_b == ((a) * (b));
    
    res_b_plus_1 = a * (b + 1);
    //@ assert res_b_plus_1 == ((a) * ((b) + 1));
    
    if (res_b > res_b_plus_1) {
        res = res_b;
        //@ assert res == ((a) * (b));
    } else {
        res = res_b_plus_1;
        //@ assert res == ((a) * ((b) + 1));
    }
    
    //@ assert res >= 0;
    return res;
}
