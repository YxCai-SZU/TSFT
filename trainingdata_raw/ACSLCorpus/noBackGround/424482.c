#include <stdbool.h>

/*@
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> 1 <= (input)[i] && (input)[i] <= 100);
    ensures \result == ((((input[0]) + (input[1]) == (input[2]) || (input[1]) + (input[2]) == (input[0]) || (input[2]) + (input[0]) == (input[1])) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(int *input)
{
    bool flag = false;
    int a = 0;
    int b = 0;
    int c = 0;

    a = input[0];
    b = input[1];
    c = input[2];

    if (a + b == c)
    {
        flag = true;
    }
    else if (b + c == a)
    {
        flag = true;
    }
    else if (c + a == b)
    {
        flag = true;
    }

    //@ assert flag == (a + b == c || b + c == a || c + a == b);
    return flag;
}
