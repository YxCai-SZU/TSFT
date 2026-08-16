#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires ((len) >= 3 &&
        \valid((a) + (0 .. (len) - 1)) &&
        1 <= (a)[0] <= 100 &&
        1 <= (a)[1] <= 20 &&
        1 <= (a)[2] <= 2000);
    ensures 1 <= \result <= a[2];
    assigns \nothing;
*/
int64_t func(int64_t* a, size_t len)
{
    // Variable declarations at top of scope
    int64_t pay;
    int64_t ans;

    // Precondition checks
    //@ assert 1 <= a[0] && a[0] <= 100;
    //@ assert 1 <= a[1] && a[1] <= 20;
    
    // Product bounds verification
    //@ assert a[0] * a[1] <= 2000;

    pay = a[0] * a[1];
    
    if (pay < a[2]) {
        ans = pay;
    } else {
        ans = a[2];
    }

    // Result bounds verification
    //@ assert 1 <= ans <= a[2];

    return ans;
}
