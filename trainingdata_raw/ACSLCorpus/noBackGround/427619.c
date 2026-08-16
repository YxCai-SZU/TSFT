#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert ((a) * (b)) <= 100 * 100;
    return a * b;
}

/*@
    ensures ((0) >= 0);
    assigns \nothing;
*/
int* read_vec(void)
{
    static int empty_vec[1];
    //@ assert ((0) >= 0);
    return empty_vec;
}

int main(void)
{
    return 0;
}
