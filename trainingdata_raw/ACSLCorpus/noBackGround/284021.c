#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    requires (1 <= (y) && (y) <= 100);
    requires (1 <= (z) && (z) <= 100);
    ensures \result == x * y + z;
*/
int func(int x, int y, int z)
{
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert (1 <= (z) && (z) <= 100);
    //@ assert ((x) * (y) <= 10000);
    
    int answer;
    answer = x * y + z;
    
    return answer;
}
