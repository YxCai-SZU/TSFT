/*@
predicate is_even(integer x) = x % 2 == 0;
predicate is_odd(integer x) = x % 2 != 0;

lemma is_even_check: \forall integer a, b; is_even(a) && is_even(b) ==> is_even(a + b);
lemma is_odd_check: \forall integer a, b; is_odd(a) && is_odd(b) ==> is_even(a + b);
lemma choose_t_even: \forall integer i, a, b; 0 <= i && i < 3 && is_even(a) && is_even(b) ==> is_even((i == 2) ? a : b);
*/


int add_even_numbers(int a, int b) {
    //@ assert is_even(a) && is_even(b);
    int result;
    result = a + b;
    //@ assert is_even(result);
    return result;
}


int add_odd_numbers(int a, int b) {
    //@ assert is_odd(a) && is_odd(b);
    int result;
    result = a + b;
    //@ assert is_even(result);
    return result;
}


int conditional_even(int i, int a, int b) {
    //@ assert 0 <= i && i < 3;
    //@ assert is_even(a) && is_even(b);
    int result;
    if (i == 2) {
        result = a;
    } else {
        result = b;
    }
    //@ assert is_even(result);
    return result;
}

int main() {
    return 0;
}
