#include <stdbool.h>

/*@
    requires ((n) > 50);
    assigns \nothing;
    ensures \result == true;
 */
bool check_threshold(int n)
{
    bool out;
    //@ assert ((n) > 50);
    out = (n > 50);
    return out;
}

int main()
{
    bool r;
    r = check_threshold(55);
    //@ assert r == true;
    return 0;
}
