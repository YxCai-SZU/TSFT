#include <stdbool.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int local_a = a;
    int local_b = b;
    int temp;

    if (local_a > local_b)
    {
        //@ assert local_a > local_b;
        temp = local_a;
        local_a = local_b;
        local_b = temp;
        //@ assert local_a <= local_b;
    }

    //@ assert local_a <= local_b;
    if (local_b >= local_a + 1)
    {
        //@ assert local_b >= local_a + 1;
        //@ assert local_a + local_b >= 0;
        return local_a + local_b;
    }
    else
    {
        //@ assert local_b < local_a + 1;
        //@ assert 3 <= local_b <= 20;
        //@ assert local_b * 2 - 1 >= 0;
        return local_b * 2 - 1;
    }
}
