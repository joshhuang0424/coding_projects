#include "Snake.h"
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;
// Add anything else you need

Snake::Snake(queue<tuple<int, int>> startPosition)
{
    while(startPosition.size()){
        position.push(startPosition.front());
        startPosition.pop();
    }
    current_direction = 0;
}

queue<tuple<int, int>> Snake::nextPosition(vector<vector<int>> map)
{

    for(int i = 0; i < map.size();i++)
    {
        for(int j = 0; j < map.size();j++)
        {
            if (map[i][j] == 1)
            {
                food_x = i;
                food_y = j;
            }
        }
    }
    for(int i = 0;i < position.size();i++)
    {
        map[get<0>(position.front())][get<1>(position.front())] = -1;
        position.push(position.front());
        position.pop();
    }
    go(map);
    if((get<0>(position.back()) != food_x)||(get<1>(position.back()) != food_y)) position.pop();
    return position;
}

// Add anything else you need

void Snake::go(vector<vector<int>> map)
{
    if (current_direction == 0)//現在往下
    {
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) > food_y))//左下or下
        {
            if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                position.push(temp);
                current_direction = 0;
                break;
            }
            else
            {
                if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                {
                    tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                    position.push(temp);
                    current_direction = 3;
                    position.pop();
                }
                else
                {
                    if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                    {
                        tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 1;
                        position.pop();
                    }
                }

            }
        }
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) > food_x)&&(get<1>(position.back()) == food_y)) //左上or左
        {
            if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
            {
                tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 3;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                    position.push(temp);
                    current_direction = 0;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                    {
                        tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 1;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) < food_x)&&(get<1>(position.back()) == food_y)) //右下or右
        {
            if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
            {
                tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 1;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                    position.push(temp);
                    current_direction = 0;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                    {
                        tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 3;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) < food_y)) //右上or上
        {
            if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
            {
                tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 1;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                    position.push(temp);
                    current_direction = 0;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                    {
                        tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 3;
                        break;
                    }
                }
            }
        }
    }
//==========================================================================================================
    if (current_direction == 1)//現在往右
    {
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) > food_y))//左下or下
        {
            if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                position.push(temp);
                current_direction = 0;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                    position.push(temp);
                    current_direction = 2;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                    {
                        tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 1;
                        break;
                    }
                }

            }
        }
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) < food_y))//左上or上
        {
            if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                position.push(temp);
                current_direction = 2;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                    position.push(temp);
                    current_direction = 0;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                    {
                        tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 1;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) < food_x)&&(get<1>(position.back()) == food_y)) //右下or右
        {
            if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
            {
                tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 1;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                    position.push(temp);
                    current_direction = 0;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                    {
                        tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                        position.push(temp);
                        current_direction = 2;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) > food_x)&&(get<1>(position.back()) == food_y)) //右上or左
        {
            if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                position.push(temp);
                current_direction = 2;
                break;
            }
            else
            {
                if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                {
                    tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                    position.push(temp);
                    current_direction = 1;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                    {
                        tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                        position.push(temp);
                        current_direction = 0;
                        break;
                    }
                }
            }
        }
    }
//==========================================================================================================
    if (current_direction == 2)//現在往上
    {
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) > food_x)&&(get<1>(position.back()) == food_y)) //左下or左
        {
            if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
            {
                tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 3;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                    position.push(temp);
                    current_direction = 2;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                    {
                        tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 1;
                        break;
                    }
                }

            }
        }
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) < food_y)) //左上or上
        {
            if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                position.push(temp);
                current_direction = 2;
                break;
            }
            else
            {
                if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                {
                    tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                    position.push(temp);
                    current_direction = 3;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                    {
                        tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 1;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) < food_x)&&(get<1>(position.back()) == food_y)) //右下or右
        {
            if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
            {
                tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 1;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                    position.push(temp);
                    current_direction = 2;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                    {
                        tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 3;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) > food_y)) //右上or下
        {
            if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                position.push(temp);
                current_direction = 2;
                break;
            }
            else
            {
                if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
                {
                    tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
                    position.push(temp);
                    current_direction = 1;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                    {
                        tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 3;
                        break;
                    }
                }
            }
        }
    }
