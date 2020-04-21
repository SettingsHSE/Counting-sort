#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

// Функция сортировки подсчетом
void countingSort(int *numbers, int array_size)
{
    int *tmp = new int[1000001];

    for (int i = 0; i <= 1000000; i++)
    {
        tmp[i] = 0;
    }

    for (int i = 0;  i < array_size; i++)
    {
        tmp[numbers[i]] ++;
    }

    for (int i = 1; i <= 1000000; i++)
    {
        tmp[i] += tmp[i - 1];
    }

    int *a = new int[array_size];
    for (int i = 0; i < array_size; i++)
    {
        a[i] = numbers[i];
    }

    for (int i = array_size - 1; i >= 0; i--)
    {
        numbers[tmp[a[i]] - 1] = a[i];
        tmp[a[i]] --;
    }

    delete[] a;
    delete[] tmp;
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    countingSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
