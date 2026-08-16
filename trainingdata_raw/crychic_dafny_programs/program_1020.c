// Generated C + ACSL

typedef struct {
    int scrollPosition;
    int pageHeight;
    int previousHeights;
} Browser;

typedef struct {
    int username;
    int password;
} Credentials;

typedef struct {
    int dummy;
} Automation;

int Login(Browser* browser, Credentials* creds);
int ScrollFeed(Browser* browser);

/*@
    assigns \nothing;
*/
void Main(void)
{
  Browser browser_obj;
  Browser* browser = &browser_obj;
  Credentials creds_obj;
  Credentials* creds = &creds_obj;
  Automation automation_obj;
  Automation* automation = &automation_obj;
  int loginSuccess = Login(browser, creds);
  /*@ assert browser->scrollPosition >= 0; */
  /*@ assert browser->pageHeight > 0; */
  if (loginSuccess)
  {
    int scrolls = ScrollFeed(browser);
    /*@ assert (scrolls >= 0); */
  }
}

/*@
    requires \valid(browser);
    requires \valid(creds);
    assigns browser->scrollPosition, browser->pageHeight;
    ensures \result == 1;
    ensures browser->scrollPosition == 0;
    ensures browser->pageHeight > 0;
*/
int Login(Browser* browser, Credentials* creds)
{
  int success = 1;
  /*@ assert success >= 0 && success <= 2147483647; */
  browser->scrollPosition = 0;
  browser->pageHeight = 100;
  return success;
}

/*@
    requires \valid(browser);
    requires browser->scrollPosition >= 0;
    requires browser->pageHeight > 0;
    assigns browser->scrollPosition, browser->pageHeight, browser->previousHeights;
    ensures \result >= 0;
    ensures browser->pageHeight >= \old(browser->pageHeight);
    ensures browser->scrollPosition <= browser->pageHeight;
*/
int ScrollFeed(Browser* browser)
{
  int scrollCount = 0;
  /*@ assert scrollCount >= 0 && scrollCount <= 2147483647; */
  int heightIncreases = 0;
  browser->previousHeights = 0;
  browser->scrollPosition = 0;
/*@
  loop invariant 0 <= heightIncreases <= 10;
  loop invariant scrollCount >= 0;
  loop invariant browser->scrollPosition >= 0;
  loop invariant browser->pageHeight > 0;
  loop invariant browser->pageHeight >= \at(browser->pageHeight, LoopEntry);
  loop invariant browser->scrollPosition <= browser->pageHeight;
  loop assigns heightIncreases, browser->previousHeights, browser->scrollPosition,
              browser->pageHeight, scrollCount;
  loop variant 10 - heightIncreases;
*/
  while ((heightIncreases < 10))
    {
      int oldHeight = browser->pageHeight;
      /*@ assert oldHeight > 0; */
      browser->previousHeights = (browser->previousHeights + 0);
      browser->scrollPosition = browser->pageHeight;
      /*@ assert browser->scrollPosition > 0; */
      int shouldIncrease = 0;
      if (shouldIncrease)
      {
        browser->pageHeight = (browser->pageHeight + 1);
        heightIncreases = (heightIncreases + 1);
      }
      /*@ assert browser->pageHeight >= oldHeight; */
      scrollCount = (scrollCount + 1);
      if ((browser->pageHeight == oldHeight))
      {
        break;;
      }
    }
  /*@ assert scrollCount >= 0; */
  return scrollCount;
}