//==========================================================================================================
if (current_direction == 3)//現在往左
    {
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) > food_y)) //左下or下
        {
            if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                position.push(temp);
                current_direction = 0;
                break;
            }
            else
            {
                if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                {
                    tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                    position.push(temp);
                    current_direction = 3;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                    {
                        tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                        position.push(temp);
                        current_direction = 2;
                        break;
                    }
                }

            }
        }
        if(((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) > food_x)&&(get<1>(position.back()) == food_y)) //左上or左
        {
            if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
            {
                tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                position.push(temp);
                current_direction = 3;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                    position.push(temp);
                    current_direction = 2;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                    {
                        tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                        position.push(temp);
                        current_direction = 0;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y))||(get<0>(position.back()) < food_x)&&(get<1>(position.back()) == food_y)) //右下or右
        {
            if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                position.push(temp);
                current_direction = 0;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                    position.push(temp);
                    current_direction = 2;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                    {
                        tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 3;
                        break;
                    }
                }
            }
        }
        if(((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y))||(get<0>(position.back()) == food_x)&&(get<1>(position.back()) < food_y)) //右上or上
        {
            if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
            {
                tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
                position.push(temp);
                current_direction = 2;
                break;
            }
            else
            {
                if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
                {
                    tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
                    position.push(temp);
                    current_direction = 0;
                    break;
                }
                else
                {
                    if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
                    {
                        tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
                        position.push(temp);
                        current_direction = 3;
                        break;
                    }
                }
            }
        }
    }
//==========================================================================================================
}
void Snake::printSanke()
{
    int index = position.size();
    for (int i = 0; i < index;i++)
    {
        cout << position.front() << " ";
        position.push(position.front());
        position.pop();
    }
}

void loadmaps(vector<vector<int>> map[101]) {
    //    vector<vector<int>> map[101]; //maps
    fstream file;
    char buffer[150];
    string fname;
    for (int i = 1; i < 101; i++) {
        if (i < 10)
            fname = "00" + to_string(i);
        else if (i < 100)
            fname = "0" + to_string(i);
        else
            fname = to_string(i);
        file.open("./map/maps/map_" + fname, ios::in);
        if (!file) {
            cout << "no file" << endl;
        }
        else {
            do {
                vector<int> tempv;
                file.getline(buffer, sizeof(buffer));
                const char* d = " "; //���Ψ̾�
                char *row; //�x�s�C�����ε��G
                row = strtok(buffer, d);
                while (row) {
                    string s = row;
                    int temp = stoi(s);
                    tempv.push_back(temp);
                    row = strtok(NULL, d);
                }
                map[i].push_back(tempv);
            } while (!file.eof());
        }
        file.close();
    }
}

