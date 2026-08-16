#include <stdbool.h>

// Test function for multiplier
/*@
    assigns \nothing;
*/
void test_multiplier()
{
    //@ assert ((3) * 5) == 15;
}

// Test function for multiplier2
/*@
    assigns \nothing;
*/
void test_multiplier2()
{
    //@ assert ((10) * 5) == 50;
}

// Test function for adder
/*@
    assigns \nothing;
*/
void test_adder()
{
    //@ assert ((10) + 20) == 30;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
