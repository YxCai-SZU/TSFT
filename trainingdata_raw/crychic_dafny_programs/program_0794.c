// Generated C + ACSL

#include <stddef.h>

#define MAX_PATTERNS 100

typedef struct {
  int patterns[MAX_PATTERNS];
  int views[MAX_PATTERNS];
  int len;
} UrlPatterns;

UrlPatterns urlPatterns = {.len = 0};
int urlPatterns_len = 0;
int* urlPatterns_patterns = urlPatterns.patterns;
int* urlPatterns_views = urlPatterns.views;

enum Pattern {
  Register,
  Channel,
  Login,
  Logout,
  PasswordReset,
  PasswordResetDone,
  PasswordResetComplete
};

/*@
    requires view != 0;
    requires 0 <= urlPatterns.len <= MAX_PATTERNS;
    assigns urlPatterns.patterns[urlPatterns.len], 
            urlPatterns.views[urlPatterns.len],
            urlPatterns.len,
            urlPatterns_len;
    ensures urlPatterns.len == \old(urlPatterns.len) || 
            urlPatterns.len == \old(urlPatterns.len) + 1;
    ensures urlPatterns.len <= MAX_PATTERNS;
*/
void RegisterPattern(int pattern, int view)
{
  if (urlPatterns.len < MAX_PATTERNS) {
    urlPatterns.patterns[urlPatterns.len] = pattern;
    urlPatterns.views[urlPatterns.len] = view;
    urlPatterns.len++;
    urlPatterns_len = urlPatterns.len;
  }
}

/*@
    requires 0 <= urlPatterns.len <= MAX_PATTERNS;
    requires urlPatterns_len == urlPatterns.len;
    requires urlPatterns_patterns == urlPatterns.patterns;
    requires urlPatterns_views == urlPatterns.views;
    assigns \nothing;
    ensures (\exists integer i; 0 <= i < urlPatterns_len && urlPatterns_patterns[i] == pattern) ==>
            (\exists integer j; 0 <= j < urlPatterns_len && urlPatterns_patterns[j] == pattern && \result == urlPatterns_views[j]);
    ensures (\forall integer i; 0 <= i < urlPatterns_len ==> urlPatterns_patterns[i] != pattern) ==>
            \result == 0;
*/
int ResolveUrl(int pattern)
{
  /*@
    loop invariant 0 <= i <= urlPatterns.len;
    loop invariant \forall integer k; 0 <= k < i ==> urlPatterns.patterns[k] != pattern;
    loop assigns i;
    loop variant urlPatterns.len - i;
  */
  for (int i = 0; i < urlPatterns.len; i++)
  {
    if (urlPatterns.patterns[i] == pattern)
    {
      //@ assert urlPatterns.patterns[i] == pattern;
      //@ assert 0 <= i < urlPatterns.len;
      return urlPatterns.views[i];
    }
    //@ assert urlPatterns.patterns[i] != pattern;
  }
  //@ assert \forall integer k; 0 <= k < urlPatterns.len ==> urlPatterns.patterns[k] != pattern;
  return 0;
}

/*@
    requires urlPatterns.len == 0;
    assigns urlPatterns.patterns[0..6], 
            urlPatterns.views[0..6],
            urlPatterns.len,
            urlPatterns_len;
    ensures urlPatterns.len <= 7;
*/
void InitializePatterns(void)
{
  int registerView = 1;
  int channelView = 2;
  int loginView = 3;
  int logoutView = 4;
  int passwordResetView = 5;
  int passwordResetDoneView = 6;
  int passwordResetConfirmView = 7;
  int passwordResetCompleteView = 8;
  RegisterPattern(Register, registerView);;
  RegisterPattern(Channel, channelView);;
  RegisterPattern(Login, loginView);;
  RegisterPattern(Logout, logoutView);;
  RegisterPattern(PasswordReset, passwordResetView);;
  RegisterPattern(PasswordResetDone, passwordResetDoneView);;
  RegisterPattern(PasswordResetComplete, passwordResetCompleteView);;
}