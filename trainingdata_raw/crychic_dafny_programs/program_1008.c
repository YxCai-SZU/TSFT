// Generated C + ACSL

/*@
    assigns \nothing;
    ensures 0.0 <= \result <= 1.0;
*/
double Main(void)
{
  int* desc1Collect = 0;
  int* desc2Collect = 0;
  int desc1Collect_len = 0;
  int desc2Collect_len = 0;
  int svrBetter = 0;
  int rfrBetter = 0;
  /*@ assert rfrBetter >= 0 && rfrBetter <= 2147483647; */
  int totalComparisons = (svrBetter + rfrBetter);
  int validComparisons = (desc1Collect_len == desc2Collect_len);
  /*@ assert validComparisons; */
  double svrBetterRatio;
  if ((totalComparisons > 0))
  {
    svrBetterRatio = ((double)svrBetter / (double)totalComparisons);
    /*@ assert svrBetterRatio >= 0 && svrBetterRatio <= 1.0; */
  }
  else
  {
    svrBetterRatio = 0.0;
  }
  /* unsupported stmt: print "SVR better than RFR in "; */
  /* unsupported stmt: print svrBetterRatio * 100.0; */
  /* unsupported stmt: print "% of the cases\n"; */
  return svrBetterRatio;  // Dafny implicit return
}

/*@
    requires desc1 != \null;
    requires desc2 != \null;
    requires desc1_len == desc2_len;
    requires desc1_len >= 0;
    requires \valid_read(desc1 + (0 .. desc1_len-1));
    requires \valid_read(desc2 + (0 .. desc2_len-1));
    assigns \nothing;
*/
void CompareDescriptors(int* desc1, int desc1_len, int* desc2, int desc2_len)
{
  /* unsupported stmt: svrBetter, rfrBetter := 0, 0; */
  int svrBetter = 0;
  int rfrBetter = 0;
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
/*@
  loop invariant 0 <= i <= desc1_len;
  loop invariant svrBetter + rfrBetter <= i;
  loop invariant svrBetter >= 0;
  loop invariant rfrBetter >= 0;
  loop invariant svrBetter <= i;
  loop invariant rfrBetter <= i;
  loop assigns i, svrBetter, rfrBetter;
  loop variant desc1_len - i;
*/
  while ((i < desc1_len))
    {
      if ((desc1[i] > desc2[i]))
      {
        svrBetter = (svrBetter + 1);
        /*@ assert svrBetter >= 0 && svrBetter <= 2147483647; */
      }
      else
      if ((desc1[i] < desc2[i]))
      {
        rfrBetter = (rfrBetter + 1);
        /*@ assert rfrBetter >= 0 && rfrBetter <= 2147483647; */
      }
      i = (i + 1);
    }
  /*@ assert ((svrBetter + rfrBetter) <= desc1_len); */
}