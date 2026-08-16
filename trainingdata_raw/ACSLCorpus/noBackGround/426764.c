#include <limits.h>

/*@
    requires (1 <= (monthnum2) <= 12);
    ensures \result == 31 || \result == 30 || \result == 28 || \result == 29;
    ensures 28 <= \result <= 31;
    assigns \nothing;
*/
int check_monthnumb_number(int monthnum2)
{
    int result;

    //@ assert (1 <= (monthnum2) <= 12);

    if (monthnum2 == 1) {
        result = 31;
    } else if (monthnum2 == 2) {
        result = 28;
    } else if (monthnum2 == 3) {
        result = 31;
    } else if (monthnum2 == 4) {
        result = 30;
    } else if (monthnum2 == 5) {
        result = 31;
    } else if (monthnum2 == 6) {
        result = 30;
    } else if (monthnum2 == 7) {
        result = 31;
    } else if (monthnum2 == 8) {
        result = 31;
    } else if (monthnum2 == 9) {
        result = 30;
    } else if (monthnum2 == 10) {
        result = 31;
    } else if (monthnum2 == 11) {
        result = 30;
    } else {
        result = 31;
    }

    //@ assert result == 31 || result == 30 || result == 28 || result == 29;
    //@ assert result >= 28 && result <= 31;

    return result;
}
