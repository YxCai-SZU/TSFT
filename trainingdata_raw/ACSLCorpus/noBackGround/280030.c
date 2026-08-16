#include <stdbool.h>

/*@
    requires \valid(s + (0..2));
    requires ((3) == 3 &&
        1 <= (s)[0] <= 100 &&
        1 <= (s)[1] <= 100 &&
        1 <= (s)[2] <= 200);
    ensures \result == (s[0] + s[1] >= s[2]);
*/
bool func(int *s)
{
    bool flag = false;
    int sum = 0;

    //@ assert s[0] >= 1 && s[0] <= 100;
    //@ assert s[1] >= 1 && s[1] <= 100;
    //@ assert s[2] >= 1 && s[2] <= 200;
    
    sum = s[0] + s[1];
    
    //@ assert sum == ((s[0]) + (s[1]));
    
    if (sum >= s[2])
    {
        flag = true;
    }
    
    //@ assert flag == (sum >= s[2]);
    return flag;
}
