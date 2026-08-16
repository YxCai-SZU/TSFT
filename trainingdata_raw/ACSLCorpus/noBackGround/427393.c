#include <stdbool.h>

/*@ requires 100 <= N <= 999;
    ensures \result == 1 <==> ((N) / 100 == 7 || ((N) / 10) % 10 == 7 || (N) % 10 == 7);
    assigns \nothing;
*/
bool func(unsigned long N) {
    unsigned long N_100;
    unsigned long N_10;
    unsigned long N_1;
    bool result;

    N_100 = N / 100;
    N_10 = (N / 10) % 10;
    N_1 = N % 10;

    //@ assert N_100 == N / 100;
    //@ assert N_10 == (N / 10) % 10;
    //@ assert N_1 == N % 10;

    result = (N_100 == 7) || (N_10 == 7) || (N_1 == 7);
    return result;
}
