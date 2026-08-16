#include <stdbool.h>

/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100);
    ensures \result == (A <= C && C <= B);
*/
bool func(int A, int B, int C)
{
    int a;
    int b;
    int c;
    int temp;
    bool result;

    a = A;
    b = B;
    c = C;

    //@ ghost L1: ;
    if (a > b)
    {
        //@ assert a > b;
        temp = a;
        a = b;
        b = temp;
        //@ assert ((a) <= (b));
    }
    //@ assert ((a) <= (b));

    //@ ghost L2: ;
    if (c < a)
    {
        //@ assert c < a;
        a = c;
        //@ assert a == c;
        //@ assert ((a) <= (c) <= (b));
    }
    else if (c > b)
    {
        //@ assert c > b;
        b = c;
        //@ assert b == c;
        //@ assert ((a) <= (c) <= (b));
    }
    else
    {
        //@ assert ((a) <= (c) <= (b));
    }

    //@ assert ((a) <= (c) <= (b));
    result = (A <= C && C <= B);
    return result;
}
