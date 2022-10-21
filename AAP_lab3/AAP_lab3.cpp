#include <iostream>
#include <ctime>
#include <chrono>


//create 2d array
#define n 6 
int c[n][n]{}; // array for task1

#define h 5
#define l 7
int a[h][l]{}; // array for task2

using namespace std;

using namespace std::chrono;

void headertask1() 
{
    printf("Лабораторна робота №3");
    printf("Завдання 1. Програма для знаходження c[i][j] = c[j][i] ");
    printf("та знайти їх кількість");
}

void GenerateElementsTask1()
{
    srand(time(0));
    static float min = -10, max = 30.9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //cout << "i = " << i << "j = " << j << endl;
            c[i][j] = (int)(min + (rand() % (int)(max - min + 1)));
        }
    }
}

void DisplayElementsTask1()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << '\t';
        }
        cout << '\n';
    }
}

void FindSameElementsAndShowIt()
{
    int count = 0;
    //Find dyblicate elements
    //get elemnts
    for (int y = 0; y < n; y++) {
        //cout << "y = " << y <<'\t'<< endl;
        for (int x = 0; x < n; x++) {
            //cout << "x = " << x <<'\n'<< endl;
            //create temp 
            int temp = c[y][x];
            //check next elements after x,y
            for (int k = 0; k < n; k++) {
                //cout << "k = " << k << '\t' << endl;
                for (int f = 0; f < n; f++) {
                    //cout << "f = " << f << '\n' << endl;
                    if (temp == c[k][f] && (x + y) != (k + f)) {
                        count++;
                        cout << "c[y][x] = " << y << ' ' << x << " c[k][f] = " << k << ' ' << f  << "\t"<< endl;
                        printf("%d  \n",  c[k][f]);
                        break;
                    }
                }
            }

        }
    }
    cout << "\n" << count << '\n';
}

void task1() {
    auto start = high_resolution_clock::now();
    headertask1();
    GenerateElementsTask1();
    DisplayElementsTask1();
    FindSameElementsAndShowIt();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "duration taken (milliseconds) = " << duration.count()/1000 << endl;
    
}

void headertask2()
{
    printf("Лабораторна робота №3");
    printf("Завдання 2. Вивести номері стовпців де всі елементи додатні");
    printf("та рядки де всі елементи відємні");
}

void GenerateElementsTask2()
{
    srand(time(0));
    static float min = -10, max = 30.9;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            //cout << "i = " << i << "j = " << j << endl;
            a[i][j] = (int)(min + (rand() % (int)(max - min + 1)));
        }
    }
}

void DisplayElementsTask2()
{
    {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                cout << a[i][j] << '\t';
            }
            cout << '\n';
        }
    }

}

void FindSameLowerZeroElementsInRows()
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (a[i][j] < 0)
            {
                count++;
                //cout << count << endl;
            }else{
                i++;
                j = 0;
                count = 0;
                
            }
            if (count == h)
            {
                sum++;
                count = 0;
            }
        }
    }
    cout << "sum = " << sum-1;
}
void FindSameHighterZeroElementsInPillar()
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (a[j][i] > 0)
            {
                count++;
                //cout << count << endl;
            }
            else {
                i++;
                j = 0;
                count = 0;

            }
            if (count == h)
            {
                sum++;
                count = 0;
            }
        }
    }
    cout << "sum = " << sum;
}


void task2()
{
    auto start = high_resolution_clock::now();
    headertask2();
    GenerateElementsTask2();
    DisplayElementsTask2();
    //FindSameLowerZeroElementsInRows();
    FindSameHighterZeroElementsInPillar();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "duration taken (milliseconds) = " << duration.count() / 1000 << endl;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    //task1();
    task2();
    

}
