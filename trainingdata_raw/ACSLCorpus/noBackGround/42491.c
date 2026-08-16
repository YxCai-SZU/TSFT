/*@
    requires input >= 1 && input <= 100;
    ensures \result >= 1 && \result <= 100;
    ensures \result == input / 2 + 1 || \result == input / 2;
*/
int func(int input)
{
    int result;
    int count;
    int temp_input;
    
    result = 0;
    count = 0;
    temp_input = input;
    
    /*@
        loop invariant ((temp_input) >= 0 && (count) >= 0 && (temp_input) + 2 * (count) == (input));
        loop assigns temp_input, count;
    */
    while (temp_input >= 2)
    {
        //@ assert temp_input >= 2;
        temp_input = temp_input - 2;
        //@ assert temp_input >= 0;
        count = count + 1;
        //@ assert count >= 0;
    }
    
    //@ assert temp_input >= 0 && temp_input <= 1;
    
    if (temp_input == 1)
    {
        result = count + 1;
        //@ assert result == input / 2 + 1;
    }
    else
    {
        result = count;
        //@ assert result == input / 2;
    }
    
    //@ assert result >= 1 && result <= 100;
    return result;
}
