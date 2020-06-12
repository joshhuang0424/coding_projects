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

moveDirection Snake::nextVerticalDirection()
{
	if(get<0>(position.back()) > food_x) return DOWN;
	else return UP;
}

moveDirection Snake::nextHorizontalDirection()
{
	if(get<1>(position.back()) > food_y) return LEFT;
	else return RIGHT;
}

// Add anything else you need
bool Snake::ChangeDirection(moveDirection direction)
{
	if ((direction + 2) % 4 == current_direction)	//玩家輸入方向與蛇當前移動方向相反將不改變此時蛇的前進方向
		return false;
	else
		current_direction = direction;
	return true;
}

void Snake::go(moveDirection direction)
{
	if()
	{
		switch (current_direction)//根據此時的方向來判斷該如何移動。移動時為提高效率將只需要處理首尾點元素
		{
			case moveDirection::DOWN:
				position.push(CPoint(snake.begin()->GetX(), snake.begin()->GetY() + 1)); break;
			case moveDirection::LEFT:
				snake.push_front(CPoint(snake.begin()->GetX() - 2, snake.begin()->GetY())); break;
			case moveDirection::RIGHT:
				snake.push_front(CPoint(snake.begin()->GetX() + 2, snake.begin()->GetY())); break;
			case moveDirection::UP:
				snake.push_front(CPoint(snake.begin()->GetX(), snake.begin()->GetY() - 1)); break;
		}
		snake.pop_back();
	}
	else
	{
		if()
	}


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