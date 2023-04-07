#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Algoritma Analizi ve Tasar�m� K�sa S�nav 1 2.K�s�m
// Horspool Algorithm
// Ahmet Tayyip A�z�g�zel
// 1210505008


using namespace std;

// Boyer-Moore-Horspool algoritmas� ile verilen kelime grubundan ka� tane oldu�unu bulma
int horspool_search(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    // 256 karakterli bir tablo olu�turun ve her karakterin varsay�lan de�erini, kelimenin uzunlu�u olarak ayarlay�n
    vector<int> table(256, m);
    for (int i = 0; i < m - 1; i++) {
        // Kelime grubunu tersine �evirin ve son karakter hari� her karakter i�in tabloya de�erler atay�n
        table[pattern[i]] = m - 1 - i;
    }

    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            // Kelime grubunun her karakterini kontrol edin
            k++;
        }
        if (k == m) {
            // Kelime grubu bulundu�unda, sayac� art�r�n
            count++;
        }
        i += table[text[i]];
        // Tablodan al�nan de�ere g�re kayd�rma i�lemini ger�ekle�tirin
    }
    return count;
}

int main() {
	
	cout << "Algoritma Analizi ve Tasarimi Kisa Sinav 1 2.Kisim" << endl;
	cout << "Horspool Algorithm" << endl;
	cout << "Ahmet Tayyip Agziguzel" << endl;
	cout << "1210505008" << endl;
	cout << "*************************************************************************************************" << endl;
	
	
    string filename = "alice_in_wonderland.txt"; // Dosya ad�
    string keywords[] = {"upon", "sigh", "Dormouse", "jury-box", "swim"}; // Kelime grubu
    string keyword_names[] = {"upon", "sigh", "Dormouse", "jury-box", "swim"}; // Kelime isimleri
    int count[5] = {0}; // Kelime say�s� i�in sayac

    ifstream file(filename.c_str());
    if (!file) {
        // Dosya a��lamazsa, kullan�c�ya bir hata mesaj� g�sterin
        cout << "Dosya acilamadi!" << endl;
        return 0;
    }

    string line;
    while (getline(file, line)) {
        // Her sat�r� okuyun ve her bir kelime grubu i�in horspool_search fonksiyonunu �a��r�n
        for (int i = 0; i < 5; i++) {
            count[i] += horspool_search(line, keywords[i]);
        }
    }

    // Her bir kelime grubu i�in say�lar� ekrana yazd�r�n
    for (int i = 0; i < 5; i++) {
        cout  << keyword_names[i] << " kelimesi " << count[i] << " kez geciyor." << endl;
    }

    return 0;
}

