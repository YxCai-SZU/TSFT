#include <stdbool.h>

/*@
    requires 0 <= a && a <= 10;
    requires 0 <= b && b <= 10;
    requires 0 <= c && c <= 10;
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    //@ assert 0 <= a && a <= 10;
    //@ assert 0 <= b && b <= 10;
    //@ assert 0 <= c && c <= 10;
    return a < b && b < c;
}

int main()
{
    return 0;
}
