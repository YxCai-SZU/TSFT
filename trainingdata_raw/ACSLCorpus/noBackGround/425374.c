#include <stdbool.h>

/*@
    requires \valid(v+(0..2));
    requires ((3) == 3 &&
        1 <= (v)[0] <= 5000 &&
        1 <= (v)[1] <= 5000 &&
        1 <= (v)[2] <= 10000);
    ensures \result == (((v[0]) + (v[1])) >= v[2]);
*/
bool func(int *v)
{
    //@ assert 1 <= v[0] && v[0] <= 5000;
    //@ assert 1 <= v[1] && v[1] <= 5000;
    //@ assert 1 <= v[2] && v[2] <= 10000;
    return v[0] + v[1] >= v[2];
}

int main()
{
    return 0;
}
