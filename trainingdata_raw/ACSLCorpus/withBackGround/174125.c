/*@
    predicate is_valid_input(integer a) = 1 <= a && a <= 10;

    logic integer func_spec(integer a) = a + a * a + a * a * a;

    lemma func_example_1: \forall integer a; a == 2 ==> func_spec(a) == 2 + 4 + 8;
    lemma func_example_2: \forall integer a; a == 3 ==> func_spec(a) == 3 + 9 + 27;
    lemma func_example_3: \forall integer a; a == 4 ==> func_spec(a) == 4 + 16 + 64;
    lemma func_example_4: \forall integer a; a == 5 ==> func_spec(a) == 5 + 25 + 125;
    lemma func_example_5: \forall integer a; a == 6 ==> func_spec(a) == 6 + 36 + 216;
    lemma func_example_6: \forall integer a; a == 7 ==> func_spec(a) == 7 + 49 + 343;
    lemma func_example_7: \forall integer a; a == 8 ==> func_spec(a) == 8 + 64 + 512;
    lemma func_example_8: \forall integer a; a == 9 ==> func_spec(a) == 9 + 81 + 729;
    lemma func_example_9: \forall integer a; a == 10 ==> func_spec(a) == 10 + 100 + 1000;
*/

/*@
    requires is_valid_input(a);
    ensures \result == func_spec(a);
*/
int func(int a)
{
    //@ assert a >= 1 && a <= 10;
    int result;
    result = a + a * a + a * a * a;
    //@ assert result == func_spec(a);
    return result;
}

int main()
{
    return 0;
}
