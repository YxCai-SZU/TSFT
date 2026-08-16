#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (n * 500 >= x);
    assigns \nothing;
*/
bool func(int n, int x)
{
    int pay;
    /*@ assert (1 <= (n) <= 100 && 1 <= (x) <= 100000); */
    
    pay = n * 500;
    
    /*@ assert pay == n * 500; */
    /*@ assert 0 <= pay <= 50000; */
    
    if (pay >= x) {
        return true;
    } else {
        return false;
    }
}
