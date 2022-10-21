#include <iostream>

#include <ctime>

#define n 3
int c[n][n]{};
using namespace std;

void GenerateElements()
{
    srand(time(0));
    static float min = -10, max = 30.9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "i = " << i << "j = " << j << endl;
            c[i][j] = (int)(min + (rand() % (int)(max - min + 1)));
        }
    }
}
void DisplayElements()
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
                        cout << "c[y][x] = " << y << ' ' << x << " c[k][f] = " << k << ' ' << f << endl;
                        break;
                    }
                }
            }

        }
    }
    cout << "\n" << count;
}

void task1() {
    GenerateElements();
    DisplayElements();
    FindSameElementsAndShowIt();

}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    task1();

}