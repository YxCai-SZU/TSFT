#include <stdbool.h>

/*@
    requires \valid_read(v + (0..2));
    requires (-100 <= (v[0]) && (v[0]) <= 100) && (-100 <= (v[1]) && (v[1]) <= 100) && (-100 <= (v[2]) && (v[2]) <= 100);
    assigns \nothing;
    ensures \result == true <==> (v[0] < v[1] && v[1] < v[2]);
*/
bool func(const int v[3])
{
    //@ assert (-100 <= (v[0]) && (v[0]) <= 100);
    //@ assert (-100 <= (v[1]) && (v[1]) <= 100);
    //@ assert (-100 <= (v[2]) && (v[2]) <= 100);
    
    if (v[0] < v[1] && v[1] < v[2]) {
        return true;
    } else {
        return false;
    }
}
