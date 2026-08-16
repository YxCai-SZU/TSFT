/*@
    lemma multiplication_distributive: \forall integer x, y; x * (y + 1) == x * y + x;
    lemma multiplication_distributive_3: \forall integer x, y; x * (y + 3) == x * y + 3 * x;
    lemma multiplication_distributive_4: \forall integer x, y; x * (y + 4) == x * y + 4 * x;
    lemma multiplication_distributive_6: \forall integer x, y; x * (y + 6) == x * y + 6 * x;
    lemma multiplication_distributive_2: \forall integer x, y; x * (y + 2) == x * y + 2 * x;
*/

/*@
    requires x >= 0 && y >= 0;
    ensures \result == x * (y + 6) && \result == x * y + 6 * x;
*/
int calc_example_9(int x, int y) {
    //@ assert x * (y + 6) == x * y + 6 * x;
    return x * (y + 6);
}

int main() {
    int x;
    int y;
    int result;
    
    x = 0;
    y = 0;
    result = calc_example_9(x, y);
    
    return 0;
}
