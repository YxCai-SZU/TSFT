#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 100 && 1 <= (b) <= 2000);
    ensures \result == true <==> (a + n * 100 >= b);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at scope top
    int add;
    bool result;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 2000;
    //@ assert n * 100 <= 2000;

    add = a + n * 100;
    
    if (add >= b) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> (a + n * 100 >= b);
    return result;
}
