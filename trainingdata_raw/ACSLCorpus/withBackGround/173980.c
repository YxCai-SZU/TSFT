/*@
    predicate x_lt_y(integer x, integer y) = x < y;
    predicate y_lt_z(integer y, integer z) = y < z;
    predicate x_plus_2_le_z_plus_3(integer x, integer z) = x + 2 <= z + 3;
*/

/*@
    logic integer add_2(integer a) = a + 2;
    logic integer add_3(integer a) = a + 3;
*/

/*@
    lemma func_lemma:
        \forall integer x, y, z;
            x_lt_y(x, y) && y_lt_z(y, z) ==> x_plus_2_le_z_plus_3(x, z);
*/

/*@
    lemma test_func_is_transitive_lemma:
        \forall integer x, y, z;
            x_lt_y(x, y) && y_lt_z(y, z) ==> x_plus_2_le_z_plus_3(x, z);
*/

/*@
    requires x_lt_y(x, y) && y_lt_z(y, z);
    ensures x_plus_2_le_z_plus_3(x, z);
*/
void func(int x, int y, int z)
{
    //@ assert x < y;
    //@ assert y < z;
    //@ assert x + 2 <= z + 3;
}

/*@
    requires x_lt_y(x, y) && y_lt_z(y, z);
    ensures x_plus_2_le_z_plus_3(x, z);
*/
void test_func(int x, int y, int z)
{
    func(x, y, z);
}

/*@
    requires x_lt_y(x, y) && y_lt_z(y, z);
    ensures x_plus_2_le_z_plus_3(x, z);
*/
void test_func_is_transitive(int x, int y, int z)
{
    func(x, y, z);
    //@ assert x + 2 <= z + 3;
}

int main(void) {
    return 0;
}
