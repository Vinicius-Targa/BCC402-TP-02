#include <assert.h>
#include <iostream>

using namespace std;

// retorna o fatorial de n
int fat(int n) {
  if (n == 0 || n == 1)
    return 1;
  return n * fat(n - 1);
}

// conta quantas combinações de labeling de nodos de uma árvore
int treeLabeling(int k, int d) {
  // se a profundidade for 1, retorna o a permutação dos nós filhos
  if (d == 1) {
    return fat(k);
  }

  return d * treeLabeling(k, d - 1);
}

void testOne() {
  int k = 10, d = 1, expected = 3628800;
  int ans = treeLabeling(k, d);

  assert(ans == expected);
  cout << "Test 01: OK!" << endl;
}

// entrada
int main() {
  testOne();
  return 0;
}