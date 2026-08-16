#include <stdbool.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures \result == 3 * x;
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top
    int result;
    
    //@ assert (1 <= (x) <= 1000);
    result = 3 * x;
    //@ assert result == 3 * x;
    return result;
}

// External function (no ACSL for external)
void print_result(int i);

int main()
{
    // Variable declarations at top
    int result;
    
    result = func(10);
    //@ assert result == 30;
    print_result(result);
    
    return 0;
}
