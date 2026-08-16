/*@
    requires (1 <= (k) && (k) <= 100) && (1 <= (x) && (x) <= 100000);
    assigns \nothing;
*/
void func(int k, int x) {
    //@ assert (k * 500 >= x) || (k * 500 < x);
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    assigns \nothing;
*/
void func2(int a, int b) {
    //@ assert ((a + b) % 2 == 0) || ((a + b) % 2 != 0);
}

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    assigns \nothing;
*/
void func3(int a, int b, int c) {
    //@ assert ((a + b + c) % 2 == 0) || ((a + b + c) % 2 != 0);
}
