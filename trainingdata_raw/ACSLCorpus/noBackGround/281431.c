#include <stdbool.h>

/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
        1 <= (v)[0] && (v)[0] <= 13 &&
        1 <= (v)[1] && (v)[1] <= 13 &&
        1 <= (v)[2] && (v)[2] <= 13);
    ensures \result <==> ((v[1]) == (v[0]) + (v[2]) || (v[2]) == (v[1]) + (v[0]) || (v[0]) == (v[2]) + (v[1]));
    assigns \nothing;
*/
bool func(int *v)
{
    //@ assert (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&         1 <= (v)[0] && (v)[0] <= 13 &&         1 <= (v)[1] && (v)[1] <= 13 &&         1 <= (v)[2] && (v)[2] <= 13);
    
    return (v[1] == v[0] + v[2]) || 
           (v[2] == v[1] + v[0]) || 
           (v[0] == v[2] + v[1]);
}
