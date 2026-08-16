#include <stdbool.h>
#include <stdint.h>

/*@
    requires \valid_read(test_data + (0 .. 2));
    requires ((((3)) == 3 &&
        \forall integer k; 0 <= k < ((3)) ==> ((test_data))[k] < 0x8000000000000000ULL) &&
        0 <= (K) < (test_data)[0]);
    assigns \nothing;
    ensures ((\result) == ((test_data)[1] + (K) < (test_data)[2]));
*/
bool check_isolation(const unsigned long long *test_data, unsigned long long K)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((3) == 3 &&         \forall integer k; 0 <= k < (3) ==> (test_data)[k] < 0x8000000000000000ULL);
    //@ assert 0 <= K < test_data[0];

    if (test_data[1] + K < test_data[2]) {
        result = true;
    } else {
        result = false;
    }

    //@ assert ((result) == ((test_data)[1] + (K) < (test_data)[2]));
    return result;
}
