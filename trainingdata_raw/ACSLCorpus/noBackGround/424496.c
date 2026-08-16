#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> a == b && b == c;
    ensures \result == 2 ==> (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
    ensures \result == 3 ==> a != b && b != c && a != c;
*/
int func(int a, int b, int c)
{
    int cnt = 0;
    
    //@ assert cnt == 0;
    
    if (a == b)
    {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0);
    
    if (b == c)
    {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (b == c ? 1 : 0);
    
    if (a == c)
    {
        cnt += 1;
    }
    //@ assert cnt == (a == b ? 1 : 0) + (b == c ? 1 : 0) + (a == c ? 1 : 0);
    
    int res;
    
    if (cnt == 3)
    {
        res = 1;
        //@ assert ((a) == (b) && (b) == (c));
    }
    else if (cnt > 0)
    {
        res = 2;
        //@ assert (((a) == (b) && (a) != (c)) || ((a) == (c) && (a) != (b)) || ((b) == (c) && (a) != (b)));
    }
    else
    {
        res = 3;
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
    }
    
    return res;
}
