/*@
    requires 10 <= n <= 99;
    ensures \result == (n / 10 == 9 || n % 10 == 9);
    assigns \nothing;
*/
int func(unsigned long n)
{
    int is_nine;
    unsigned long temp_n;
    unsigned long last_digit;

    is_nine = 0;
    temp_n = n;

    // Remove the last digit
    last_digit = temp_n % 10;
    temp_n = temp_n / 10;

    // Check the last digit
    if (last_digit == 9)
    {
        is_nine = 1;
    }

    // Check the remaining digit
    if (temp_n == 9)
    {
        is_nine = 1;
    }

    //@ assert is_nine == (n / 10 == 9 || n % 10 == 9);

    return is_nine;
}
