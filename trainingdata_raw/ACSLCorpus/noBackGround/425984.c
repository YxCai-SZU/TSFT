#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000);
    ensures \result <==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 5000);
    //@ assert (1 <= (b) <= 5000);
    //@ assert (1 <= (c) <= 5000);
    
    return (a + b == c) || (a + c == b) || (b + c == a);
}

int main()
{
    unsigned int a = 1;
    unsigned int b = 1;
    unsigned int c = 1;
    bool result = func(a, b, c);
    return 0;
}
