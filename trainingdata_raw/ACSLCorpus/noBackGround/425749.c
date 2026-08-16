#include <stdbool.h>

/*@
    requires a >= b;
    ensures \result == true;
    assigns \nothing;
*/
bool greater_than_or_equal(unsigned char a, unsigned char b)
{
    //@ assert a >= b;
    return true;
}

/*@
    requires a >= b && b >= c;
    ensures \result == true;
    assigns \nothing;
*/
bool greater_than_or_equal_to_c(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    return true;
}

/*@
    requires a > b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void calc_example_4(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps_and_asserts(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps_and_asserts_and_true(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps_and_asserts_and_true_and_last(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
    //@ assert c >= c;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps_and_asserts_and_true_and_last_and_first(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
    //@ assert c >= c;
    //@ assert a >= c;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps_and_asserts_and_true_and_last_and_first_and_second(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
    //@ assert c >= c;
    //@ assert a >= c;
    //@ assert b >= c;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

/*@
    requires a >= b && b >= c;
    ensures a >= c;
    assigns \nothing;
*/
void greater_than_or_equal_to_c_with_calc_and_additional_steps_and_asserts_and_true_and_last_and_first_and_second_and_third(unsigned char a, unsigned char b, unsigned char c)
{
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert a >= c;
    //@ assert c >= c;
    //@ assert a >= c;
    //@ assert b >= c;
    //@ assert a >= b;
    //@ assert a >= b;
    //@ assert b >= c;
    //@ assert c >= c;
    //@ assert a >= c;
}

int main()
{
    return 0;
}
