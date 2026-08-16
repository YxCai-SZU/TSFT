// Generated C + ACSL

/*@
    requires opt == 0 || opt == 1;
    requires f == 0 || f == 1;
    requires opt == 1 ==> f == 1;
    assigns \nothing;
    ensures (opt == 1) <==> (\result == 1);
    ensures \result == opt;
*/
int MapOption(int opt, int f)
{
  if (opt == 1) {
    return 1;
  } else {
    return 0;
  }
}

/*@
    requires opt == 0 || opt == 1;
    requires f == 0 || f == 1;
    requires opt == 1 ==> f != 0;
    assigns \nothing;
    ensures (opt == 1 && f != 0) ==> (\result == 0 || \result == 1);
    ensures (opt == 0) ==> (\result == 0);
    ensures opt == 1 ==> \result == f;
    ensures opt == 0 ==> \result == 0;
*/
int FlatMapOption(int opt, int f)
{
  if (opt == 1) {
    /*@ assert f == 0 || f == 1; */
    /*@ assert f != 0; */
    /*@ assert f == 1; */
    return f;
  } else {
    /*@ assert opt == 0; */
    return 0;
  }
}