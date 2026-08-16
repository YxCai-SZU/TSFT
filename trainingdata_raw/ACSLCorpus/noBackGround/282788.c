#include <stdbool.h>

/*@
    requires \true;
    ensures \result == (a % 2 == 0 && (b % 2 == 0 || c % 2 == 0));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    //@ assert \true;
    if (a % 2 == 0)
    {
        //@ assert \true;
        if (b % 2 == 0 || c % 2 == 0)
        {
            result = true;
        }
    }
    //@ assert result == (a % 2 == 0 && (b % 2 == 0 || c % 2 == 0));
    return result;
}

/*@
    requires \true;
    ensures \result == ((a % 2 == 0) && ((b % 2 == 0) || (c % 2 == 0)));
    assigns \nothing;
*/
bool func2(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    //@ assert \true;
    if (a % 2 == 0)
    {
        //@ assert \true;
        if (b % 2 == 0 || c % 2 == 0)
        {
            result = true;
        }
    }
    //@ assert result == ((a % 2 == 0) && ((b % 2 == 0) || (c % 2 == 0)));
    return result;
}

/*@
    requires \true;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool is_even_func(unsigned int n)
{
    bool ret = (n % 2) == 0;
    //@ assert ret == (n % 2 == 0);
    return ret;
}

int main()
{
    return 0;
}
