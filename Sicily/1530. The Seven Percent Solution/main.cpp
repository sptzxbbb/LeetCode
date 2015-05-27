// soj: 1530. The Seven Percent Solution
// Mon Dec 15, 2014--------Shawn Chow
#include "cstdio"
#include "cstring"
using namespace std;

int main(int argc, char *argv[]) {
  char s[80];
  while (fgets(s, 80, stdin), s[0] != '#') {
    for (int i = 0; i < strlen(s); ++i) {
      switch(s[i]) {
      case ' ' :
	printf("%s", "%20");
      	break;
      case '!' :
	printf("%s", "%21");
      	break;
      case '$' :
	printf("%s", "%24");
      	break;
      case '%' :
	printf("%s", "%25");
      	break;
      case '(' :
	printf("%s", "%28");
      	break;
      case ')' :
	printf("%s", "%29");
      	break;
      case '*' :
	printf("%s", "%2a");
      	break;
      default :
	printf("%c", s[i]);
      }
    }
  }
  return 0;
}

