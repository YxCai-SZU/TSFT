#include <stdbool.h>

/*@
    requires \valid(v + (0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 20 &&
        1 <= (v)[2] <= 2000);
    ensures \result >= 0;
    ensures \result <= v[2];
    assigns \nothing;
*/
int func(int *v)
{
    int x;
    
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 20;
    //@ assert 1 <= v[2] && v[2] <= 2000;
    
    //@ assert v[0] * v[1] >= 0;
    //@ assert v[0] * v[1] <= 2000;
    
    x = v[0] * v[1];
    
    if (x < v[2])
    {
        //@ assert x <= v[2];
        return x;
    }
    else
    {
        return v[2];
    }
}
