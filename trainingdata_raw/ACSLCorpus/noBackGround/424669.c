/*@
    requires (100 <= (input) && (input) <= 999 &&
        (input) == 100 * ((input) / 100));
    ensures \result == (100 * ((input) / 100) + ((input) % 100));
    assigns \nothing;
*/
int func(int input)
{
    int quotient;
    int remainder;

    quotient = 0;
    remainder = input;

    /*@
        loop invariant 100 <= input && input <= 999;
        loop invariant 0 <= quotient;
        loop invariant quotient <= input / 100;
        loop invariant remainder == input - 100 * quotient;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        quotient = quotient + 1;
        remainder = remainder - 100;
    }

    //@ assert remainder == input % 100;
    //@ assert quotient == input / 100;
    return 100 * quotient + remainder;
}
