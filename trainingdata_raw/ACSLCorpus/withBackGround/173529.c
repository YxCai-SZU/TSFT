/*@
predicate is_valid_addition(integer x, integer y, integer z) =
    x == 2 && y == 3 && z == 5;

lemma addition_bound: \forall integer x, y, z;
    is_valid_addition(x, y, z) ==> x + y <= z + 4;
*/

/*@
requires is_valid_addition(x, y, z);
ensures \result == 0;
*/
int calc_example_addition(int x, int y, int z) {
    // Variable declarations at scope top
    int a;
    int b;
    int c;
    int result = 0;
    
    a = 2;
    b = 3;
    c = 5;
    
    //@ assert a == 2;
    //@ assert b == 3;
    //@ assert c == 5;
    //@ assert a + b <= c + 4;
    
    return result;
}

int main() {
    int x = 2;
    int y = 3;
    int z = 5;
    
    //@ assert is_valid_addition(x, y, z);
    calc_example_addition(x, y, z);
    return 0;
}
