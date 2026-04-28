#include <iostream>
#include <string>
using namespace std;

class siswa; // forward declaration

class orang
{
private:
    string nama;

public:
    void setNama(string pNama);
    friend class siswa; // siswa boleh akses private orang
};

class siswa
{
private:
    int id;

public:
    void setId(int pId);
    void displayAll(orang &a); // diperbaiki (nama harus sama)
};

// IMPLEMENTASI

void orang::setNama(string pNama)
{
    nama = pNama;
}

void siswa::setId(int pId)
{
    id = pId;
}

void siswa::displayAll(orang &a)
{
    cout << "ID: " << id << endl;
    cout << "Nama: " << a.nama << endl; // akses private karena friend
}

// MAIN
int main()
{
    orang joko;
    joko.setNama("Joko Susilo");

    siswa joko_siswa;
    joko_siswa.setId(1);

    joko_siswa.displayAll(joko);

    return 0;
}