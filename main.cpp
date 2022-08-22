//Juan Eduardo Aran Flores - A01284238
#include <iostream>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

void merge(int *array, int l, int m, int r) {
  int i, j; //Iteradores
  int k, nIzq, nDer; 
  
  nIzq = m - l + 1; //Temaño de los vectores
  nDer = r - m; 
  
  int izqArr[nIzq], derArr[nDer]; //Creacion del vector izquierdo y derecho
  
  for(i = 0; i < nIzq; i++){ //Llenado de los dos vectores
    izqArr[i] = array[l+i];
  }
  for(j = 0; j < nDer; j++){
    derArr[j] = array[m + 1 + j];
  }
  
  i = 0; j = 0; //Reinicio de Iteradores
  k = l;
  
  while(i < nIzq && j < nDer) { //Creacion del vector final
    if(izqArr[i] <= derArr[j]) {
      array[k] = izqArr[i];
      i++;
    }else{
      array[k] = derArr[j];
      j++;
    }
    k++;
  }
  
  while(i < nIzq) {
    array[k] = izqArr[i];
    i++; k++;
  }
  while(j < nDer) {
    array[k] = derArr[j];
    j++; k++;
  }
}

void mergeSort(int *array, int l, int r) {
  int med;
  if(l < r) {
    med = l+(r-l)/2;
    
    mergeSort(array, l, med); //Acomodo del los 2 nuevos vectores creados
    mergeSort(array, med + 1, r);
    merge(array, l, med, r);
  }
}

int main() {
  ifstream entrada;
  ofstream salida;
  int n;
  string nom;

  cout << "Nombre del archivo a leer: ";
  cin >> nom;
  
  entrada.open(nom + ".txt"); //Abrimos el txt dado
  
  entrada >> n;  
  int arr[n]; //Vector con los numeros dados

  for (int i = 0; i < n; i++){
    entrada >> arr[i];
  }

  mergeSort(arr, 0, n-1);
  
  salida.open (nom + ".out.txt");
  
  for(int i = 0; i < n; i++){
    salida << arr[i] << endl;
  }

  salida.close();
}
