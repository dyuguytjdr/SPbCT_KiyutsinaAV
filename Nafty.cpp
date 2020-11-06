#include <process.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include "windows.h"


using namespace std;

void fork(int i) {
    cout << "Создание процесса № " << i << "\n";
}
void execl(int i, int a) {
    cout << "Передача числа " << a << " в процесс " << i << endl;
}
void waitpid(int i) {
    cout << "Ожидание процесса № " << i << "\n";
    Sleep(200);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    char* pEnd;
    cout << "Начало программы\n\n";
    int proc = strtol(argv[1], &pEnd, 10);
    int num = strtol(argv[2], &pEnd, 10);
    for (int i = 1; i <= proc; i++) {
        fork(i);
    }
    cout << "\nПроцессы созданы\n\n";
    for (int i = 1; i <= proc; i++) {
        execl(i, num);
    }
    cout << "\nПередача чисел завершина\n\n";
    for (int i = 1; i <= proc; i++) {
        waitpid(i);
    }
    cout << "\nКонец программы\n";
}