#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;
struct Figure {
    string name;
    int bal1 = 0;
    int bal2 = 0;
    int Sum = 0;
};

int main() {
    int n;
    int k1, k2;
    cout << "n = "; cin >> n;
    FILE* f1 = fopen(R"(C:\Users\Xiaomi\CLionProjects\Binfiles\far.dt)", "wb");
    Figure* a = new Figure[n];
    if (f1) {
        cout << "Введите фигуристов и баллы: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].name >> a[i].bal1 >> a[i].bal2;
            fwrite(&a[i], sizeof(Figure), 1, f1);
        }
    }
    fclose(f1);
    cout << "Введите коэффициент 1: "; cin >> k1;
    cout << "Введите коэффициент 2: "; cin >> k2;
    f1 = fopen(R"(C:\Users\Xiaomi\CLionProjects\Binfiles\far.dt)", "rb+");
    if (f1){
            fread(a, sizeof(Figure), n, f1);
    }
    for (int i = 0; i < n; i++) {
        a[i].Sum = (a[i].bal1 * k1) + (a[i].bal2 * k2);
    }
    fseek(f1,0,SEEK_SET);
    fwrite(a, sizeof(Figure),n,f1);
    fseek(f1,0,SEEK_SET);
    if (f1) {
        fread(a, sizeof(Figure), n, f1);
    }
    fclose(f1);
    Figure Max;
    for (int i = 0; i < n; ++i) {
        if (a[i].Sum > Max.Sum){
            Max.Sum = a[i].Sum;
            Max.name = a[i].name;
            Max.bal1 = a[i].bal1;
            Max.bal2 = a[i].bal2;
        }
    }
    f1 = fopen(R"(C:\Users\Xiaomi\CLionProjects\Binfiles\file.dt)", "wb+");
    fwrite(&Max, sizeof(Figure),1,f1);
    fseek(f1,0,SEEK_SET);
    fread(&Max, sizeof(Figure),1,f1);
    for (int i = 0; i < n; ++i) {
        cout << a[i].name << " " << a[i].bal1 << " " << a[i].bal2 << " " << a[i].Sum << endl;
    }
    cout << "Лучшая: " << Max.name << " " << Max.bal1 << " " << Max.bal2 << " " << Max.Sum << endl;
    delete[]a;
    fclose(f1);
    return 0;
}