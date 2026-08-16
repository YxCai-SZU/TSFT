#include <stdint.h>
#include <stdbool.h>

/*@
    requires \valid(m + (0..9));
    ensures (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    assigns m[0..9];
*/
void test_remove_all(int *m)
{
    //@ ghost int i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> m[j] == 0;
        loop assigns i, m[0..9];
    */
    for (int i = 0; i < 10; ++i)
    {
        m[i] = 0;
        //@ assert m[i] == 0;
    }
    //@ assert (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
}

/*@
    requires \valid(m + (0..9));
    ensures (\forall integer i; 0 <= i < 10 ==> 
            (i == (3) ==> (m)[i] == (4)) &&
            (i != (3) ==> (m)[i] == 0));
    assigns m[0..9];
*/
void test_insert_all(int *m)
{
    //@ ghost int i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> m[j] == 0;
        loop assigns i, m[0..9];
    */
    for (int i = 0; i < 10; ++i)
    {
        m[i] = 0;
        //@ assert m[i] == 0;
    }
    m[3] = 4;
    //@ assert (\forall integer i; 0 <= i < 10 ==>              (i == (3) ==> (m)[i] == (4)) &&             (i != (3) ==> (m)[i] == 0));
}

/*@
    requires \valid(m + (0..9));
    ensures (\forall integer i; 0 <= i < 10 ==> 
            (i == (3) ==> (m)[i] == (4)) &&
            (i != (3) ==> (m)[i] == 0));
    assigns m[0..9];
*/
void main3(int *m)
{
    test_remove_all(m);
    //@ assert (\forall integer i; 0 <= i < 10 ==> (m)[i] == 0);
    test_insert_all(m);
    //@ assert (\forall integer i; 0 <= i < 10 ==>              (i == (3) ==> (m)[i] == (4)) &&             (i != (3) ==> (m)[i] == 0));
}
