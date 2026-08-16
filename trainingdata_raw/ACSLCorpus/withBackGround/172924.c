#include <stdbool.h>

/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

/*@ predicate sum_in_range(integer a, integer b) = 
        2 <= a + b <= 200; */

/*@ lemma sum_range_lemma: 
      \forall integer a, b; 
      valid_range(a) && valid_range(b) ==> sum_in_range(a, b); */

/*@ requires \valid(input + (0..2));
    requires 1 <= input[0] <= 100;
    requires 1 <= input[1] <= 100;
    requires 1 <= input[2] <= 100;
    ensures \result == (
        (input[0] + input[1] == input[2]) ||
        (input[1] + input[2] == input[0]) ||
        (input[0] + input[2] == input[1])
    );
    assigns \nothing;
*/
bool func(const int input[3]) {
    int a;
    int b;
    int c;
    int sum1;
    int sum2;
    int sum3;
    bool result;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert sum_in_range(a, b);
    //@ assert sum_in_range(b, c);
    //@ assert sum_in_range(a, c);

    sum1 = a + b;
    sum2 = b + c;
    sum3 = a + c;

    result = (sum1 == c) || (sum2 == a) || (sum3 == b);
    return result;
}
