/*@
    requires \true;
    ensures \forall integer x, y; x <= y ==> ((x) / 2) <= ((y) / 2);
*/
void establish_forall()
{
    //@ assert \forall integer x, y; x <= y ==> ((x) / 2) <= ((y) / 2);
}

/*@
    requires \true;
    ensures \forall integer x, y; x <= y ==> ((x) / 2) <= ((y) / 2);
*/
void establish_forall_conseq()
{
    //@ assert \forall integer x, y; x <= y ==> ((x) / 2) <= ((y) / 2);
}

int main()
{
    establish_forall();
    establish_forall_conseq();
    return 0;
}
