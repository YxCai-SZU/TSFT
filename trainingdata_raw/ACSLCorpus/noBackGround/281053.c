/*@
  requires \valid(a) && \valid(b) && \valid(c);
  requires *a > 0 && *b > 0 && *c > 0;
  ensures (*a + *b) * *c == *a * *c + *b * *c;
*/
void non_linear_arith_example15(int* a, int* b, int* c) {
    // Variable declarations at scope top
    int a_val;
    int b_val;
    int c_val;
    int sum_ab;
    int left_side;
    int right_side;
    
    a_val = *a;
    b_val = *b;
    c_val = *c;
    
    //@ assert a_val > 0;
    //@ assert b_val > 0;
    //@ assert c_val > 0;
    
    sum_ab = a_val + b_val;
    //@ assert sum_ab > 0;
    
    left_side = sum_ab * c_val;
    right_side = a_val * c_val + b_val * c_val;
    
    //@ assert left_side == right_side;
}

int main() {
    return 0;
}
