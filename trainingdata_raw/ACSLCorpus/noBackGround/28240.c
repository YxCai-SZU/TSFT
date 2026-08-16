#include <stdbool.h>

/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
        (v)[0] >= 1 && (v)[0] <= 100 &&
        (v)[1] >= 1 && (v)[1] <= 100 &&
        (v)[2] >= 1 && (v)[2] <= 100);
    ensures \result == ((((v[0]) + (v[1]) == (v[2])) ? 1 : (((v[1]) + (v[2]) == (v[0])) ? 1 : (((v[2]) + (v[0]) == (v[1])) ? 1 : 0))) == 1);
    assigns \nothing;
*/
bool func(int *v)
{
    bool result;
    
    //@ assert \valid(v) && \valid(v+1) && \valid(v+2);
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    //@ assert v[2] >= 1 && v[2] <= 100;

    result = (v[0] + v[1] == v[2]) || 
             (v[1] + v[2] == v[0]) || 
             (v[2] + v[0] == v[1]);

    return result;
}
