#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(v + (0 .. 2));
    requires ((len) >= 3 &&
        1 <= (v)[0] <= 9 &&
        1 <= (v)[1] <= 9 &&
        1 <= (v)[2] <= 9);
    ensures \result == (((v[1] * 10) + v[2]) % 4 == 0);
*/
bool func(int *v, size_t len)
{
    //@ assert 1 <= v[1] <= 9;
    //@ assert 1 <= v[2] <= 9;
    //@ assert v[1] * 10 <= 90;
    //@ assert v[1] * 10 + v[2] <= 99;
    
    return (v[1] * 10 + v[2]) % 4 == 0;
}
