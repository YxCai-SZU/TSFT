#include <stdbool.h>

/*@
    requires \valid_read(v + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == (v[0] < v[1] && v[1] < v[2]);
    ensures \result <==> ((len) >= 3 ==> (v)[0] < (v)[1] && (v)[1] < (v)[2]);
 */
bool func(int *v, int len)
{
    bool result;
    //@ assert len >= 3;
    result = v[0] < v[1] && v[1] < v[2];
    //@ assert result == (v[0] < v[1] && v[1] < v[2]);
    return result;
}
