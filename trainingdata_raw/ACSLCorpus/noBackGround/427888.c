#include <stdbool.h>

/*@
    requires 100 <= n <= 999;
    ensures \result == true <==> (((n) / 100) == 7 || (((n) / 10) % 10) == 7 || (((n) % 100) % 10) == 7);
    assigns \nothing;
*/
bool func(int n)
{
    int original_n = n;
    bool ans = false;

    //@ assert 100 <= original_n <= 999;

    if ((n / 100) == 7) {
        ans = true;
        //@ assert (((original_n) / 100) == 7 || (((original_n) / 10) % 10) == 7 || (((original_n) % 100) % 10) == 7);
    } else if (((n / 10) % 10) == 7) {
        ans = true;
        //@ assert (((original_n) / 100) == 7 || (((original_n) / 10) % 10) == 7 || (((original_n) % 100) % 10) == 7);
    } else if (((n % 100) % 10) == 7) {
        ans = true;
        //@ assert (((original_n) / 100) == 7 || (((original_n) / 10) % 10) == 7 || (((original_n) % 100) % 10) == 7);
    }

    //@ assert ans == true <==> (((original_n) / 100) == 7 || (((original_n) / 10) % 10) == 7 || (((original_n) % 100) % 10) == 7);
    return ans;
}
