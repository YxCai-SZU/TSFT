/*@
    predicate is_non_negative(integer value) = value >= 0;
*/


unsigned char example_subtract_20(unsigned char a)
{
    //@ assert is_non_negative(a - 20);
    return a - 20;
}

int main()
{
    return 0;
}
