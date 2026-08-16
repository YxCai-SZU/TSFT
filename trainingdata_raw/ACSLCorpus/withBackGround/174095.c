#include <stdbool.h>

/*@ predicate pairwise_distinct(integer a, integer b, integer c) =
      a != b && b != c && a != c;
*/

/*@ predicate all_distinct(int *arr, integer len) =
      \forall integer i, j; 0 <= i < j < len ==> arr[i] != arr[j];
*/

/*@ lemma pairwise_distinct_implies:
      \forall integer a, b, c;
        pairwise_distinct(a, b, c) <==> (a != b && b != c && a != c);
*/

/*@ requires \valid(v+(0..2));
    requires all_distinct(v, 3);
    ensures \result == true <==> (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]);
*/
bool func(int *v) {
    int a;
    int b;
    int c;
    bool result;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert a != b && b != c && a != c;

    result = (a != b && b != c && a != c);
    return result;
}

int main() {
    //@ assert 1 != 2 && 2 != 3 && 1 != 3;
    //@ assert !(1 != 1 && 1 != 2 && 1 != 2);
    return 0;
}
