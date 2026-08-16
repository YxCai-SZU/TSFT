/*@
    predicate valid_input(integer input) = 1 <= input && input <= 32;
    predicate valid_result(integer result) = 1 <= result && result <= 51;
    logic integer array_value(integer index) =
        index == 0 ? 1 :
        index == 1 ? 1 :
        index == 2 ? 1 :
        index == 3 ? 2 :
        index == 4 ? 1 :
        index == 5 ? 2 :
        index == 6 ? 1 :
        index == 7 ? 5 :
        index == 8 ? 2 :
        index == 9 ? 2 :
        index == 10 ? 1 :
        index == 11 ? 5 :
        index == 12 ? 1 :
        index == 13 ? 2 :
        index == 14 ? 1 :
        index == 15 ? 14 :
        index == 16 ? 1 :
        index == 17 ? 5 :
        index == 18 ? 1 :
        index == 19 ? 5 :
        index == 20 ? 2 :
        index == 21 ? 2 :
        index == 22 ? 1 :
        index == 23 ? 15 :
        index == 24 ? 2 :
        index == 25 ? 2 :
        index == 26 ? 5 :
        index == 27 ? 4 :
        index == 28 ? 1 :
        index == 29 ? 4 :
        index == 30 ? 1 :
        index == 31 ? 51 : 0;
    lemma index_bounds: \forall integer input; valid_input(input) ==> 0 <= input - 1 && input - 1 < 32;
    lemma result_valid: \forall integer input; valid_input(input) ==> valid_result(array_value(input - 1));
*/

/*@
    requires valid_input(input);
    ensures valid_result(\result);
*/
int func(int input)
{
    int arr[32];
    int index;
    int result;
    
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 1;
    arr[7] = 5;
    arr[8] = 2;
    arr[9] = 2;
    arr[10] = 1;
    arr[11] = 5;
    arr[12] = 1;
    arr[13] = 2;
    arr[14] = 1;
    arr[15] = 14;
    arr[16] = 1;
    arr[17] = 5;
    arr[18] = 1;
    arr[19] = 5;
    arr[20] = 2;
    arr[21] = 2;
    arr[22] = 1;
    arr[23] = 15;
    arr[24] = 2;
    arr[25] = 2;
    arr[26] = 5;
    arr[27] = 4;
    arr[28] = 1;
    arr[29] = 4;
    arr[30] = 1;
    arr[31] = 51;
    
    index = input - 1;
    
    //@ assert 0 <= index && index < 32;
    
    result = arr[index];
    
    //@ assert result >= 1 && result <= 51;
    
    return result;
}
