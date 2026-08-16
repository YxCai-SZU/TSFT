/*@
    logic integer diff(integer x, integer y) = x - y;
    logic integer add(integer x, integer y) = x + y;
    logic integer multiply(integer x, integer y) = x * y;
    
    lemma test_diff:
        diff(20, 10) == 10 && diff(20, 0) == 20;
    
    lemma diff_intermediate:
        \forall integer x, y;
            0 <= x <= 20 && 0 <= y <= 10 ==>
            diff(x, y) == x - y;
    
    lemma test_add:
        add(10, 20) == 30 && add(10, 0) == 10;
    
    lemma add_intermediate:
        \forall integer x, y;
            0 <= x <= 10 && 0 <= y <= 20 ==>
            add(x, y) == x + y;
    
    lemma test_multiply:
        multiply(10, 2) == 20 && multiply(10, 0) == 0;
    
    lemma multiply_intermediate:
        \forall integer x, y;
            0 <= x <= 10 && 0 <= y <= 2 ==>
            multiply(x, y) == x * y;
*/

int main() {
    //@ assert diff(20, 10) == 10;
    //@ assert diff(20, 0) == 20;
    //@ assert add(10, 20) == 30;
    //@ assert add(10, 0) == 10;
    //@ assert multiply(10, 2) == 20;
    //@ assert multiply(10, 0) == 0;
    
    return 0;
}
