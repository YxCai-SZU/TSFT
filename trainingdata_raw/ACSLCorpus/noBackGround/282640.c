#include <limits.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures ((\result) == 8 || (\result) == 7 || (\result) == 6 || (\result) == 5);
    assigns \nothing;
*/
int func(int x)
{
    int num;
    
    //@ assert (400 <= (x) && (x) < 2000);
    
    if (x >= 1200 && x < 2000) {
        num = 8;
    } else if (x >= 800 && x < 1200) {
        num = 7;
    } else if (x >= 600 && x < 800) {
        num = 6;
    } else if (x >= 400 && x < 600) {
        num = 5;
    } else {
        num = -1;
    }
    
    //@ assert ((num) == 8 || (num) == 7 || (num) == 6 || (num) == 5);
    
    return num;
}
