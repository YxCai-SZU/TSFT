#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int func(int r)
{
    int pi = 3;
    int ans;

    //@ assert 2 * r * pi <= 2 * 100 * 3;
    ans = 2 * r * pi;
    return ans;
}

int main()
{
    return 0;
}
