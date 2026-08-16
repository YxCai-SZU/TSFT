#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures ((\result) == (((a) + (b) == (c)) || ((a) + (c) == (b)) || ((b) + (c) == (a))));
*/
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    return (a + b == c) || (a + c == b) || (b + c == a);
}

int main()
{
    return 0;
}
