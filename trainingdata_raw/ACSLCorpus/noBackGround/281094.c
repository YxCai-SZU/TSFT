#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int func(int a)
{
    int result;
    
    //@ assert (1 <= (a) && (a) <= 10);
    result = a;
    
    //@ assert 1 <= a * a && a * a <= 100;
    result += a * a;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    result += a * a * a;
    
    return result;
}

int main()
{
    return 0;
}
