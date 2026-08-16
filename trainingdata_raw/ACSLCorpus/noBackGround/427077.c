#include <stdbool.h>

/*@
    requires a < 124 && b < 124 && c < 124 && d < 124 && e < 124 && k < 124;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == true <==> e - a <= k;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    bool answer = false;

    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    
    if (e - a <= k)
    {
        answer = true;
    }

    //@ assert answer == true <==> e - a <= k;
    
    return answer;
}
