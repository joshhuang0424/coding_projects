#include "Snake.h"

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
}

// Add anything else you need

void Snake::go(vector<vector<int>> map)
{
	if (current_direction == 0)//現在往下
	{
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y)) //左下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
				position.push(temp);
				current_direction = 0;
			}
			else
			{
				if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 3;
				}
				else
				{
					if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 1;
					}
				}

			}
		}
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y)) //左上
		{
			if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
				position.push(temp);
				current_direction = 3;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
					position.push(temp);
					current_direction = 0;
				}
				else
				{
					if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 1;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y)) //右下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
				position.push(temp);
				current_direction = 0;
			}
			else
			{
				if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 1;
				}
				else
				{
					if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 3;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y)) //右上
		{
			if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
				position.push(temp);
				current_direction = 1;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
					position.push(temp);
					current_direction = 0;
				}
				else
				{
					if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 3;
					}
				}
			}
		}
	}
//==========================================================================================================
	if (current_direction == 1)//現在往右
	{
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y)) //左下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
				position.push(temp);
				current_direction = 0;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
					position.push(temp);
					current_direction = 2;
				}
				else
				{
					if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 1;
					}
				}

			}
		}
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y)) //左上
		{
			if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
				position.push(temp);
				current_direction = 2;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
					position.push(temp);
					current_direction = 0;
				}
				else
				{
					if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 1;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y)) //右下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
				position.push(temp);
				current_direction = 0;
			}
			else
			{
				if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 1;
				}
				else
				{
					if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
						position.push(temp);
						current_direction = 2;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y)) //右上
		{
			if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
				position.push(temp);
				current_direction = 2;
			}
			else
			{
				if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 1;
				}
				else
				{
					if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
						position.push(temp);
						current_direction = 0;
					}
				}
			}
		}
	}
//==========================================================================================================
	if (current_direction == 2)//現在往上
	{
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y)) //左下
		{
			if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
				position.push(temp);
				current_direction = 3;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
					position.push(temp);
					current_direction = 2;
				}
				else
				{
					if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 1;
					}
				}

			}
		}
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y)) //左上
		{
			if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
				position.push(temp);
				current_direction = 2;
			}
			else
			{
				if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 3;
				}
				else
				{
					if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 1;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y)) //右下
		{
			if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
				position.push(temp);
				current_direction = 1;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
					position.push(temp);
					current_direction = 2;
				}
				else
				{
					if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 3;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y)) //右上
		{
			if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
				position.push(temp);
				current_direction = 2;
			}
			else
			{
				if(map[get<0>(position.back()) + 1][get<1>(position.back()) ] != -1)//如果可以往右
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) + 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 1;
				}
				else
				{
					if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 3;
					}
				}
			}
		}
	}
//==========================================================================================================
if (current_direction == 3)//現在往左
	{
		if ((get<0>(position.back()) == food_x)&&(get<1>(position.back()) > food_y)) //下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				if(map[get<0>(position.back())][get<1>(position.back()) - 1] == 1)
				{
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
					position.push(temp);
					current_direction = 0;
				}
				else
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
					position.push(temp);
					current_direction = 0;
				}
			}
		}

		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) > food_y)) //左下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
				position.push(temp);
				current_direction = 0;
			}
			else
			{
				if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 3;
				}
				else
				{
					if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
						position.push(temp);
						current_direction = 2;
					}
				}

			}
		}
		if((get<0>(position.back()) > food_x)&&(get<1>(position.back()) < food_y)) //左上
		{
			if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
				position.push(temp);
				current_direction = 2;
			}
			else
			{
				if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
					position.push(temp);
					current_direction = 3;
				}
				else
				{
					if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
						position.push(temp);
						current_direction = 0;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) > food_y)) //右下
		{
			if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
				position.push(temp);
				current_direction = 0;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
					position.push(temp);
					current_direction = 2;
				}
				else
				{
					if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 3;
					}
				}
			}
		}
		if((get<0>(position.back()) < food_x)&&(get<1>(position.back()) < food_y)) //右上
		{
			if(map[get<0>(position.back())][get<1>(position.back()) + 1] != -1) //如果可以往上
			{
				position.pop();
				tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) + 1);
				position.push(temp);
				current_direction = 2;
			}
			else
			{
				if(map[get<0>(position.back())][get<1>(position.back()) - 1] != -1)//如果可以往下
				{
					position.pop();
					tuple<int, int> temp(get<0>(position.back()), get<1>(position.back()) - 1);
					position.push(temp);
					current_direction = 0;
				}
				else
				{
					if(map[get<0>(position.back()) - 1][get<1>(position.back())] != -1) //如果可以往左
					{
						position.pop();
						tuple<int, int> temp(get<0>(position.back()) - 1, get<1>(position.back()));
						position.push(temp);
						current_direction = 3;
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

//currentPoision後直接判斷四個方向
//判斷會不會打到自己尾巴再判斷往哪走
//為何原地踏步