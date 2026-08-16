#include <stdbool.h>

/*@
    requires x <= 4294967295;
    ensures \result == true <==> (((x) & 1) == 0);
    assigns \nothing;
*/
bool is_even_c(unsigned int x)
{
    bool ret;
    //@ assert x <= 4294967295;
    ret = (x & 1) == 0;
    //@ assert ret == true <==> (((x) & 1) == 0);
    return ret;
}

int main()
{
    unsigned int _;
    _ = 2;
    return 0;
}
