/*
RUN ERROR???
WHy????
*/

#include <iostream>
using namespace std;

int main() {
   // Costruisco e riempio un array di interi presi da input
   int dimSeq;
   cin >> dimSeq;
   int *seq = new int[dimSeq]();
   for (int i = 0; i < dimSeq; i++) {
      cin >> seq[i];
   }

   // Costruisco e riempio una matrice righe X colonne
   int righe,colonne;
   cin >> righe >> colonne;
   int **matrix = new int*[righe]();
   for (int i = 0; i < righe; i++) {
      matrix[i] = new int[colonne]();
   }

   // riempio a spirare usando seq[] in sequenza
   int k = 0;
   for (int i = 0; i < (righe*colonne / 4); i++) {
      // riga superiore, da sx a dx
      for (int j = i; j < colonne; j++) {
         if (k >= dimSeq) k = 0;
         if (matrix[i][j] == 0) matrix[i][j] = seq[k++];
      }
      // colonna più dx, dall'alto verso il basso
      for (int j = i; j < righe-i; j++) {
         if (k >= dimSeq) k = 0;
         if (matrix[j][colonne-1-i] == 0) matrix[j][colonne-1-i] = seq[k++];
      }
      // riga inferiore, da dx a sx
      for (int j = colonne-1-i; j > i; j--) {
         if (k >= dimSeq) k = 0;
         if (matrix[righe-1-i][j] == 0) matrix[righe-1-i][j] = seq[k++];
      }
      // colonna più a sx, dal basso verso l'alto
      for (int j = righe-1-i; j > i; j--) {
         if (k >= dimSeq) k = 0;
         if (matrix[j][i] == 0) matrix[j][i] = seq[k++];
      }

   }

   // stampo la matrice
   for (int i = 0; i < righe; i++) {
      for(int j = 0; j < colonne; j++) {
         cout << matrix[i][j];
      }
      cout << endl;
   }

   // deleto la matrice e la sequenza usata per riempirla
   for (int i = 0; i < righe; i++) {
      delete[] matrix[i];
   }

   delete[] matrix;
   delete[] seq;
   return 0;
}