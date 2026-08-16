#include <stdbool.h>

/*@
    requires \valid_read(xs + (0..2));
    requires (-100 <= (xs[0]) <= 100) && (-100 <= (xs[1]) <= 100) && (-100 <= (xs[2]) <= 100);
    requires ((xs[0]) <= (xs[1]));
    ensures \result == true <==> ((xs[0]) <= (xs[2]) <= (xs[1]));
*/
bool func(const long long *xs)
{
    bool result;

    //@ assert (-100 <= (xs[0]) <= 100);
    //@ assert (-100 <= (xs[1]) <= 100);
    //@ assert (-100 <= (xs[2]) <= 100);
    //@ assert ((xs[0]) <= (xs[1]));

    result = (xs[0] <= xs[2]) && (xs[2] <= xs[1]);
    
    //@ assert result == true <==> ((xs[0]) <= (xs[2]) <= (xs[1]));
    
    return result;
}
