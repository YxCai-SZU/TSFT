#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000) && (1 <= (b) && (b) <= 5000) && (1 <= (c) && (c) <= 10000);
    ensures \result == (c <= a + b);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 5000);
    //@ assert (1 <= (b) && (b) <= 5000);
    //@ assert (1 <= (c) && (c) <= 10000);
    //@ assert ((a) + (b) <= 10000);
    
    result = (c <= a + b);
    return result;
}

int main() {
    return 0;
}
