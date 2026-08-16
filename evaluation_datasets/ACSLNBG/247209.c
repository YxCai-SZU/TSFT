#include <stdbool.h>


bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool ans;
    bool cond1;
    bool cond2;
    bool cond3;

    ans = false;
    cond1 = (A == 5) && ((B == 5) || (C == 5) || (B == 7) || (C == 7));
    cond2 = (B == 5) && ((A == 5) || (C == 5) || (A == 7) || (C == 7));
    cond3 = (C == 5) && ((A == 5) || (B == 5) || (A == 7) || (B == 7));

    //@ assert cond1 == ((A == 5) && ((B == 5) || (C == 5) || (B == 7) || (C == 7)));
    //@ assert cond2 == ((B == 5) && ((A == 5) || (C == 5) || (A == 7) || (C == 7)));
    //@ assert cond3 == ((C == 5) && ((A == 5) || (B == 5) || (A == 7) || (B == 7)));

    ans = cond1 || cond2 || cond3;

    //@ assert ans == ((A == 5 && (B == 5 || C == 5 || B == 7 || C == 7)) || (B == 5 && (A == 5 || C == 5 || A == 7 || C == 7)) || (C == 5 && (A == 5 || B == 5 || A == 7 || B == 7)));

    return ans;
}
