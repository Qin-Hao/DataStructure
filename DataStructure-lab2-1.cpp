/*
	Question:
	迷宫求解
	迷宫只有两个门,一个叫做入口,另一个叫做出口。把一只老鼠从一个无顶盖的大盒子的入口处赶进迷宫。
	迷宫中设置很多隔壁,对前进方向形成了多处障碍,在迷宫的唯一出口处放置了一块奶酪,吸引老鼠在迷宫中寻找通路以到达出口。
	求解迷宫问题,即找出从入口到出口的路径。
   【知识要点】
	迷宫问题是栈应用的一个典型例子。求解过程可采用回溯法。回溯法是一种不断试探且及时纠正错误的搜索方法。从入口出发,按某一方向
	向前探索,若能走通(未走过的),即某处可以到达,则到达新点,否则试探下一方向 ; 若所有的方向均没有通路,则沿原路返回前一
	点,换下一个方向再继续试探,直到所有可能的通路都探索到,或找到一条通路,或无路可走又返回到入口点。在求解过程中,为了保证
	在到达某一点后不能向前继续行走(无路)时,能正确返回前一点以便继续从下一个方向向前试探,则需要用一个栈保存所能够到达的每
	一点的下标及从该点前进的方向,栈中保存的就是一条迷宫的通路。为了确保程序能够终止,调整时,必须保证曾被放弃过的填数序列不
	被再次试验,即要求按某种有序模型生成填数序列。给解的候选者设定一个被检验的顺序,按这个顺序逐一生成候选者并检验。
   【实现提示】
	对于迷宫问题,用回溯法的难点就在如何为解空间排序,以确保曾被放弃过的填数序列不被再次试验,在二维迷宫里面,
	从出发点开始,每个点按四邻域算,按照右、上、左、下的顺序搜索下一落脚点,有路则进,无路即退,前点再从下一个方向搜索,即可
	构成一有序模型。

	Author: Qin Hao
	Data: 2019/4/25
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_INIT_SIZE 100 //初始容量
#define STACK_INCREMENT 10  //增加量

// 位置元素
typedef struct {
	int row;    // 行号
	int col;    // 列号
}posElem;

// 路径元素
typedef struct {
	posElem seat;	// 位置
	int dir;    // 要前往的方向 1 上 2 下 3 左 4 右
}pathElem;

// 路径栈
typedef struct {
	pathElem* base;
	pathElem* top;
	int stacksize;
}pathStack;

// 初始化栈
void initStack(pathStack& s) {
	s.base = (pathElem*)malloc(STACK_INIT_SIZE * sizeof(pathElem));
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
}

// 压栈
void pushStack(pathStack& s, pathElem e) {
	if (s.top - s.base >= s.stacksize) {
		s.base = (pathElem*)realloc(s.base, (s.stacksize + STACK_INCREMENT) * sizeof(pathElem));
		s.top = s.base + s.stacksize;
		s.stacksize += STACK_INCREMENT;
	}
	*(s.top) = e;
	s.top++;
}

// 出栈
pathElem popStack(pathStack& s) {
	(s.top)--;
	pathElem e = *(s.top);
	return e;
}

// 判断栈是否为空
bool emptyStack(pathStack s) {
	return (s.base == s.top);
}

// 随机迷宫生成器
int** mazeMaker(int row, int col) {
	int** maze = new int* [row];
	for (int i = 0; i < row; ++i) {
		maze[i] = new int[col];
	}
	srand(unsigned(time(0)));
	for (int j = 0; j < row; ++j) {
		for (int k = 0; k < col; ++k) {
			maze[j][k] = rand() % 6;
			if (maze[j][k] != 0) {
				maze[j][k] = 0;
			}
			else {
				maze[j][k] = 1;
			}
		}
	}
	return maze;
}

// 寻找通路
pathStack mazePath(int** maze, posElem start, posElem end, int row, int col) {
	pathStack s1, s2;
	// 初始化栈
	initStack(s1);	
	initStack(s2);

	maze[start.row][start.col] = 2; // 标记走过的路径

	posElem curpos = start;
	pathElem e, temp;
	e.seat = curpos;
	e.dir = -1; // 初始方向-1
	pushStack(s1, e);

	int di;
	while (!emptyStack(s1)) {
		temp = popStack(s1);
		di = temp.dir + 1;
		while (di < 4) {
			
		}
	}
}

int main() {
	int row = 10, col = 10;
	int** maze = mazeMaker(row, col);
	maze[0][0] = 0;
	maze[row - 1][col - 1] = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	posElem start, end;
	start.row = 0;
	start.col = 0;
	end.row = row - 1;
	end.col = col - 1;

	int 
	pathStack s = mazePath(maze, start, end, row, col);
	while (count != 0) {
		pathElem e = popStack(s);
		printf("%d %d ", e.seat.row, e.seat.col);
		count--;
	}
	return 0;
}
