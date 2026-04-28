#include <iostream>
using namespace std;

class LayangLayang; // forward declaration

class BelahKetupat
{
private:
    float d1, d2; // diagonal
    float sisi;

public:
    void input()
    {
        cout << "Belah Ketupat\n";
        cout << "Masukkan diagonal 1: ";
        cin >> d1;
        cout << "Masukkan diagonal 2: ";
        cin >> d2;
        cout << "Masukkan sisi: ";
        cin >> sisi;
    }

    float luas()
    {
        return 0.5 * d1 * d2;
    }

    float keliling()
    {
        return 4 * sisi;
    }

    void output()
    {
        cout << "Luas Belah Ketupat: " << luas() << endl;
        cout << "Keliling Belah Ketupat: " << keliling() << endl;
    }

    // friend function dari Layang-Layang
    friend float kelilingLayang(LayangLayang &l);
};

class LayangLayang
{
private:
    float d1, d2;
    float sisi1, sisi2;

public:
    void input()
    {
        cout << "\nLayang-Layang\n";
        cout << "Masukkan diagonal 1: ";
        cin >> d1;
        cout << "Masukkan diagonal 2: ";
        cin >> d2;
        cout << "Masukkan sisi 1: ";
        cin >> sisi1;
        cout << "Masukkan sisi 2: ";
        cin >> sisi2;
    }

    float luas()
    {
        return 0.5 * d1 * d2;
    }

    float keliling()
    {
        return 2 * (sisi1 + sisi2);
    }

    void output()
    {
        cout << "Luas Layang-Layang: " << luas() << endl;
        cout << "Keliling Layang-Layang: " << keliling() << endl;
    }

    // friend function (boleh diakses BelahKetupat)
    friend float kelilingLayang(LayangLayang &l);
};

// IMPLEMENTASI FRIEND FUNCTION
float kelilingLayang(LayangLayang &l)
{
    return 2 * (l.sisi1 + l.sisi2);
}

// MAIN
int main()
{
    LayangLayang l;
    BelahKetupat b;

    l.input();
    l.output();

    cout << "Keliling Layang-Layang (friend): " << kelilingLayang(l) << endl;

    cout << endl;

    b.input();
    b.output();

    return 0;
}
