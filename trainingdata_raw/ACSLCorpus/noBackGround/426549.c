/*@
    requires num_list_entries_per_node <= 18446744073709551615ULL / (list_element_size + metadata_size);
    ensures num_list_entries_per_node * (list_element_size + metadata_size) <= 18446744073709551615ULL;
*/
void nonlinear_arithmetic_example_1(unsigned long long num_list_entries_per_node,
                                    unsigned int list_element_size,
                                    unsigned int metadata_size)
{
    //@ assert num_list_entries_per_node * (list_element_size + metadata_size) <= 18446744073709551615ULL;
}

/*@
    requires first <= 100 && second <= 100 && third <= 100;
    requires first * second * third <= 1000000;
    ensures first * second * third <= 1000000;
*/
void nonlinear_arithmetic_example_2(unsigned int first,
                                    unsigned int second,
                                    unsigned int third)
{
    //@ assert first * second * third <= 1000000;
}

/*@
    requires x <= 100 && y <= 100;
    requires x * y <= 10000;
    ensures x * y <= 10000;
*/
void nonlinear_arithmetic_example_3(int x, int y)
{
    //@ assert x * y <= 10000;
}

/*@
    requires a <= 100 && b <= 100;
    requires a * b <= 10000;
    ensures a * b <= 10000;
*/
void nonlinear_arithmetic_example_4(int a, int b)
{
    //@ assert a * b <= 10000;
}

/*@
    requires x <= 100 && y <= 100;
    requires x * y <= 10000;
    ensures x * y <= 10000;
*/
void nonlinear_arithmetic_example_5(int x, int y)
{
    //@ assert x * y <= 10000;
}

int main()
{
    return 0;
}
