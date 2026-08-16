#include <stdbool.h>


bool func(int N, int A, int B)
{
    bool result;
    int diff;

    //@ assert (0 <= (A) < (B) <= 100);
    //@ assert ((B) - (A)) >= 0;
    //@ assert ((B) - (A)) <= 100;
    
    result = false;
    diff = B - A;
    
    if (diff <= N)
    {
        result = true;
    }
    
    //@ assert result == (B - A <= N);
    return result;
}
