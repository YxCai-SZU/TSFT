#include <stdint.h>
/*@
    requires ((x) < UINT32_MAX);
    ensures \result == ((x) + 1);
    assigns \nothing;
*/
uint32_t add_one(uint32_t x)
{
    uint32_t result;
    //@ assert ((x) < UINT32_MAX);
    result = x + 1;
    //@ assert result == ((x) + 1);
    return result;
}

/*@
    requires ((x) < UINT32_MAX);
    ensures \result == ((x) + 1);
    assigns \nothing;
*/
uint32_t main2(uint32_t x)
{
    uint32_t result;
    result = add_one(x);
    //@ assert result == ((x) + 1);
    return result;
}

/*@
    assigns \nothing;
*/
void use_add_one(void)
{
    uint32_t x;
    uint32_t result;
    x = 50;
    //@ assert ((x) < UINT32_MAX);
    result = main2(x);
    //@ assert result == ((x) + 1);
}

/*@
    assigns \nothing;
*/
int main(void)
{
    use_add_one();
    return 0;
}