//(�Ҧ��a��,�U�@�i�a��,�D����m)
vector<vector<int>> generate_map(vector<vector<int>> map[101], int mapindex, queue<tuple<int, int>> snack) {
    tuple<int, int> position;
    int row, col;
    int flag3 = 0;
    int flag5 = 0;
    int flag7 = 0;
    int flagall = 0;

    //�M��a�ϱo���I��m
    for (int m = 0; m < 50; m++) {
        for (int n = 0; n < 50; n++) {
            if (map[mapindex][m][n] == 1) {
                row = m;
                col = n;
                position = make_tuple(m, n);
            }
        }
    }

    //�P�_�o���I���S���b�D���W
    int flag = 0;
    queue<tuple<int, int>> tempsnack = snack;
    while (!tempsnack.empty() && flag == 0) {
        if (tempsnack.front() == position) {
            flag = 1;
        }
        tempsnack.pop();
    }
    if (flag == 0)
        return map[mapindex];
    else {
        //      3*3��s�o���I
        for (int i = row - 1; i < row + 2; i++) {
            if (i > 0 && i < 49 && flag3 == 0) {
                for (int j = col - 1; j < col + 2; j++) {
                    if (j > 0 && j < 49 && flag3 == 0) {
                        tempsnack = snack;
                        flag = 0;
                        position = make_tuple(i, j);
                        //�C�@���I��D����m����A�����
                        while (!tempsnack.empty() && flag == 0) {
                            if (tempsnack.front() == position) {
                                flag = 1;
                            }
                            tempsnack.pop();
                        }
                        if (flag == 0) {
                            flag3 = 1;//�b3*3�����i�H���I���a��
                            row = i;//�s�Iindex
                            col = j;
                            break;
                        }
                    }
                    if (flag3 == 1)
                        break;
                }
            }
            if (flag3 == 1) {
                break;
            }
        }
        if (flag3 == 1) {  //3*3���
            vector<vector<int>> newmap;
            for (int i = 0; i < 50; i++) {
                vector<int> tempv;
                for (int j = 0; j < 50; j++) {
                    if (i == 0 || i == 49) {
                        tempv.push_back(-1);
                    }
                    else {
                        if (i == row && j == col) {
                            tempv.push_back(1);
                        }
                        else if (j == 0 || j == 49)
                            tempv.push_back(-1);
                        else
                            tempv.push_back(0);
                    }
                }
                newmap.push_back(tempv);
            }
            return newmap;
        }
        else if (flag3 == 0 && flag5 == 0) { //5*5��o���I
            for (int i = row - 2; i < row + 3; i++) {
                if (i > 0 && i < 49 && flag5 == 0) {
                    for (int j = col - 2; j < col + 3; j++) {
                        if (j > 0 && j < 49 && flag5 == 0) {
                            tempsnack = snack;
                            flag = 0;
                            position = make_tuple(i, j);
                            //�C�@���I��D����m����A�����
                            while (!tempsnack.empty() && flag == 0) {
                                if (tempsnack.front() == position) {
                                    flag = 1;
                                }
                                tempsnack.pop();
                            }
                            if (flag == 0) {
                                flag5 = 1;//�b5*5�����i�H���I���a��
                                row = i;
                                col = j;
                                break;
                            }
                        }
                        if (flag5 == 1)
                            break;
                    }
                }
                if (flag5 == 1) {
                    break;
                }
            }
        }
        if (flag5 == 1) {  //5*5���
            vector<vector<int>> newmap;
            for (int i = 0; i < 50; i++) {
                vector<int> tempv;
                for (int j = 0; j < 50; j++) {
                    if (i == 0 || i == 49) {
                        tempv.push_back(-1);
                    }
                    else {
                        if (i == row && j == col) {
                            tempv.push_back(1);
                        }
                        else if (j == 0 || j == 49)
                            tempv.push_back(-1);
                        else
                            tempv.push_back(0);
                    }
                }
                newmap.push_back(tempv);
            }
            return newmap;
        }
        else if (flag3 == 0 && flag5 == 0 && flagall == 0) {
            for (int i = 0; i < 50; i++) {
                if (i > 0 && i < 49 && flagall == 0) {
                    for (int j = 0; j < 50; j++) {
                        if (j > 0 && j < 49 && flagall == 0) {
                            tempsnack = snack;
                            flag = 0;
                            position = make_tuple(i, j);
                            //�C�@���I��D����m����A�����
                            while (!tempsnack.empty() && flag == 0) {
                                if (tempsnack.front() == position) {
                                    flag = 1;
                                }
                                tempsnack.pop();
                            }
                            if (flag == 0) {
                                flag5 = 1;//�b5*5�����i�H���I���a��
                                row = i;
                                col = j;
                                break;
                            }
                        }
                        if (flagall == 1)
                            break;
                    }
                }
                if (flagall == 1) {
                    break;
                }
            }
        }
        if (flagall == 1) {
            vector<vector<int>> newmap;
            for (int i = 0; i < 50; i++) {
                vector<int> tempv;
                for (int j = 0; j < 50; j++) {
                    if (i == 0 || i == 49) {
                        tempv.push_back(-1);
                    }
                    else {
                        if (i == row && j == col) {
                            tempv.push_back(1);
                        }
                        else if (j == 0 || j == 49)
                            tempv.push_back(-1);
                        else
                            tempv.push_back(0);
                    }
                }
                newmap.push_back(tempv);
            }
            return newmap;
        }
    }
}

