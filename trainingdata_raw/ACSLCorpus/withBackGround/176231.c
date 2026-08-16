#include <stdbool.h>
/*@
    predicate is_valid_result(integer r) =
        r == 0 || r == 1 || r == 5 || r == 6 || r == 19;
*/

/*@
    requires 2 <= n <= 100;
    ensures is_valid_result(\result);
    assigns \nothing;
*/
int func(unsigned int n) {
    int result;
    if ((n % 2) == 0) {
        result = 1;
    } else if ((n % 3) == 0) {
        result = 5;
    } else if ((n % 5) == 0) {
        result = 19;
    } else if ((n % 7) == 0) {
        result = 0;
    } else {
        result = 6;
    }
    //@ assert is_valid_result(result);
    return result;
}

/*@
    requires 2 <= n <= 100;
    ensures is_valid_result(\result);
    assigns \nothing;
*/
int func_spec(unsigned int n) {
    int result;
    if ((n % 2) == 0) {
        result = 1;
    } else if ((n % 3) == 0) {
        result = 5;
    } else if ((n % 5) == 0) {
        result = 19;
    } else if ((n % 7) == 0) {
        result = 0;
    } else {
        result = 6;
    }
    //@ assert is_valid_result(result);
    return result;
}
