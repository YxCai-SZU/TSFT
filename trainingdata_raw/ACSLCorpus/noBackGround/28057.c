#include <stdbool.h>

/*@
    requires (\valid((v) + (0..4)) &&
        (\forall integer i; 0 <= i < 5 ==> 0 <= (v)[i] <= 123) &&
        (v)[0] < (v)[1] && (v)[1] < (v)[2] && (v)[2] < (v)[3] && (v)[3] < (v)[4]) && 0 <= k <= 123;
    ensures \result == (k >= ((((v))[4]) - (((v))[0])));
*/
bool func(int *v, int k)
{
    int max_val;
    int min_val;
    
    //@ assert v[4] > v[0];
    
    if (v[4] > v[0]) {
        max_val = v[4];
    } else {
        max_val = v[0];
    }
    
    //@ assert max_val == v[4];
    
    if (v[0] < v[4]) {
        min_val = v[0];
    } else {
        min_val = v[4];
    }
    
    //@ assert min_val == v[0];
    //@ assert max_val - min_val == ((((v))[4]) - (((v))[0]));
    
    return k >= (max_val - min_val);
}
