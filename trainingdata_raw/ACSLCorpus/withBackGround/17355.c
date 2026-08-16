/*@
predicate strict_less(integer x, integer y) = x < y;

lemma calc_example_3: \forall integer x, y, z; x < y && y < z ==> x < z;
lemma calc_example_4: \forall integer x, y, z, a, b; x < y && y < z && z < a && a < b ==> x < b;
*/

/*@
requires x < y && y < z;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_3_proof(int x, int y, int z) {
    //@ assert x < y && y < z;
    return 0;
}

/*@
requires x < y && y < z && z < a && a < b;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_4_proof(int x, int y, int z, int a, int b) {
    //@ assert x < y && y < z && z < a && a < b;
    return 0;
}

/*@
assigns \nothing;
*/
int main() {
    int x = 1;
    int y = 2;
    int z = 3;
    int a = 4;
    int b = 5;
    
    //@ assert x < y && y < z;
    calc_example_3_proof(x, y, z);
    
    //@ assert x < y && y < z && z < a && a < b;
    calc_example_4_proof(x, y, z, a, b);
    
    return 0;
}
