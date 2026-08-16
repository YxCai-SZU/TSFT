/*@
    requires (1 <= (input) <= 10);
    ensures ((\result) == (input) * (1 + (input) * (1 + (input))));
    ensures (1 <= (\result) <= 1110);
*/
int func(int input)
{
    // Variable declarations at scope top
    int result;

    //@ assert 1 <= input && input <= 10;
    //@ assert 1 <= (1 + input) && (1 + input) <= 11;
    //@ assert 1 <= (1 + input * (1 + input)) && (1 + input * (1 + input)) <= 111;
    //@ assert 1 <= input * (1 + input * (1 + input)) && input * (1 + input * (1 + input)) <= 1110;

    result = input * (1 + input * (1 + input));
    return result;
}
