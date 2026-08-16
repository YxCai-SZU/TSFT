#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    ensures \result == ((a) + (b)) || \result == ((a) * (b));
    ensures \result >= ((a) + (b));
    ensures \result >= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int add;
    int mul;
    int ret;

    //@ assert (1 <= (a) && (a) <= 20);
    //@ assert (1 <= (b) && (b) <= 20);
    //@ assert ((a) * (b)) <= 400;

    add = a + b;
    mul = a * b;

    if (add > mul)
    {
        ret = add;
    }
    else
    {
        ret = mul;
    }

    //@ assert ret == ((a) + (b)) || ret == ((a) * (b));
    //@ assert ret >= ((a) + (b));
    //@ assert ret >= ((a) * (b));
    return ret;
}

int main()
{
    return 0;
}
