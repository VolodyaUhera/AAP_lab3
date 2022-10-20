#include <iostream>
#include <ctime>

#define n 6

using namespace std;

void title1()
{
    cout << "Лабораторна робота №3" << endl;
    cout << "Завдання 1. Програма обрахунку  суми кулькості елементів C[i][j]=C[j][i]" << endl;
}


void task1()
{
    float c[n][n]{};
    static float min = -10, max = 30.9;
    int count = 0;
    static int l = 1;
    
    srand(time(0));
    
    title1();

    //генерування елементів
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = min + (rand() % (int)(max - min + 1));
        }
    }
    
    //вивід елементів
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            cout << c[i][j];
            cout << "\t";
        }
        cout << '\n' << endl;
    }
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            
            if (*c[i] =*c[j])
            {
                cout << "i = " << i << "j = " << j;
                cout << "\n";
                cout << "c[i][j] = " << c[i][j] << "c[j][i] = " << c[j][i] << endl;
                cout << "\n";
                count++;
            }
        }
    }
    
    cout << "\n" << count ;
}

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    task1();

}