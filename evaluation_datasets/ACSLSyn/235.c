/* Scenario: A simple student grade analyzer that combines two operations:
   1. Compute the sum of two assignment scores (0-100 each) using example()
   2. Compute the maximum possible combined score from three single-digit quiz scores (1-9 each) using func()
   The synthesized function validates that the final result respects both the score bounds and the maximum selection property.
*/

/*@
    predicate strictly_increasing(int *arr, integer len) =
        len == 3 &&
        arr[0] < arr[1] &&
        arr[1] < arr[2];
*/

/*@
    lemma calc_example_2: \forall integer a, b, c; a < b && b < c ==> a <= c;
*/

/*@
    lemma example_sum_nonneg: \forall integer x, y; 0 <= x <= 100 && 0 <= y <= 100 ==> 0 <= x + y;
*/

/*@
    lemma example_sum_bound: \forall integer x, y; 0 <= x <= 100 && 0 <= y <= 100 ==> x + y <= 200;
*/

/*@
    lemma is_strictly_increasing_lemma: \forall int *arr; strictly_increasing(arr, 3) ==> arr[0] < arr[2];
*/

int example(int x, int y) {
    //@ assert x >= 0 && y >= 0;
    return x + y;
}

void is_strictly_increasing(int *arr) {
    //@ assert arr[0] < arr[2];
}

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;
    logic integer sum_10a_bc(integer a, integer b, integer c) = 10 * a + b + c;
    logic integer sum_10b_ca(integer a, integer b, integer c) = 10 * b + c + a;
    logic integer sum_10c_ab(integer a, integer b, integer c) = 10 * c + a + b;

    predicate is_valid_result(integer r, integer a, integer b, integer c) =
        r == sum_abc(a, b, c) ||
        r == sum_10a_bc(a, b, c) ||
        r == sum_10b_ca(a, b, c) ||
        r == sum_10c_ab(a, b, c);
*/

int func(int A, int B, int C)
{
    int ans = -100;

    //@ assert ans == -100;

    if (ans > A + B + C)
    {
        //@ assert ans == -100;
    }
    else
    {
        ans = A + B + C;
    }
    //@ assert is_valid_result(ans, A, B, C);

    if (ans > 10 * A + B + C)
    {
        //@ assert is_valid_result(ans, A, B, C);
    }
    else
    {
        ans = 10 * A + B + C;
    }
    //@ assert is_valid_result(ans, A, B, C);

    if (ans > 10 * B + C + A)
    {
        //@ assert is_valid_result(ans, A, B, C);
    }
    else
    {
        ans = 10 * B + C + A;
    }
    //@ assert is_valid_result(ans, A, B, C);

    if (ans > 10 * C + A + B)
    {
        //@ assert is_valid_result(ans, A, B, C);
    }
    else
    {
        ans = 10 * C + A + B;
    }
    //@ assert is_valid_result(ans, A, B, C);

    return ans;
}

int analyze_grades(int score1, int score2, int quiz1, int quiz2, int quiz3) {
    int assignment_total = example(score1, score2);
    //@ assert 0 <= assignment_total <= 200;

    int quiz_max = func(quiz1, quiz2, quiz3);
    //@ assert is_valid_result(quiz_max, quiz1, quiz2, quiz3);

    int final_result = assignment_total + quiz_max;

    //@ assert 0 <= assignment_total <= 200 && is_valid_result(quiz_max, quiz1, quiz2, quiz3);

    return final_result;
}
