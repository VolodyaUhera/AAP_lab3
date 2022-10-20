#include <iostream>
#include <ctime>

#define n 3

using namespace std;

void title1()
{
    cout << "����������� ������ �3" << endl;
    cout << "�������� 1. �������� ���������  ���� �������� �������� C[i][j]=C[j][i]" << endl;
}


void task1()
{
    float c[n][n]{}, sum{};
    static float min = -10, max = 30.9;
    int count = 0;
    static int l = 1;
    
    srand(time(0));
    
    title1();

    //����������� ��������
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout  << "i = " << i << "j = " << j << endl;
            c[i][j] = min + (rand() % (int)(max - min + 1));
        }
    }
    
    //���� ��������
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout <<c[i][j]<< '\t';
        }
        cout << '\n';
    }

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
             int temp = c[y][x];
             //��������� �������� ������
             for (int k = x + 1; k < n; k++)
             {
                 if (temp == c[y][k])
                 {
                     count++;
                     break;
                 }
             }
             //��������� �������� ������
             for (int k = y + 1; k < n; k++)
             {
                 if (temp == c[k][x])
                 {
                     count++;
                     break;
                 }
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