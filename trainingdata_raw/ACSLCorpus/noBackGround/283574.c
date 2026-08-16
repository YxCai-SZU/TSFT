/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == (((a) * 3 + (b)) / 2);
*/
int func(int a, int b)
{
    int result;
    int answer;
    int count;
    int temp_result;
    
    result = a * 3 + b;
    answer = 0;
    count = 0;
    temp_result = result;
    
    /*@
        loop invariant 0 <= temp_result <= result;
        loop invariant 0 <= count <= result / 2;
        loop invariant temp_result == result - 2 * count;
        loop invariant answer == count;
        loop assigns answer, temp_result, count;
    */
    while (temp_result >= 2)
    {
        //@ assert temp_result >= 2;
        answer += 1;
        temp_result -= 2;
        count += 1;
    }
    
    //@ assert answer == (((a) * 3 + (b)) / 2);
    return answer;
}
