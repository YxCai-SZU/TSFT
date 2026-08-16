#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100);
    ensures \result >= 1;
    ensures ((\result) == 1 || (\result) == 2 || (\result) == 5 || (\result) == 14 || (\result) == 15 || (\result) == 51 || (\result) == 4);
    assigns \nothing;
*/
int func(int k)
{
    int result;
    
    //@ assert 1 <= k <= 100;
    
    if (k == 1) {
        result = 1;
    } else if (k == 2) {
        result = 1;
    } else if (k == 5) {
        result = 2;
    } else if (k == 14) {
        result = 5;
    } else if (k == 15) {
        result = 14;
    } else if (k == 51) {
        result = 51;
    } else {
        //@ assert 1 <= k <= 100;
        result = 4;
    }
    
    //@ assert result >= 1;
    //@ assert ((result) == 1 || (result) == 2 || (result) == 5 || (result) == 14 || (result) == 15 || (result) == 51 || (result) == 4);
    return result;
}
