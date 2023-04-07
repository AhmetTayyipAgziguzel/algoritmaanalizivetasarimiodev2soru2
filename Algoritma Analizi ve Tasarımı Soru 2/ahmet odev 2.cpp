#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Algoritma Analizi ve Tasarýmý Kýsa Sýnav 1 2.Kýsým
// Horspool Algorithm
// Ahmet Tayyip Aðzýgüzel
// 1210505008


using namespace std;

// Boyer-Moore-Horspool algoritmasý ile verilen kelime grubundan kaç tane olduðunu bulma
int horspool_search(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int count = 0;

    // 256 karakterli bir tablo oluþturun ve her karakterin varsayýlan deðerini, kelimenin uzunluðu olarak ayarlayýn
    vector<int> table(256, m);
    for (int i = 0; i < m - 1; i++) {
        // Kelime grubunu tersine çevirin ve son karakter hariç her karakter için tabloya deðerler atayýn
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
            // Kelime grubu bulunduðunda, sayacý artýrýn
            count++;
        }
        i += table[text[i]];
        // Tablodan alýnan deðere göre kaydýrma iþlemini gerçekleþtirin
    }
    return count;
}

int main() {
	
	cout << "Algoritma Analizi ve Tasarimi Kisa Sinav 1 2.Kisim" << endl;
	cout << "Horspool Algorithm" << endl;
	cout << "Ahmet Tayyip Agziguzel" << endl;
	cout << "1210505008" << endl;
	cout << "*************************************************************************************************" << endl;
	
	
    string filename = "alice_in_wonderland.txt"; // Dosya adý
    string keywords[] = {"upon", "sigh", "Dormouse", "jury-box", "swim"}; // Kelime grubu
    string keyword_names[] = {"upon", "sigh", "Dormouse", "jury-box", "swim"}; // Kelime isimleri
    int count[5] = {0}; // Kelime sayýsý için sayac

    ifstream file(filename.c_str());
    if (!file) {
        // Dosya açýlamazsa, kullanýcýya bir hata mesajý gösterin
        cout << "Dosya acilamadi!" << endl;
        return 0;
    }

    string line;
    while (getline(file, line)) {
        // Her satýrý okuyun ve her bir kelime grubu için horspool_search fonksiyonunu çaðýrýn
        for (int i = 0; i < 5; i++) {
            count[i] += horspool_search(line, keywords[i]);
        }
    }

    // Her bir kelime grubu için sayýlarý ekrana yazdýrýn
    for (int i = 0; i < 5; i++) {
        cout  << keyword_names[i] << " kelimesi " << count[i] << " kez geciyor." << endl;
    }

    return 0;
}

