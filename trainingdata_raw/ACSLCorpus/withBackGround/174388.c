/*@
    predicate valid_params(integer X, integer A, integer B) =
        1 <= A && A <= 1000 &&
        1 <= B && B <= 1000 &&
        A + B <= X && X <= 10000 &&
        X % 1 == 0 &&
        A % 1 == 0 &&
        B % 1 == 0;

    logic integer compute_answer(integer X, integer A, integer B) =
        (X - A) > B ? (X - A) : B;

    lemma answer_bounds:
        \forall integer X, A, B;
        valid_params(X, A, B) ==>
        compute_answer(X, A, B) >= 0 &&
        compute_answer(X, A, B) <= X;

    lemma answer_cases:
        \forall integer X, A, B;
        valid_params(X, A, B) ==>
        compute_answer(X, A, B) == X - A ||
        compute_answer(X, A, B) == B;
*/

/*@
    requires valid_params(X, A, B);
    ensures \result >= 0;
    ensures \result <= X;
    ensures \result == X - A || \result == B;
*/
long func(long X, long A, long B)
{
    long answer;

    //@ assert valid_params(X, A, B);
    
    if (X - A > B)
    {
        answer = X - A;
        //@ assert answer == X - A;
    }
    else
    {
        answer = B;
        //@ assert answer == B;
    }

    //@ assert answer >= 0;
    //@ assert answer <= X;
    //@ assert answer == X - A || answer == B;
    
    return answer;
}
