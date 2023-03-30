// 847 - A multiplication game

/* Stan and Ollie play the game of multiplication by multiplying an integer p by one of the numbers 2 to
9. Stan always starts with p = 1, does his multiplication, then Ollie multiplies the number, then Stan
and so on. Before a game starts, they draw an integer 1 < n < 4294967295 and the winner is who first
reaches p ≥ n. */

#include <iostream>
#include <cstdlib>

using namespace std;

//retorna o vencedor da partida, onde 1 = stan e 0 = ollie
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


int main() {

  int n, ans;

  //loop recebendo as entradas contínuas sem critério de parada.
  while(cin>>n){
    ans = decideWinner(n);

    if(ans == 1)
      cout<<"Stan wins"<<endl;
    else
      cout<<"Ollie wins"<<endl;
  }

  return 0;
}
