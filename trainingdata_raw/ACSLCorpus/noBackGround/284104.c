#include <stdbool.h>

/*@
  requires (100 <= (n) && (n) <= 999);
  ensures \result == (n / 100 == 7 || (n / 10) % 10 == 7 || n % 10 == 7);
  assigns \nothing;
*/
bool func(int n)
{
    // Variable declarations at top of scope
    int n_100;
    int n_10;
    int n_1;
    bool result;

    // Precondition verification
    //@ assert (100 <= (n) && (n) <= 999);

    // Arithmetic bounds verification
    //@ assert n / 100 <= 9;
    //@ assert n / 10 <= 99;
    //@ assert n % 10 <= 9;

    n_100 = n / 100;
    n_10 = (n / 10) % 10;
    n_1 = n % 10;

    result = (n_100 == 7 || n_10 == 7 || n_1 == 7);
    return result;
}
