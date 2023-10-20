#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h> 

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    ifstream fin("Shakespeare_Winter'sTale.txt", ios::binary);

 
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу!";
        return 1;
    }

  
    fin.seekg(0, ios::end);
    long len = fin.tellg();

    
    char* buf = new char[len + 1];
    fin.seekg(0, ios::beg);
    fin.read(buf, len);
    buf[len] = '\0';


    ofstream fout("question.txt");

    long n = 0, i = 0;
    while (buf[i]) {
        // Шукаємо знак питання в тексті
        if (buf[i] == '?') {
            string sentence;
            for (int j = n; j <= i; j++) {
                sentence += buf[j];
            }

          
            fout << sentence << endl;
            n = i + 1; 
        }

      
        if (buf[i] == '.' || buf[i] == '!' || buf[i] == '\n') {
            n = i + 1;
        }

        i++; 
    }


    fin.close();
    fout.close();

    cout << "Interrogative sentences are recorded in the filequestion.txt" << endl;

    return 0;
}
