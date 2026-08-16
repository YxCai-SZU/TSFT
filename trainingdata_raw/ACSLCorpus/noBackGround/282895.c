#include <stdbool.h>

/*@
    requires (1 <= (x) <= 179);
    ensures \result == 48 - x || \result == 48 - x - 1;
    assigns \nothing;
*/
int func(int x)
{
    int ans;

    //@ assert (1 <= (x) <= 179);
    
    if (x < 48) {
        ans = 48 - x;
        //@ assert ans == 48 - x;
    } else {
        ans = 48 - x - 1;
        //@ assert ans == 48 - x - 1;
    }

    //@ assert ans == 48 - x || ans == 48 - x - 1;
    return ans;
}

int main(void)
{
    return 0;
}
