// Generated C + ACSL

int saved_money;

/*@
    requires saved_money >= 0 && saved_money <= 2147482647;
    assigns saved_money;
    ensures saved_money == \old(saved_money) + 1000;
*/
void SendMoney(void)
{
  saved_money = saved_money + 1000;
  /*@ assert saved_money >= 0 && saved_money <= 2147483647; */
  /* unsupported stmt: print "发工资\n"; */
}