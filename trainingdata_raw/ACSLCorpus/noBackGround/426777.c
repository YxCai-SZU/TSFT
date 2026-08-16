#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int result;
    bool final_result;

    result = (a + b >= c) ? 1 : 0;
    //@ assert result == 0 || result == 1;
    final_result = (result == 1);
    return final_result;
}
