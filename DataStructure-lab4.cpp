/**
实验题目：校园导游咨询
实验目的：掌握图的存储方法和最短路经算法。
实验内容：设计一个校园导游程序，为来访客人提供各种信息查询服务。测试数据根据实际情况指定。
提示：一般情况下，校园的道路是双向通行的，可设校园平面图是一个无向图。顶点和边均含有相关信息。
实验要求：
1、设计所在学校的校园平面图，所含景点不少于10个。以图中顶点表示校内各景点，存放景点名称、代号、简介等信息；
以边表示路径，存放路径长度等相关信息。
2、为来访客人提供图中任意景点相关信息的查询。
3、为来访客人提供图中任意景点的纹路查询，即查询任意两个景点之间的一条最短的简单路径。

Author: Qin Hao
Environment：Windo10 + CodeBlocks 17.12
Data：2019/06/21

*/
#include <iostream>
#include <cstring>

#define INFINITY 100 // 假定无穷远是100
#define MAX_VERTEX_NUM 10 // 顶点数

using namespace std;

// 景点（顶点）
struct Attraction
{
    int number;// 代号
    string name;// 名称
    string introduce;// 简介
} Attraction, Attractions[MAX_VERTEX_NUM];
// 路径（弧）
struct Arc
{
    int weight;// 权值
    int in;// 起点
    int out;// 终点
} Arc, MGraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 初始化二维数组
void InitMGraph()
{
    FILE* fp = fopen("MGraph.txt","r");
    if(fp == NULL)
    {
        printf("open MGraph.txt error!");
        return;
    }
    for(int i = 0; i < MAX_VERTEX_NUM; ++i)
    {
        for(int j = 0; j < MAX_VERTEX_NUM; ++j)
        {
            fscanf(fp, "%d", &MGraph[i][j].weight);
            MGraph[i][j].in = i;
            MGraph[i][j].out = j;
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
}
// 初始化一维数组
void InitAttractions()
{
    for (int i = 0; i < MAX_VERTEX_NUM; ++i)
        Attractions[i].number = i;

    Attractions[0].name = "building0";
    Attractions[0].introduce = "000000000000";

    Attractions[1].name = "building1";
    Attractions[1].introduce = "1111111111111";

    Attractions[2].name = "building2";
    Attractions[2].introduce = "2222222222222222";

    Attractions[3].name = "building3";
    Attractions[3].introduce = "333333333333";

    Attractions[4].name = "building4";
    Attractions[4].introduce = "44444444444444";

    Attractions[5].name = "building5";
    Attractions[5].introduce = "555555555555555555555555";

    Attractions[6].name = "building6";
    Attractions[6].introduce = "666666666666666";

    Attractions[7].name = "building7";
    Attractions[7].introduce = "77777777";

    Attractions[8].name = "building8";
    Attractions[8].introduce = "88888888";

    Attractions[9].name = "building9";
    Attractions[9].introduce = "99999999999999";
}
// 输出景点信息
void Print()
{
    cout << "以下是全部景点的代号和名称：" << endl;
    for (int i = 0; i < MAX_VERTEX_NUM; ++i)
        cout << "代号：" << Attractions[i].number << " 名称： " << Attractions[i].name << endl;
}
void PrintInfo(int number)
{
    cout << "景点代号: " << number << endl;
    cout << "景点名称: " << Attractions[number].name << endl;
    cout << "景点简介: " << Attractions[number].introduce << endl;
}
void PrintMeau()
{
	cout << "*******校园导游咨询********" << endl;
	cout << "***输入-1执行景点信息查询***" << endl;
	cout << "***输入-2执行最短路径查询***" << endl;
	cout << "***      输入-3退出      ***" << endl;
}
int dist[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
string path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 求两点间最短路径
void FindShortestPath_FLOYD()
{
	for (int i = 0; i < MAX_VERTEX_NUM; i++)//初始化dist和path
        for (int j = 0; j < MAX_VERTEX_NUM; j++)
        {
            dist[i][j] = MGraph[i][j].weight;

            if (dist[i][j] != 100)
                path[i][j] = Attractions[i].name + " " + Attractions[j].name;
            else
                path[i][j] = " ";
        }

	for (int k = 0; k < MAX_VERTEX_NUM; k++)//判定顶点i j之间是否经过k
        for (int i = 0; i < MAX_VERTEX_NUM; i++)
            for (int j = 0; j < MAX_VERTEX_NUM; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k] + "-->" + path[k][j];
                }
}

int main(int argc, char *argv[])
{
    InitMGraph();
    InitAttractions();
    PrintMeau();
    Print();
    FindShortestPath_FLOYD();
    int choice;
    while (true)
    {
        cout << "请输入您要执行功能的编号：" ;
		cin >> choice;
		switch (choice)
		{
		case -1:
		    cout << "请输入景点代号：";
			int number;
			cin >> number;
			PrintInfo(number);
			break;
		case -2:
		    cout << "请输入起点的代号和终点的代号，中间用空格隔开：";
            int u, v;
            cin >> u >> v;
            cout << Attractions[u].name << "到" << Attractions[v].name << "的最短路径为：" << path[u][v] << endl;
            cout << Attractions[u].name << "到" << Attractions[v].name << "的最短长度为: " << dist[u][v] << endl;
			break;
		case -3:
		    cout << "程序已退出！" << endl;
		    return 0;
		}
    }
    return 0;
}
