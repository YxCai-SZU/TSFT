/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == (t / a) * b;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int t)
{
    unsigned int number_of_groups;
    unsigned int total_b;

    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);

    number_of_groups = t / a;

    //@ assert number_of_groups == t / a;
    //@ assert number_of_groups * b <= 400;

    total_b = number_of_groups * b;

    //@ assert total_b == (t / a) * b;
    return total_b;
}
