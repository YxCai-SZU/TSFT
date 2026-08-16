#include <stdbool.h>

/*@
    predicate is_valid_range(integer N) = 100 <= N && N <= 999;

    logic integer digit_hundred(integer N) = N / 100;
    logic integer digit_ten(integer N) = (N / 10) % 10;
    logic integer digit_one(integer N) = N % 10;

    predicate contains_seven(integer N) =
        digit_hundred(N) == 7 ||
        digit_ten(N) == 7 ||
        digit_one(N) == 7;
*/

/*@
    requires is_valid_range(N);
    ensures \result == true <==> contains_seven(N);
    assigns \nothing;
*/
bool func(long long N) {
    unsigned long long N_unsigned;
    bool result;

    //@ assert 100 <= N && N <= 999;
    
    if (N < 0) {
        N_unsigned = (unsigned long long)(-N);
    } else {
        N_unsigned = (unsigned long long)N;
    }

    //@ assert 0 <= N_unsigned;

    if (N_unsigned / 100 == 7 || (N_unsigned / 10) % 10 == 7 || N_unsigned % 10 == 7) {
        //@ assert contains_seven(N);
        result = true;
    } else {
        //@ assert !contains_seven(N);
        result = false;
    }

    return result;
}
