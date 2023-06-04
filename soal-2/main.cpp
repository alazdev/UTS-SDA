#include <iostream>
#include <stack>
#include <cstring>  

using namespace std;

// Function bantuan
string addSeparator(int number) {
    string strNumber = to_string(number);
    string result;

    int count = 0;
    for (int i = strNumber.length() - 1; i >= 0; i--) {
        if (count != 0 && count % 3 == 0)
            result = '.' + result;
        result = strNumber[i] + result;
        count++;
    }

    return result;
}

int main()
{
    char pesanan[100];
    stack<string> stackPesanan;
    int totalHarga = 0;
    
    string menu[5] = {"Soto","Rawon","Pecel","Bakso","Siomay"};
    int hargaMenu[5] = {15000,20000,10000,12500,25000};
    int sizeMenu = sizeof(menu) / sizeof(menu[0]);
    
    // Menampilkan semua menu makanan
    cout << "Menu makanan :" << endl;
    for (int i = 0; i < sizeMenu; i++) {
        cout << "   - " + menu[i] + " : " + addSeparator(hargaMenu[i]) << endl;
    }
    cout << "===============" << endl;
    
    // Proses input pesanan pelanggan
    cout << "Isikan Makanan yang dipesan : ";
    cin.getline(pesanan, 100);
    cout << "===============" << endl;
    
    char *ptr;
    ptr = strtok(pesanan, " , ");
    while (ptr != NULL)  
    {
        stackPesanan.push(ptr);
        ptr = strtok(NULL, " , ");  
    }
    if (stackPesanan.size() % 2 != 0) {
        cout << "===== Format pesanan yang Anda masukkan salah =====";
        return 0;
    }
    
    int sizePesanan = stackPesanan.size()/2;
    
    string menuPesanan[sizePesanan];
    int hargaPesanan[sizePesanan];
    int jumlahPesanan[sizePesanan];
    
    int intJumlah = sizePesanan -1;
    int intMenu = sizePesanan -1;
    bool menuDitemukan;
    while (!stackPesanan.empty()) {
        if (stackPesanan.size() % 2 == 0) {
            try {
                if (stoi(stackPesanan.top()) > 0) {
                    jumlahPesanan[intJumlah] = stoi(stackPesanan.top());
                    --intJumlah;
                }
            } catch (exception& e) {
                cout << "===== Format pesanan yang Anda masukkan salah =====";
                return 0;
            }
        } else {
            menuDitemukan = false;
            for (int j = 0; j < sizeMenu; j++) {
                if (menu[j] == stackPesanan.top()) {
                    menuDitemukan = true;
                    menuPesanan[intMenu] = menu[j];
                    hargaPesanan[intMenu] = hargaMenu[j];
                    --intMenu;
                }
            }
            if (!menuDitemukan) {
                cout << "===== Salah satu menu pesanan yang Anda masukkan tidak ditemukan =====";
                return 0;
            }
        }
        stackPesanan.pop();
    }
    
    // Menampilkan semua pesanan pelanggan
    cout << "Total Harga :" << endl;
    for (int i = 0; i < sizePesanan; i++) {
        cout << "   - " + menuPesanan[i] + " @" + addSeparator(hargaPesanan[i]) + " * " + addSeparator(jumlahPesanan[i]) + " = " + addSeparator(hargaPesanan[i] * jumlahPesanan[i]) << endl;
        totalHarga += hargaPesanan[i] * jumlahPesanan[i];
    }
    cout << "Total = " + addSeparator(totalHarga) << endl;
    cout << "===============" << endl;
    return 0;
}
