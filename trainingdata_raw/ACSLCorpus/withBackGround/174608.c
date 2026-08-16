/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;

    lemma answer_satisfies:
        \forall integer a, b, c, answer;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        (answer == sum_ab(a,b) || answer == sum_bc(b,c) || answer == sum_ca(c,a)) ==>
        answer >= 0 && answer <= a + b + c;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= a + b + c;
    ensures \result == a + b || \result == b + c || \result == c + a;
*/
int func(int a, int b, int c)
{
    int answer;
    int current;
    int max_value;

    answer = -1;
    current = 0;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    if (a > b && a > c) {
        max_value = a;
    } else if (b > c) {
        max_value = b;
    } else {
        max_value = c;
    }

    //@ assert max_value == a || max_value == b || max_value == c;

    current = a + b;
    //@ assert current == sum_ab(a,b);
    if (current > max_value) {
        //@ assert current > max_value;
        if (answer == -1 || current < answer) {
            answer = current;
        }
    }

    current = b + c;
    //@ assert current == sum_bc(b,c);
    if (current > max_value) {
        //@ assert current > max_value;
        if (answer == -1 || current < answer) {
            answer = current;
        }
    }

    current = c + a;
    //@ assert current == sum_ca(c,a);
    if (current > max_value) {
        //@ assert current > max_value;
        if (answer == -1 || current < answer) {
            answer = current;
        }
    }

    //@ assert answer == a + b || answer == b + c || answer == c + a;

    return answer;
}
