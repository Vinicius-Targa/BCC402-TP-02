// 10032 - Tug of War

/* A tug of war is to be arranged at the local office picnic. For the tug of war, the picnickers must be divided into two teams. Each person must be on one team or the other; the number of people on the two teams must not differ by more than 1; the total weight of the people on each team should be as nearly equal as possible. */

#include <iostream>
#include <climits>
using namespace std;
 
// Esta função procura todas as possíveis soluções, enquanto compara a solução atual com a melhor solução, atualizando sempre que encontra uma solução melhor.
void splitWeights(int* arr, int n, bool* curr_elements, int selected_elements, bool* ans, int* min_diff, int sum, int curr_sum, int pos){
  //caso base: iterador excedeu o tamanho do vetor.
  if (pos == n)
    return;
 
  // Observa se o número de elementos restantes não é menor que o numero de elementos para formar a solução.
  if ((n / 2 - selected_elements) > (n - pos))
    return;
 
  //Casos onde o elemento atual (demarcado por 'pos') não é considerado parte da solução.
  splitWeights(arr, n, curr_elements, selected_elements, ans, min_diff, sum, curr_sum, pos + 1);
 
  // adicionar o elemento atual na solução.
  selected_elements++;
  curr_sum = curr_sum + arr[pos];
  curr_elements[pos] = true;
 
  //Observa se uma solução viável é formada.
  if (selected_elements == n/2){
    //Compara se a solução viável é melhor que a melhor solução atual.
    if (abs(sum/2 - curr_sum) < *min_diff){
      *min_diff = abs(sum/2 - curr_sum);
      for (int i = 0; i<n; i++)
          ans[i] = curr_elements[i];
    }
  }
  else{
    //Casos onde o elemento atual faz parte da solução.
    splitWeights(arr, n, curr_elements, selected_elements, ans, min_diff, sum, curr_sum, pos + 1);
  }
 
  //Remove o elemento antes de finalizar a execução da função e retornar para que a chamou.
  curr_elements[pos] = false;
}
 
// Esta função vai criar os vetores booleanos, chamar a função recursiva e imprimir os resultados.
int* tugOfWar(int *vet, int n){
  // São utilizados vetores booleanos para representar o vetor original, onde se no vetor booleano estiver TRUE, o valor representado por aquela posição pertence à um time, e se estiver FALSE, o valor pertence ao outro time
  bool* curr_elements = new bool[n];
  //vetor de booleanos para a melhor solução/ solução final
  bool* ans = new bool[n];
  int min_diff = INT_MAX, sum = 0, auxsum = 0;
  //inicializando os vetores booleanos como false, e encontrando a soma total dos elementos do vetor original
  for (int i=0; i<n; i++){
    sum += vet[i];
    curr_elements[i] = false;
    ans[i] = false;
  }
 
  // Chamada da função recursica para encontrar a a melhor divisão de grupos
  splitWeights(vet, n, curr_elements, 0, ans, &min_diff, sum, 0, 0);
 
  // somas dos grupos
  sum = 0;
  auxsum = 0;
  for (int i=0; i<n; i++){
    if (ans[i] == true)
      sum += vet[i];
    if (ans[i] == false)
      auxsum += vet[i];
  }

  //deletando vetores alocados dinamicamente
  delete [] curr_elements;
  delete [] ans;

  //preparando o vetor de retorno
  int *ret = new int[2];
  
  if(sum <= auxsum){
    ret[0] = sum;
    ret[1] = auxsum;
    return ret;
  }
  else{
    ret[1] = sum;
    ret[0] = auxsum;
    return ret;
  }
}

//aqui é feita a entrada dos dados e a chamada da função principal
int main(){
  int n, cases, *ans;
  
  cin>>cases;
  
  for(int i = 0; i < cases;i++){
    cin>>n;
    int vet[n];
    for(int j = 0; j < n; j++){
      cin>>vet[j];
    }
    
    ans = tugOfWar(vet, n);

    cout<<ans[0]<<" "<<ans[1]<<endl;

    delete[] ans;
  }
  return 0;
}