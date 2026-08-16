/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a) + (b) + (c)) || \result == ((a) + (c) + 1);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int result_2;
    int max_result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a + b + c >= 0) {
        result = a + b + c;
    } else {
        result = a + c + 1;
    }

    if (a + c + 1 >= 0) {
        result_2 = a + c + 1;
    } else {
        result_2 = a + b + c;
    }

    if (result > result_2) {
        max_result = result;
    } else {
        max_result = result_2;
    }

    //@ assert max_result == ((a) + (b) + (c)) || max_result == ((a) + (c) + 1);
    
    return max_result;
}
