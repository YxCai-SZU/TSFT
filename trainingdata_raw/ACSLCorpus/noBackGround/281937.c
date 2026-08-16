#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == (((a) * (n)) <= b || ((a) * ((n) - 1)) + b >= ((a) * (n)));
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at top of scope
    int an;
    int an_1;
    bool result;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert ((a) * (n)) <= 1000;

    //@ assert 0 <= n - 1 && n - 1 <= 19;
    //@ assert ((a) * ((n) - 1)) <= 950;

    an = a * n;
    an_1 = a * (n - 1);
    result = (an <= b) || (an_1 + b >= an);
    
    return result;
}
