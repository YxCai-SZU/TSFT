/*@
    lemma calc_example_8: \forall integer a, b; a <= b ==> a * 3 <= b * 3;
*/

int main() {
    // Proof block 1
    {
        int a = 2;
        int b = 5;
        //@ assert a <= b;
        //@ assert a * 3 <= b * 3;
    }

    // Proof block 2
    {
        int a = 10;
        int b = 15;
        //@ assert a <= b;
        //@ assert a * 3 <= b * 3;
    }

    // Proof block 3
    {
        int a = 20;
        int b = 25;
        //@ assert a <= b;
        //@ assert a * 3 <= b * 3;
    }

    // Proof block 4
    {
        int a = 30;
        int b = 35;
        //@ assert a <= b;
        //@ assert a * 3 <= b * 3;
    }

    // Proof block 5
    {
        int a = 40;
        int b = 45;
        //@ assert a <= b;
        //@ assert a * 3 <= b * 3;
    }

    return 0;
}
