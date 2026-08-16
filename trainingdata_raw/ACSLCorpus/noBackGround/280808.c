/*@ requires ((a) + 1 == (a) + 2 - 1);
    ensures ((a) + 1 == (a) + 3 - 2);
*/
void myfun(int a)
{
    //@ assert ((a) + 1 == (a) + 2 - 1);
    //@ assert a + 1 == a + 3 - 2;
}

/*@ requires ((a) + 1 == (a) + 2 - 1);
    ensures ((a) + 1 == (a) + 4 - 3);
*/
void myfun2(int a)
{
    //@ assert ((a) + 1 == (a) + 2 - 1);
    //@ assert a + 1 == a + 4 - 3;
}

/*@ requires ((a) + 1 == (a) + 2 - 1);
    ensures ((a) + 1 == (a) + 5 - 4);
*/
void myfun3(int a)
{
    //@ assert ((a) + 1 == (a) + 2 - 1);
    //@ assert a + 1 == a + 5 - 4;
}

int main()
{
    return 0;
}
