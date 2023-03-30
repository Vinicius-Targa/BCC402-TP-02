#include <iostream>
#include <assert.h>

using namespace std;

int decideWinner(int n){
  //se n for igual a 1, stan já ganha de default
  if(n == 1)
    return 1;

  //Booleana que gerencia de quem é a vez, se true, é a vez do stan, se false, é a vez do ollie
  //stan começa
  bool Turn = true;

  //i começará em 1, e os jogadores vão multiplicar i em turnos, enquanto se alterna jogadores
  for(int i=1; i<n; Turn=!Turn){
    if(Turn)
      i*=9; // o valor ótimo para o stan é sempre 9
    else
      i*=2; // o valor ótimo para o ollie é sempre 2
  }
  
  if(Turn)
    return 0;
  else 
    return 1;
}

void testOne(){
  int n = 17;
  int ans = decideWinner(n);

  assert(ans == 0);
  cout<<"Test 01: OK!"<<endl;
}

void testTwo(){
  int n = 162;
  int ans = decideWinner(n);

  assert(ans == 1);
  cout<<"Test 02: OK!"<<endl;
}

void testThree(){
  int n = 34012226;
  int ans = decideWinner(n);

  assert(ans == 1);
  cout<<"Test 02: OK!"<<endl;
}

int main() {

  testOne();
  testTwo();
  testThree();
  
  return 0;
}