#include <limits.h>

/*@
    requires (0 <= (a)) && ((0) <= (a) && (a) <= (10));
    requires (0 <= (b)) && ((0) <= (b) && (b) <= (5));
    ensures ((a) + (b) <= (15));
*/
void calc_example_2(int a, int b)
{
    //@ assert (0 <= (a)) && ((0) <= (a) && (a) <= (10));
    //@ assert (0 <= (b)) && ((0) <= (b) && (b) <= (5));
    //@ assert (0 <= (a + b)) && ((0) <= (a + b) && (a + b) <= (15));
    //@ assert ((a) + (b) <= (15));
}

/*@
    requires (0 <= (a)) && ((0) <= (a) && (a) <= (10));
    requires (0 <= (b)) && ((0) <= (b) && (b) <= (5));
    ensures (0 <= (a) * (b) && (a) * (b) <= (50));
*/
void assert_example_2(int a, int b)
{
    //@ assert (0 <= (a) * (b) && (a) * (b) <= (50));
}

int main()
{
    return 0;
}
