#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == ((n) / 2 + (n) % 2);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    
    //@ assert (1 <= (n) && (n) <= 1000000);
    
    if (n % 2 == 1) {
        //@ assert n / 2 + 1 == ((n) / 2 + (n) % 2);
        result = n / 2 + 1;
    } else {
        //@ assert n / 2 == ((n) / 2 + (n) % 2);
        result = n / 2;
    }
    
    //@ assert result == ((n) / 2 + (n) % 2);
    return result;
}

int main()
{
    return 0;
}
