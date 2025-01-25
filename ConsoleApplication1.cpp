// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <ctime>
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int num_list[25] = { 0 };
    for (int i = 0; i < 25; i++)  num_list[i] = i;
    
    for (int i = 0; i < 25; i++)
    {
        int r = rand() % 25,temp;
        temp = num_list[i];
        num_list[i] = num_list[r];
        num_list[r] = temp;
    }
    bool num_b[25] = { false };
    int count = 0;
    int scroc = 0;
    while (true)
    {
        system("cls"); // 清除畫面
        cout << string(6, '=') << "賓果遊戲" << string(6, '=') << endl;
        for (int i = 0; i < 25; i++)
        {
            if (num_b[num_list[i]] && num_list[i] != 0)
                 cout << "\033[31m" <<setw(2)<< num_list[i] << "\033[0m" << " |";
            
            else
            {
                if (num_list[i] == 0)
                {
                    num_b[num_list[i]] = true;
                    cout<<   "\033[33m" << setw(2) << " * "<< "\033[0m" <<"|";
                }
                else
                 cout << setw(2) << " ? |";
            }
            if ((i + 1) % 5 == 0)
            {
                cout << endl;
                cout << string(20, '-') << endl;;
            }

        }
        cout << string(6, '=')<<"第"<<count << "回和;達成 " << scroc << " 條線" << endl;
        cout << "請輸入(1~24):";
        int n;
        while (true)
        {
            cin >> n;
            if (num_b[n] || n<1 ||n>24)
                cout << "輸入錯誤" << endl;
            else
            {
                num_b[n] = true;
                break;
            }
        }
        count++;



        scroc = 0;
        if (num_b[num_list[0]] && num_b[num_list[6] ]&& num_b[num_list[12]] && num_b[num_list[18]] && num_b[num_list[24]])
        {
            scroc++;
        }
        if (num_b[num_list[4]] && num_b[num_list[8]] && num_b[num_list[12]] && num_b[num_list[16]] && num_b[num_list[20]])
        {
            scroc++;
        }
        for (int i = 0; i < 5; i++)
        {
            if (num_b[num_list[0 + i * 5]] && num_b[num_list[1 + i * 5]] && num_b[num_list[2 + i * 5]] && num_b[num_list[3 + i * 5]] && num_b[num_list[4 + i * 5]])
            {
                scroc++;
               
            }
            if (num_b[num_list[0 + i]] && num_b[num_list[5 + i]] && num_b[num_list[10 + i ]] && num_b[num_list[15 + i ]] && num_b[num_list[20 + i ]] )
            {
                scroc++;
               
            }
        }   
        /*
         0  1  2  3  4 
         5  6  7  8  9 
        10 11 12 13 14
        15 16 17 18 19
        20 21 22 23 24
        */
        if (scroc == 5)
        {
            cout << string(6, '=') << "bingo??達成5條線;你總共玩了" << count << "回合" << string(6, '=') << endl;
            break;
        }
    }










}

