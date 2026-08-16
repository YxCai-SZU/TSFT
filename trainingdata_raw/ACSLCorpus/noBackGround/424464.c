#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <= 300;
*/
int proof_for_embeded_code(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert ((a) + (b) + (c)) <= 300;
    return a + b + c;
}

int main()
{
    return 0;
}
