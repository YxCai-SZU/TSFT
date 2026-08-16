/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result <= 0 || \result == a - b * 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    
    if (a <= b * 2) {
        result = 0;
    } else {
        result = a - b * 2;
    }

    //@ assert result == ((a) <= (b) * 2 ? 0 : (a) - (b) * 2);
    //@ assert result <= 0 || result == a - b * 2;

    return result;
}
