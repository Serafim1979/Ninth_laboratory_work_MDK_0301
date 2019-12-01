#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::max;

void get_index(int arr[], int N, int rez[], int n, bool flag)
{
    int min1, min2, max1, max2, buff;
    min1 = min2 = max1 = max2 = arr[0];

    if(flag == true)
    {
        if(abs(arr[0]) < abs(arr[1]))
        {
            min1 = 0;
            min2 = 1;
        }
        else
        {
            min1 = 1;
            min2 = 0;
        }
        for(int i = 2; i < N; i++)
        {
            if(abs(arr[i]) < abs(arr[min1]))
            {
                buff = min1;
                min1 = i;
                if(abs(arr[buff]) < abs(arr[min2]))
                    min2 = buff;
            }
            else{
                if(abs(arr[i]) < abs(arr[min2]))
                    min2 = i;
            }
        }
        rez[0] = min1;
        rez[1] = min2;
    }
    if(flag == false)
    {
        if(abs(arr[0]) < abs(arr[1]))
        {
            max1 = 0;
            max2 = 1;
        }
        else
        {
            max1 = 1;
            max2 = 0;
        }
        for(int i = 2; i < N; i++)
        {
            if(abs(arr[i]) > abs(arr[max1]))
            {
                buff = max1;
                max1 = i;
                if(abs(arr[buff]) > abs(arr[max2]))
                    max2 = buff;
            }
            else{
                if(abs(arr[i]) > abs(arr[max2]))
                    max2 = i;
            }
        }
        rez[0] = max2;
        rez[1] = max1;
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if(!fin)
    {
        cout << "File not opened!";
        return 1;
    }

    const int N = 10;
    bool flag = false;
    int arr[N];
    int rez[2];

    for(int i = 0; i < N; i++)
    {
        fin >> arr[i];
    }
    cout << endl;
    for(int j = 0; j < N; j++)
    {
        fout << arr[j] << ' ';
    }

    get_index(arr, N, rez, 2, flag);

    if(flag)
    {
        cout << "Search indexes min value in the module: ";
        cout << rez[0] << " and " << rez[1] << endl;
    }
    else
    {
        cout << "Search indexes max value in the module: ";
        cout << rez[0] << " and " << rez[1] << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