queue<tuple<int, int>> get_start_position() {
    queue<tuple<int, int>> re;

    tuple<int, int> pos1(1, 1);
    tuple<int, int> pos2(1, 2);
    tuple<int, int> pos3(1, 3);
    tuple<int, int> pos4(1, 4);
    tuple<int, int> pos5(1, 5);

    re.push(pos1);
    re.push(pos2);
    re.push(pos3);
    re.push(pos4);
    re.push(pos5);

    return re;
}

void loadmaps2(vector<vector<int>> map[101]) {
    fstream file;
    char buffer[150];
    string fname;
    for (int i = 101; i < 201; i++) {
        if (i < 10)
            fname = "00" + to_string(i);
        else if (i < 100)
            fname = "0" + to_string(i);
        else
            fname = to_string(i);
        file.open("./map/maps/map_" + fname, ios::in);
        if (!file) {
            cout << "no file" << endl;
        }
        else {
            do {
                vector<int> tempv;
                file.getline(buffer, sizeof(buffer));
                const char* d = " "; //���Ψ̾�
                char *row; //�x�s�C�����ε��G
                row = strtok(buffer, d);
                while (row) {
                    string s = row;
                    int temp = stoi(s);
                    tempv.push_back(temp);
                    row = strtok(NULL, d);
                }
                map[i-100].push_back(tempv);
            } while (!file.eof());
        }
        file.close();
    }
}
vector<int> findthree(int row, int col, queue<tuple<int, int>> snack) {
    int flag3 = 0;
    int flag = 0;
    vector<int> result;
    tuple<int, int> position; //�Ȯɪ��I
    queue<tuple<int, int>> tempsnack = snack;
    for (int i = row - 1; i < row + 2; i++) { //�쥻�I��3*3���d��
        if (i > 0 && i < 49 && flag3 == 0) {
            for (int j = col - 1; j < col + 2; j++) {
                if (j > 0 && j < 49 && flag3 == 0) {
                    tempsnack = snack;
                    flag = 0;
                    position = make_tuple(i, j);
                    //�C�@���I��D����m����A�����
                    while (!tempsnack.empty() && flag == 0) {
                        if (tempsnack.front() == position) {
                            flag = 1;
                        }
                        tempsnack.pop();
                    }
                    if (flag == 0) {
                        flag3 = 1;//�b3*3�����i�H���I���a��
                        row = i;//�s�Iindex
                        col = j;
                        break;
                    }
                }
            }
            if (flag3 == 1)
                break;
        }
    }
    if (flag3 == 1) {
        result.push_back(flag3);
        result.push_back(row);
        result.push_back(col);
    }
    else if (flag3 == 0) {
        result.push_back(flag3);
        result.push_back(0);
        result.push_back(0);
    }
    return result;
}
vector<int> findfive(int row, int col, queue<tuple<int, int>> snack) {
    int flag5 = 0;
    int flag = 0;
    vector<int> result;
    tuple<int, int> position; //�Ȯɪ��I
    queue<tuple<int, int>> tempsnack = snack;
    for (int i = row - 2; i < row + 3; i++) { //�쥻�I��3*3���d��
        if (i > 0 && i < 49 && flag5 == 0) {
            for (int j = col - 2; j < col + 3; j++) {
                if (j > 0 && j < 49 && flag5 == 0) {
                    tempsnack = snack;
                    flag = 0;
                    position = make_tuple(i, j);
                    //�C�@���I��D����m����A�����
                    while (!tempsnack.empty() && flag == 0) {
                        if (tempsnack.front() == position) {
                            flag = 1;
                        }
                        tempsnack.pop();
                    }
                    if (flag == 0) {
                        flag5 = 1;//�b5*5�����i�H���I���a��
                        row = i;//�s�Iindex
                        col = j;
                        break;
                    }
                }
            }
            if (flag5 == 1)
                break;
        }
    }
    if (flag5 == 1) {
        result.push_back(flag5);
        result.push_back(row);
        result.push_back(col);
    }
    else if (flag5 == 0) {
        result.push_back(flag5);
        result.push_back(0);
        result.push_back(0);
    }
    return result;
}
vector<int> findall(int row, int col, queue<tuple<int, int>> snack) {
    int flagall = 0;
    int flag = 0;
    vector<int> result;
    tuple<int, int> position; //�Ȯɪ��I
    queue<tuple<int, int>> tempsnack = snack;
    for (int i = 0; i < 50; i++) { //�쥻�I��3*3���d��
        if (i > 0 && i < 49 && flagall == 0) {
            for (int j = 0; j < 50; j++) {
                if (j > 0 && j < 49 && flagall == 0) {
                    tempsnack = snack;
                    flag = 0;
                    position = make_tuple(i, j);
                    //�C�@���I��D����m����A�����
                    while (!tempsnack.empty() && flag == 0) {
                        if (tempsnack.front() == position) {
                            flag = 1;
                        }
                        tempsnack.pop();
                    }
                    if (flag == 0) {
                        flagall = 1;//�b5*5�����i�H���I���a��
                        row = i;//�s�Iindex
                        col = j;
                        break;
                    }
                }
            }
            if (flagall == 1)
                break;
        }
    }
    if (flagall == 1) {
        result.push_back(flagall);
        result.push_back(row);
        result.push_back(col);
    }
    else if (flagall == 0) {
        result.push_back(flagall);
        result.push_back(0);
        result.push_back(0);
    }
    return result;
}
//(�Ҧ��a��,�U�@�i�a��index,�D����m)
vector<vector<int>> generate_map2(vector<vector<int>> map[101], int mapindex, queue<tuple<int, int>> snack) {
    tuple<int, int> positionONE, positionTWO;
    int row1, row2, col1, col2;
    //    int flag3=0;
    //    int flag5=0;
    //    int flag7=0;
    //    int flagall=0;

        //�M��a�Ϩ�ӱo���I��m
    for (int m = 0; m < 50; m++) {
        for (int n = 0; n < 50; n++) {
            if (map[mapindex][m][n] == 1) {
                row1 = m;
                col1 = n;
                positionONE = make_tuple(m, n);
            }
            if (map[mapindex][m][n] == 2) {
                row2 = m;
                col2 = n;
                positionTWO = make_tuple(m, n);
            }
        }
    }
    //���վ�o���I2�A�A�վ�o���I1
        //�P�_�o���I���S���b�D���W
    int twoOnSnack = 0;
    int oneOnSnack = 0;
    vector<int> result;
    queue<tuple<int, int>> tempsnack = snack;
    while (!tempsnack.empty()) {
        if (tempsnack.front() == positionTWO) {
            twoOnSnack = 1;
            cout << "two on snack" << endl;
        }
        if (tempsnack.front() == positionONE) {
            oneOnSnack = 1;
            cout << "one on snack" << endl;
        }
        tempsnack.pop();
    }
    if (oneOnSnack == 0 && twoOnSnack == 0) { //��ӳ����b�D���W
        return map[mapindex];
    }
    if (twoOnSnack == 1) { //�p�G�o���I2�b�D���W
        result = findthree(row2, col2, snack); //�q3*3�}�l��
        if (result[0] == 1) {
            twoOnSnack = 0;
            row2 = result[1];
            col2 = result[2];
        }
        else if (result[0] == 0) {
            result = findfive(row2, col2, snack); //�q5*5�}�l��
            if (result[0] == 1) {
                twoOnSnack = 0;
                row2 = result[1];
                col2 = result[2];
            }
            else if (result[0] == 0) {
                result = findall(row2, col2, snack); //������
                if (result[0] == 1) {
                    twoOnSnack = 0;
                    row2 = result[1];
                    col2 = result[2];
                }
            }
        }
    }
    if (oneOnSnack == 1) {
        result = findthree(row1, col1, snack); //�q3*3�}�l��
        if (result[0] == 1) {
            oneOnSnack = 0;
            row1 = result[1];
            col1 = result[2];
        }
        else if (result[0] == 0) {
            result = findfive(row1, col1, snack); //�q5*5�}�l��
            if (result[0] == 1) {
                oneOnSnack = 0;
                row1 = result[1];
                col1 = result[2];
            }
            else if (result[0] == 0) {
                result = findall(row1, col1, snack); //������
                if (result[0] == 1) {
                    oneOnSnack = 0;
                    row1 = result[1];
                    col1 = result[2];
                }
            }
        }
    }
    if (oneOnSnack == 0 && twoOnSnack == 0) {  //�o���I1�B2�����b�D���W
        vector<vector<int>> newmap;
        for (int i = 0; i < 50; i++) {
            vector<int> tempv;
            for (int j = 0; j < 50; j++) {
                if (i == 0 || i == 49) {
                    tempv.push_back(-1);
                }
                else {
                    if (i == row1 && j == col1) {
                        tempv.push_back(1);
                    }
                    else if (i == row2 && j == col2)
                        tempv.push_back(2);
                    else if (j == 0 || j == 49)
                        tempv.push_back(-1);
                    else
                        tempv.push_back(0);
                }
            }
            newmap.push_back(tempv);
        }
        return newmap;
    }
}

