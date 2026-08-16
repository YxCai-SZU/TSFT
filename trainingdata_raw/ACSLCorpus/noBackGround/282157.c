#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    ensures \result == (a * b > 50);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top
    bool res;

    //@ assert a * b <= 10000;
    res = a * b > 50;
    //@ assert res == (a * b > 50);
    return res;
}

int main()
{
    // Variable declarations at top
    unsigned int width;
    unsigned int height;
    
    width = 4;
    height = 4;
    //@ assert (((width) == (height)) ==> ((width) > 0));
    //@ assert ((width) * (height)) == 16;
    return 0;
}
