#include <stdbool.h>
#include <stddef.h>

/*@
    requires x > 10;
    ensures \result == (x % 2 == 0);
    assigns \nothing;
*/
bool even_greater_than_10(unsigned int x)
{
    bool result;
    //@ assert x > 10;
    result = (x % 2 == 0);
    //@ assert result == (x % 2 == 0);
    return result;
}

/*@
    requires x < 5;
    ensures \result == (x % 2 == 1);
    assigns \nothing;
*/
bool odd_less_than_5(unsigned int x)
{
    bool result;
    //@ assert x < 5;
    result = (x % 2 == 1);
    //@ assert result == (x % 2 == 1);
    return result;
}

/*@
    assigns \nothing;
*/
void use_vec(void)
{
    bool r;
    r = even_greater_than_10(14);
    //@ assert r == true;
    //@ assert ((14) > 10 && (14) % 2 == 0);
    r = odd_less_than_5(3);
    //@ assert r == true;
    //@ assert ((3) < 5 && (3) % 2 == 1);
}

int main(void)
{
    use_vec();
    return 0;
}
