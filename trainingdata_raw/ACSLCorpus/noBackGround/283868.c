#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result == true <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    bool result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (a < b && b < c) {
        result = true;
    } else if (a > b && b > c) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> ((((a)) < ((b)) && ((b)) < ((c))) || (((a)) > ((b)) && ((b)) > ((c))));
    return result;
}
