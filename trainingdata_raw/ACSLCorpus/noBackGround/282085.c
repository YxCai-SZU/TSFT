#include <stdbool.h>

/*@
    requires (\valid((v) + (0..3)) &&
        1 <= (v)[0] <= 100 &&
        1 <= (v)[1] <= 100 &&
        1 <= (v)[2] <= 100 &&
        1 <= (v)[3] <= 100);
    ensures \result == 1 <==> ((v)[0] >= (v)[2] && (v)[1] <= (v)[3]);
    assigns \nothing;
*/
bool func(int *v)
{
    //@ assert \valid(v + (0..3));
    //@ assert 1 <= v[0] <= 100;
    //@ assert 1 <= v[1] <= 100;
    //@ assert 1 <= v[2] <= 100;
    //@ assert 1 <= v[3] <= 100;
    
    return v[0] >= v[2] && v[1] <= v[3];
}
