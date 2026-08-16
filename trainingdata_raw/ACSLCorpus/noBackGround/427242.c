#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (x + y + z >= a + b + c);
*/
bool func(int x, int y, int z, int a, int b, int c)
{
    int x_sum;
    int a_sum;
    bool result;
    
    x_sum = x + y + z;
    a_sum = a + b + c;
    
    //@ assert 1 <= x_sum <= 300;
    //@ assert 1 <= a_sum <= 300;
    //@ assert x_sum >= 3;
    //@ assert x_sum <= 300;
    //@ assert a_sum >= 3;
    //@ assert a_sum <= 300;
    
    result = (x_sum >= a_sum);
    return result;
}

int main()
{
    return 0;
}
