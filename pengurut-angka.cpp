/* * * * * * * * * * * * * * * * * * * * * * * *
 * Nama program         : Pengurut Angka       *
 * Pembuat              : Putu Ardi Dharmayasa *
 * Dibuat pada          : 14 Desember 2018     *
 * Terakhir diubah pada : 14 Desember 2018     *
 * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

using namespace std;


/* * * * * * * * * * *
 *   Fungsi Buatan   *
 * * * * * * * * * * */
void tampilkan_array(int arr[], int jumlahArr)
{
    for (int i = 0; i < jumlahArr; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void tukar_nilai_variabel(int* variabel1, int* variabel2)
{
    int variabelSementara = *variabel1;
    *variabel1 = *variabel2;
    *variabel2 = variabelSementara;
}


void urut_dari_kecil_ke_besar(int kumpulanAngka[], int jumlahAngka)
{
    for (int i = 0; i < jumlahAngka; ++i)
    {
        for (int j = i+1; j < jumlahAngka; ++j)
        {
            // Jika angka setelahnya lebih kecil dari angka saat ini
            if (kumpulanAngka[j] < kumpulanAngka[i])
            {
                // tukar posisi angka
                tukar_nilai_variabel(&kumpulanAngka[i], &kumpulanAngka[j]);
            }
        }
    }
}


void urut_dari_besar_ke_kecil(int kumpulanAngka[], int jumlahAngka)
{
    for(int i = 0; i < jumlahAngka; ++i)
    {
        for (int j = i+1; j < jumlahAngka; ++j)
        {
            // Jika angka setelahnya lebih besar dari angka saat ini
            if (kumpulanAngka[j] > kumpulanAngka[i])
            {
                // tukar posisi angka
                tukar_nilai_variabel(&kumpulanAngka[i], &kumpulanAngka[j]);
            }
        }
    }
}



/* * * * * * *
 *   Kelas   *
 * * * * * * */
class PengurutAngka
{
    private:
        int mode;

    public:
        // Mode pengurut angka
        // - 1: mengurutkan angka dari yang terkecil ke terbesar
        // - 2: mengurutkan angka dari yang terbesar ke terkecil
        void aturMode(int mode)
        {
            this->mode = mode;
        }

        void urut(int kumpulanAngka[], int jumlahAngka)
        {
            if (this->mode == 1)
            {
                urut_dari_kecil_ke_besar(kumpulanAngka, jumlahAngka);
            }
            else if (this->mode == 2)
            {
                urut_dari_besar_ke_kecil(kumpulanAngka, jumlahAngka);
            }
        }
};



/* * * * * * * * * * *
 *   Fungsi Utama    *
 * * * * * * * * * * */
int main()
{
    cout << "======================================================================" << endl;
    cout << "|                       Program Pengurut Angka                       |" << endl;
    cout << "======================================================================" << endl;
    int jumlahAngka = 0;
    cout << "Masukkan jumlah angka yang akan diurutkan: "; cin >> jumlahAngka;

    int kumpulanAngka[jumlahAngka] = {};
    for (int i = 0; i < jumlahAngka; ++i)
    {
        cout << "Masukkan angka ke-" << i+1 << ": "; cin >> kumpulanAngka[i];
    }
    cout << endl;

    cout << "Angka sebelum diurutkan: " << endl;
    tampilkan_array(kumpulanAngka, jumlahAngka);

    PengurutAngka pengurutSatu;
    pengurutSatu.aturMode(1);
    pengurutSatu.urut(kumpulanAngka, jumlahAngka);
    cout << "Angka setelah diurutkan dari yang terkecil ke terbesar: " << endl;
    tampilkan_array(kumpulanAngka, jumlahAngka);

    PengurutAngka pengurutDua;
    pengurutDua.aturMode(2);
    pengurutDua.urut(kumpulanAngka, jumlahAngka);
    cout << "Angka setelah diurutkan dari yang terbesar ke terkecil: " << endl;
    tampilkan_array(kumpulanAngka, jumlahAngka);

    return 0;
}

// Catatan
// - Sudah termasuk materi array, fungsi, pointer, oop
// - Struct fungsinya sama kayak Class, sama-sama bisa dipakai untuk oop, jadi tidak saya pakai
