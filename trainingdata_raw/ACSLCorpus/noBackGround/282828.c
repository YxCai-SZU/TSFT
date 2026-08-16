#include <stdbool.h>
/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
        (v)[0] >= 1 && (v)[0] <= 100 &&
        (v)[1] >= 1 && (v)[1] <= 100 &&
        (v)[2] >= 1 && (v)[2] <= 100);
    ensures \result <==> ((v)[0] + (v)[1] == (v)[2] ||
        (v)[1] + (v)[2] == (v)[0] ||
        (v)[2] + (v)[0] == (v)[1]);
    assigns \nothing;
*/
bool func(unsigned long long *v)
{
    bool result;

    //@ assert v[0] + v[1] <= 200;
    //@ assert v[1] + v[2] <= 200;
    //@ assert v[2] + v[0] <= 200;

    if (v[0] + v[1] == v[2] || v[1] + v[2] == v[0] || v[2] + v[0] == v[1])
    {
        //@ assert ((v)[0] + (v)[1] == (v)[2] ||         (v)[1] + (v)[2] == (v)[0] ||         (v)[2] + (v)[0] == (v)[1]);
        result = true;
    }
    else
    {
        //@ assert !((v)[0] + (v)[1] == (v)[2] ||         (v)[1] + (v)[2] == (v)[0] ||         (v)[2] + (v)[0] == (v)[1]);
        result = false;
    }

    return result;
}
