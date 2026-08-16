#include <stdbool.h>

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires 1 <= c <= 10;
    ensures 1 <= \result <= 30;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    
    result = a + b + c;
    
    //@ assert 1 <= result <= 30;
    
    return result;
}

int main()
{
    return 0;
}
