#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    ensures \result == true <==> a % 2 == 0;
    assigns \nothing;
*/
bool func(int a)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 100;
    result = (a % 2 == 0);
    
    //@ assert result == true <==> a % 2 == 0;
    return result;
}

int main()
{
    return 0;
}
