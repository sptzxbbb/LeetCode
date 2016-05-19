// soj: 1147. 谁拿了最多奖学金
// Sat Nov 29, 2014--------Shawn Chow

#include "iostream"
#include "string"
using namespace std;

struct student {
  string name;
  int mark1;
  int mark2;
  char cadre;
  char west;
  int paper;
  int scholarship;
};

void evaluate(student* s);
  
int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  student candidate[N];
  string name;
  int mark1, mark2, paper;
  char cadre, west;
  for (int i = 0; i < N; ++i) {
    cin >> name >> mark1 >> mark2 >> cadre >> west >> paper;
    candidate[i].name = name;
    candidate[i].mark1 = mark1;
    candidate[i].mark2 = mark2;
    candidate[i].cadre = cadre;
    candidate[i].west = west;
    candidate[i].paper = paper;
    candidate[i].scholarship = 0;
    evaluate(&candidate[i]);
  }

  int ans = 0, sum = 0;
  for (int i = 0; i < N; ++i) {
    if (candidate[i].scholarship > candidate[ans].scholarship) ans = i;
    sum += candidate[i].scholarship;
  }

  cout << candidate[ans].name << endl;
  cout << candidate[ans].scholarship << endl;
  cout << sum << endl;

  return 0;
}

void evaluate(student* s) {
  if (s->mark1 > 80 && s->paper >= 1) {
    s->scholarship += 8000;
  }

  if (s->mark1 > 85 && s->mark2 > 80) {
    s->scholarship += 4000;
  }

  if (s->mark1 > 90) {
    s->scholarship += 2000;
  }

  if (s->mark1 > 85 && s->west == 'Y') {
    s->scholarship += 1000;
  }

  if (s->mark2 > 80 && s->cadre == 'Y') {
    s->scholarship += 850;
  }
}