int main(int argc, char *argv[]) {
    queue<tuple<int, int>> ori_pos;
    queue<tuple<int, int>> new_pos = get_start_position();

    Snake snake(new_pos);

    vector<vector<int>> whole_map[101];//1~100�s�@�ʱi�a��
    vector<vector<int>> whole_map2[101];//101~200�s�@�ʱi�a��
    loadmaps(whole_map);//�q�ɮפ�Ū���a�ϸ��
    loadmaps2(whole_map2);//�q�ɮפ�Ū���a�ϸ��

    int cur_map_index = 1;
    vector<vector<int>> map = generate_map(whole_map, cur_map_index, new_pos);

    int step_limit = 8000;
    int point = 0;
    cout << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "|" << point << "\n";

    clock_t usedTime, limitTime;

    usedTime = 0;
    limitTime = 120000;

    try
    {
        for (int i = 0; i < step_limit; i++) {

            ori_pos = new_pos;

            clock_t tmpTime1, tmpTime2;

            tmpTime1 = clock();

            new_pos = snake.nextPosition(map);

            tmpTime2 = clock();

            usedTime += tmpTime2 - tmpTime1;

            if (usedTime > limitTime) {

                // Create and open a text file
                ofstream f(argv[2]);

                // Write to the file
                f << argv[1] << "," << point << "," << "TimeLimitExceed";

                // Close the file
                f.close();

                break;
            }

            int new_head_x = get<0>(new_pos.back());
            int new_head_y = get<1>(new_pos.back());

            if (i % 1000 == 0) {
                cout << i << ": " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "|" << map[new_head_x][new_head_y] << "$" << point << "\n";
            }
            //cout << i << ": map " << cur_map_index << " | " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "|" << map[new_head_x][new_head_y] << "$" << point << "\n";

            // Walk one step
            int one_step_limit = 1;
            one_step_limit -= abs(get<0>(ori_pos.back()) - new_head_x);
            one_step_limit -= abs(get<1>(ori_pos.back()) - new_head_y);
            if (one_step_limit != 0) {
                cout << argv[1] << " A: Invalid step... " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "\n";

                // Create and open a text file
                ofstream f(argv[2]);

                // Write to the file
                f << argv[1] << "," << point << "," << "InvalidStep";

                // Close the file
                f.close();

                break;
            }

            // Hit wall
            if (map[new_head_x][new_head_y] == -1) {
                cout << argv[1] << " B: GAME OVER! Hit wall... " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "\n";

                // Create and open a text file
                ofstream f(argv[2]);

                // Write to the file
                f << argv[1] << "," << point << "," << "HitWall";

                // Close the file
                f.close();

                break;
            }

            // Hit self
            queue<tuple<int, int>> tmp_queue = new_pos;
            bool ifGameOver = false;
            for (int i = 0; i < new_pos.size() - 1; i++) {
                if (get<0>(tmp_queue.front()) == new_head_x && get<1>(tmp_queue.front()) == new_head_y) {
                    cout << argv[1] << " C: GAME OVER! Hit yourself... " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "\n";

                    // Create and open a text file
                    ofstream f(argv[2]);

                    // Write to the file
                    f << argv[1] << "," << point << "," << "HitSelf";

                    // Close the file
                    f.close();

                    ifGameOver = true;
                    break;
                }
                tmp_queue.pop();
            }
            if (ifGameOver)
                break;
            // Check teleport
            // TBD...

            // Count point and check eat longer
            if (map[new_head_x][new_head_y] > 0) {
                if (new_pos.size() != ori_pos.size() + 1) {
                    cout << argv[1] << " D: Invalid eat length... " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "\n";

                    // Create and open a text file
                    ofstream f(argv[2]);

                    // Write to the file
                    f << argv[1] << "," << point << "," << "InvalidEatLength";

                    // Close the file
                    f.close();

                    break;
                }

                point += map[new_head_x][new_head_y];

                // Create and open a text file
                ofstream f(argv[2]);

                // Write to the file
                f << argv[1] << "," << point << "," << "ErrorInterruption";

                // Close the file
                f.close();

                if (cur_map_index >= 200) {

                    // Create and open a text file
                    ofstream f(argv[2]);

                    // Write to the file
                    f << argv[1] << "," << point << "," << "Finish";

                    // Close the file
                    f.close();

                    break;
                }
                if (cur_map_index < 100) {
                    map = generate_map(whole_map, ++cur_map_index, new_pos);
                }
                else if (cur_map_index < 200) {
                    map = generate_map2(whole_map2, (++cur_map_index) - 100, new_pos);
                }
            }
            else {
                if (new_pos.size() != ori_pos.size()) {
                    cout << argv[1] << " E: Invalid length... " << get<0>(new_pos.back()) << ", " << get<1>(new_pos.back()) << "\n";

                    // Create and open a text file
                    ofstream f(argv[2]);

                    // Write to the file
                    f << argv[1] << "," << point << "," << "InvalidLength";

                    // Close the file
                    f.close();

                    break;
                }
            }

            if (i == step_limit - 1) {
                // Create and open a text file
                ofstream f(argv[2]);

                // Write to the file
                f << argv[1] << "," << point << "," << "OverStepLimit";

                // Close the file
                f.close();
            }
        }
    }
    catch (const exception& e)
    {
        cout << "Error" << e.what() << "\n";

        // Create and open a text file
        ofstream f(argv[2]);

        // Write to the file
        f << argv[1] << "," << point << "," << "Error";

        // Close the file
        f.close();
    }

    cout << argv[1] << " | Final: " << "$" << point << "\n";

    //system("pause");

    return 0;
}
