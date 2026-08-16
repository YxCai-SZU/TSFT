#include <stdbool.h>

/*@
    requires ((3) == 3 &&
    \valid((v) + (0 .. 2)) &&
    1 <= (v)[0] <= 9 &&
    1 <= (v)[1] <= 9 &&
    1 <= (v)[2] <= 9);
    ensures \result == (((v)[1] * 100 + (v)[2] * 10 + (v)[0]) % 4 == 0);
    assigns \nothing;
*/
bool func(int *v)
{
    // Variable declarations at top of scope
    bool result;
    int temp;

    //@ assert \valid(v + (0 .. 2));
    
    temp = v[1] * 100 + v[2] * 10 + v[0];
    
    //@ assert temp == ((v)[1] * 100 + (v)[2] * 10 + (v)[0]);
    
    if (temp % 4 == 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (((v)[1] * 100 + (v)[2] * 10 + (v)[0]) % 4 == 0);
    return result;
}
