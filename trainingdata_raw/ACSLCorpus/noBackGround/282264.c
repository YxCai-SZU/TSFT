/*@
    requires (1 <= (input) && (input) <= 10000);
    ensures \result == ((input) / 3);
    assigns \nothing;
*/
int func(int input)
{
    int result;
    int temp_input;
    
    result = 0;
    temp_input = input;
    
    /*@
        loop invariant 1 <= input <= 10000;
        loop invariant 0 <= temp_input <= input;
        loop invariant result == (input - temp_input) / 3;
        loop invariant input == temp_input + 3 * result;
        loop assigns temp_input, result;
        loop variant temp_input;
    */
    while (temp_input >= 3)
    {
        //@ assert temp_input >= 3;
        temp_input = temp_input - 3;
        result = result + 1;
        //@ assert input == temp_input + 3 * result;
    }
    
    //@ assert result == ((input) / 3);
    return result;
}
