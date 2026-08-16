/*@ axiomatic MathProofs {
    predicate square_minus_zero_is_square(integer x) = x * x - 0 == x * x;
    predicate cubing_n(integer x) = x * x * x == x * x * x;
    predicate calc_example_addition(integer a, integer b) = a + b == a + b;
    predicate cubing_and_adding_n(integer x, integer y) = x * x * x + y == x * x * x + y;
    predicate doubling_affects_n_times_3(integer n) = 3 * n * 2 == 6 * n;
    predicate cubing_n_times_3(integer x) = 3 * x * x * x == 3 * x * x * x;
} */

/*@ lemma square_minus_zero_is_square_lemma: 
      \forall integer x; square_minus_zero_is_square(x); */

/*@ lemma cubing_n_lemma: 
      \forall integer x; cubing_n(x); */

/*@ lemma calc_example_addition_lemma: 
      \forall integer a, b; calc_example_addition(a, b); */

/*@ lemma cubing_and_adding_n_lemma: 
      \forall integer x, y; cubing_and_adding_n(x, y); */

/*@ lemma doubling_affects_n_times_3_lemma: 
      \forall integer n; doubling_affects_n_times_3(n); */

/*@ lemma cubing_n_times_3_lemma: 
      \forall integer x; cubing_n_times_3(x); */

int main() {
    //@ assert square_minus_zero_is_square(5);
    //@ assert cubing_n(5);
    //@ assert calc_example_addition(5, 3);
    //@ assert cubing_and_adding_n(5, 3);
    //@ assert doubling_affects_n_times_3(5);
    //@ assert cubing_n_times_3(5);
    return 0;
}
