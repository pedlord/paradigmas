/*autor: Pedro Inacio de Carvalho Junior
Esse programa calcula o custo minimo entre a matriz na posição 0,0 e 6,6
e também mostra o caminho percorrido entre eles
*/

#include <iostream>
#include<limits.h>

using namespace std;
int m[7][7] = { { 4, 7, 5, 0, 3, 8,13},
                { 3, 5, 2, 1, 6, 1, 4},
                { 1, 3, 9,11, 9, 2, 3},
                {17, 3, 8, 4, 1, 8,14},
                { 2, 0, 9, 5,11, 0, 4},
                { 6, 4, 0, 2, 1,10, 3},
                {7, 13, 2, 0, 7, 1, 2} };

void imprimirCami(int i, int j, pair<int,int> cami[7][7], int mati[7][7])
{
  if (!i && !j) {
    /*cout << mati[i][j] << ' ';
    cout << cami[i][j].first << ' ' << cami[i][j].second << ' ';*/
    cout << "Caminho Percorrido:\n";
    return;
  }
  imprimirCami(cami[i][j].first, cami[i][j].second, cami, mati);
  /*cout << mati[i][j] << ' ';*/
  cout << cami[i][j].first << ' ' << cami[i][j].second << ' ';
  cout << "\n";
}

int cam_min_custo(int mat[7][7], int sup, int esq, int inf, int dir)
{
    int i, j;
    int tc[7][7]; 
    
    tc[0][0] = mat[0][0];
    pair<int,int> caminho[7][7];
 
    for (i = 1; i <= inf; i++){
        tc[i][0] = tc[i - 1][0] + mat[i][0];
        caminho[i][0] = make_pair(i - 1, 0);
    }
    for (j = 1; j <= dir; j++){
        tc[0][j] = tc[0][j - 1] + mat[0][j];
        caminho[0][j] = make_pair(0, j - 1);
    }
    for (i = 1; i <= inf; i++){
        for (j = 1; j <= dir; j++){
            if (tc[i - 1][j] < tc[i][j - 1]) {
                tc[i][j] =  tc[i - 1][j] + mat[i][j];
                caminho[i][j] = make_pair(i - 1, j);
            } else {
                tc[i][j] =  tc[i][j - 1] + mat[i][j];
                caminho[i][j] = make_pair(i, j - 1);
            }
        }
    }
    imprimirCami(6,6, caminho, tc);
    cout << "6 6";
    cout << "\nCusto do Caminho: ";
    return tc[inf][dir];
}

int main ()
{
    int menor_cam;
    menor_cam = cam_min_custo(m,2,2,6,6);
    // ou menor_cam = cam_min_custo(m,3,3,6,6) etc. para testar submatrizes
    cout<< menor_cam << endl;
}
