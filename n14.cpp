/*
Letta da input una sequenza di interi terminata da -1,
controlli che
  siano tutte cifre decimali (0-9),
  calcoli il numero che si ottiene giustapponendo le cifre
  verifichi se il numero ottenuto è divisibile per 3

2 5 9 15 1 -1
  ERRORE

2 5 9 1 1 -1
  25911
  SI

2 5 9 1 -1
  2591
  NO

-1
  VUOTO
 */

 #include <iostream>
 #include <sstream>
 using namespace std;

/////////////////////////////////////////////////////////////
template<typename T>
string to_string_mine(const T& value)
 {
     ostringstream oss;
     oss << value;
     return oss.str();
 }

static int stoiMine( string s ) {
    int i;
    istringstream(s) >> i;
    return i;
}
/////////////////////////////////////////////////////////////


 bool div3 (int num) {
 	if (num % 3 == 0) {
 		return true;
 	} else {
 		return false;
 	}
 }

 int main() {
 	string numero = "";
 	int chInput;
  bool errore = false;

  cin >> chInput;

  if (chInput == -1) {
    cout << "VUOTO";
    return 0;
  }

  while (chInput != -1) {
 		if (chInput >= 0 && chInput <= 9) {
      numero += to_string_mine(chInput);
    } else {
      errore = true;
    }
 		cin >> chInput;
 	}

  if (errore) {
    cout << "ERRORE";
    return 0;
  }

  cout << numero << endl;
 	int num = stoiMine(numero);

 	if (div3(num)) {
 		cout << "SI";
 	} else {
 		cout << "NO";
 	}

 	return 0;
 }
