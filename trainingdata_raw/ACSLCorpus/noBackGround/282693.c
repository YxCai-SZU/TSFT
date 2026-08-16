#include <stdbool.h>

/*@
    requires 1 <= monthnum2 <= 12;
    ensures \result <==> ((monthnum2) == 1 || (monthnum2) == 3 || (monthnum2) == 5 || (monthnum2) == 7 ||
        (monthnum2) == 8 || (monthnum2) == 10 || (monthnum2) == 12);
    assigns \nothing;
 */
bool check_monthnumb_number(int monthnum2)
{
    //@ assert 1 <= monthnum2 && monthnum2 <= 12;
    return monthnum2 == 1 || monthnum2 == 3 || monthnum2 == 5 || monthnum2 == 7 ||
           monthnum2 == 8 || monthnum2 == 10 || monthnum2 == 12;
}
