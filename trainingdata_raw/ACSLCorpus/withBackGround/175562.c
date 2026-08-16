/*@
predicate example_range(integer x, integer y) =
    2 <= x && x <= 100 &&
    2 <= y && y <= 100;

lemma distributive_property:
    \forall integer x, y;
    example_range(x, y) ==> 2 * (x + y) == 2 * x + 2 * y;

lemma distributive_property_2:
    \forall integer x, y;
    example_range(x, y) ==> 2 * (x + y) == 2 * x + 2 * y;
*/

/*@
    requires example_range(x, y);
    ensures \result == 2 * (x + y);
    ensures \result == 2 * x + 2 * y;
*/
int property_example(int x, int y)
{
    //@ assert example_range(x, y);
    //@ assert 2 * (x + y) == 2 * x + 2 * y;
    return 2 * (x + y);
}

/*@
    requires example_range(x, y);
    ensures \result == 2 * (x + y);
    ensures \result == 2 * x + 2 * y;
*/
int property_example_2(int x, int y)
{
    //@ assert example_range(x, y);
    //@ assert 2 * (x + y) == 2 * x + 2 * y;
    return 2 * (x + y);
}

int main()
{
    int x;
    int y;
    int result1;
    int result2;
    
    x = 50;
    y = 50;
    result1 = property_example(x, y);
    result2 = property_example_2(x, y);
    
    return 0;
}
