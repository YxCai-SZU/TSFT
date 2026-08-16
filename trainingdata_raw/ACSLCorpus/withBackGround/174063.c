/*@
    predicate input_in_range(integer i) = 1 <= i && i <= 100000000000000;
    
    logic integer division_by_subtraction(integer input, integer temp) = (input - temp) / 2;
    
    lemma division_lemma: \forall integer input, integer temp, integer result;
        input == temp + 2 * result ==> division_by_subtraction(input, temp) == result;
*/

/*@
    requires input_in_range(input);
    ensures \result == (input / 2) - 1;
*/
long func(long input) {
    long result;
    long temp_input;
    
    result = 0;
    temp_input = input;
    
    /*@
        loop invariant 0 <= temp_input <= input;
        loop invariant result == division_by_subtraction(input, temp_input);
        loop invariant input == temp_input + 2 * result;
        loop assigns temp_input, result;
    */
    while (temp_input >= 2) {
        //@ assert temp_input >= 2;
        temp_input -= 2;
        result += 1;
    }
    
    //@ assert result == (input / 2);
    result -= 1;
    
    return result;
}
