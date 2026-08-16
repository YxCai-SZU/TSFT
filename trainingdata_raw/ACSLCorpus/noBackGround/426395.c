/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    unsigned int half_sum;
    unsigned int result;

    sum = a + b;
    half_sum = sum / 2;

    if (sum % 2 == 0) {
        result = half_sum;
        //@ assert result == (((a) + (b) + 1) / 2);
        return result;
    } else {
        result = half_sum + 1;
        //@ assert result == (((a) + (b) + 1) / 2);
        return result;
    }
}
