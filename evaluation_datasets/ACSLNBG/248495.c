
int func(int input)
{
    // Variable declarations at top of scope
    int cube;

    //@ assert (-1290 <= (input) && (input) <= 1290);
    //@ assert -1290*1290 <= input * input && input * input <= 1290*1290;
    //@ assert -1290*1290*1290 <= input * input * input && input * input * input <= 1290*1290*1290;

    cube = input * input * input;
    return cube;
}
