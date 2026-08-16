/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result <= ((p) + (a) * 3);
    ensures \result >= 0;
*/
unsigned int func(unsigned int a, unsigned int p) {
    unsigned int result;
    unsigned int result_div_by_2;
    unsigned int temp_result;
    unsigned int count;

    result = p + a * 3;
    result_div_by_2 = 0;
    temp_result = result;
    count = 0;

    /*@
        loop invariant 0 <= temp_result;
        loop invariant count <= result / 2;
        loop invariant temp_result + 2 * count == result;
        loop assigns temp_result, count;
    */
    while (temp_result >= 2) {
        //@ assert temp_result >= 2;
        temp_result -= 2;
        count += 1;
    }
    result_div_by_2 = count;

    //@ assert result_div_by_2 <= ((p) + (a) * 3);
    return result_div_by_2;
}
