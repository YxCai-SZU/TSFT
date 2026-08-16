#include <stdbool.h>

/*@
    requires 0 <= x < 100;
    ensures \result == (((x) >= 0 && (x) <= 99) ? (x) : 0);
    assigns \nothing;
*/
int compute_f(int x)
{
    int result;
    
    //@ assert ((x) >= 0 && (x) <= 99);
    //@ assert (((x) >= 0 && (x) <= 99) ? (x) : 0) == x;
    
    if (x >= 0 && x <= 99) {
        result = x;
    } else {
        result = 0;
    }
    
    //@ assert result == (((x) >= 0 && (x) <= 99) ? (x) : 0);
    return result;
}

int main()
{
    int x;
    int result;
    
    x = 50;
    //@ assert 0 <= x < 100;
    result = compute_f(x);
    //@ assert result == x;
    
    return 0;
}
