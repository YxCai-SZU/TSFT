/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    lemma result_bound:
        \forall integer a, b, c, min, result;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        min == (a < b ? (a < c ? a : c) : (b < c ? b : c)) &&
        result == (2*min <= a+b+c ? 1 : 0) + (2*min+1 <= a+b+c ? 1 : 0) + (2*min+2 <= a+b+c ? 1 : 0)
        ==> 0 <= result <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures 0 <= \result <= 100;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min;
    unsigned int result;
    unsigned int temp;

    min = a;
    //@ assert min == a;
    if (b < min) {
        min = b;
    }
    //@ assert min == (a < b ? a : b);
    if (c < min) {
        min = c;
    }
    //@ assert min == (a < b ? (a < c ? a : c) : (b < c ? b : c));

    result = 0;
    temp = 2 * min;
    //@ assert temp == 2 * min;
    if (temp <= a + b + c) {
        result += 1;
    }
    //@ assert result == (2*min <= a+b+c ? 1 : 0);

    temp = 2 * min + 1;
    //@ assert temp == 2 * min + 1;
    if (temp <= a + b + c) {
        result += 1;
    }
    //@ assert result == (2*min <= a+b+c ? 1 : 0) + (2*min+1 <= a+b+c ? 1 : 0);

    temp = 2 * min + 2;
    //@ assert temp == 2 * min + 2;
    if (temp <= a + b + c) {
        result += 1;
    }
    //@ assert result == (2*min <= a+b+c ? 1 : 0) + (2*min+1 <= a+b+c ? 1 : 0) + (2*min+2 <= a+b+c ? 1 : 0);

    //@ assert 0 <= result <= 100;
    return result;
}
