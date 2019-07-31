/**
1、输入一段100—200字的英文短文，存入一文件 a 中。
2、写函数统计短文出现的字母个数 n 及每个字母的出现次数
3、写函数以字母出现次数作权值，建 Haffman 树（n 个叶子），给出 每个字母的 Haffman 编码。
4、用每个字母编码对原短文进行编码，码文存入文件 b 中。
5、用 Haffman 树对 b 中码文进行译码，结果存入文件 c 中，比较 a,c是否一致，以检验编码、译码的正确性。
*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<fstream>

using namespace std;

int a[27]; //存储每个字母出现的次数 26+\n
int len;    //短文长度
char s[1000000];    //读取文件需要

int m;  //一共多少个点
int num = 0;  //叶子节点个数

map<char, int> v; //对应的字母和出现的次数

typedef struct {
    char c; //叶子节点类型
    int weight; //权重
    int parent, lchild, rchild; //节点的双亲下标，左右孩子的下标
    char code; //结点编号
} htnode, *huffmantree;

// 2.统计短文出现的字母种数和每个字母出现的次数
void countLeterNumberAndFrequency() {
    FILE *fi = freopen("a.txt", "r", stdin);
    gets(s);    //gets()读入时空格也读入，直到遇到回格键
    len = strlen(s);
    cout << "短文长度为：" << len << endl;
    for(int i = 0; i < len; i++) {
        if(s[i] - 'a' >= 0 && s[i] - 'a' <= 25) {
            a[s[i] - 'a']++;
        }
        if(s[i] - 'A' >= 0 && s[i] - 'A' <= 25) {
            a[s[i] - 'A']++;
        }
    }
    cout << "字母及出现的次数为：" << endl;
    for(int i = 0; i < 26; i++) {
        if(a[i] > 0) {
            num++;  //统计叶子节点个数
            char cha;
            cha = 'a' + i;
            cout << cha << ": " << a[i] << " " << endl; //每个字母出现的次数  作为权
            v.insert(pair<char, int>(cha, a[i]));
        }
    }
    cout << "字母出现的种数：" << num << endl;
    fclose(fi);
}

// 选择两个权值最小的点
void Selectmin(huffmantree ht, int num2, int &s1, int &s2) {
    s1 = s2 = 0; //初始化两个最小节点的位置
    int i;
    for(i = 1; i <= num2; i++) {
        if(ht[i].parent == 0) {
            if(s1 == 0) {
                s1 = i;
            } else {
                s2 = i;
                break;
            }
        }
    }
    if(ht[s1].weight > ht[s2].weight) {
        int t = s1;
        s1 = s2;
        s2 = t;
    }
    //找到两个权值最小的点的位置
    for(i = i + 1; i < num2; i++) {
        if(ht[i].parent == 0) {
            if(ht[i].weight < ht[s1].weight) {
                s2 = s1;
                s1 = i;
            } else if(ht[i].weight < ht[s2].weight) {
                s2 = i;
            }
        }
    }
}

//创建huffmantree
void creathuffmantree(huffmantree &ht, int num, map<char, int> v) {
    m = 2 * num - 1; //num个叶子的huffman树共有2num-1个节点
    ht = new htnode[m + 1]; //htnode[0]不存节点
    for(int i = 1; i <= m; i++) { //初始化每个节点的值
        ht[i].parent = ht[i].lchild = ht[i].rchild = 0;
        ht[i].code = '9';     //初始化编码都为-1
    }
    map<char, int>::reverse_iterator iter;
    int j = 1;
    for(iter = v.rbegin(); iter != v.rend(); iter++) {
        ht[j].c = iter->first;
        ht[j].weight = iter->second;
        j++;
    }
    ht[0].weight = num;
    for(int i = num + 1; i <= m; i++) { //已有num个节点，从num+1开始添加节点  共添加num-1个，也就是到m
        int s1, s2;
        Selectmin(ht, i, s1, s2); //传入添加节点的位置  返回两个最小值s1<=s2
        //将两节点的双亲设置为新节点的位置
        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[s1].code = '0';   //编码
        ht[s2].code = '1';
        //添加新节点，左右孩子
        ht[i].lchild = s1;
        ht[i].rchild = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight; //新节点权值
    }
}
//计算huffman树总路径长度
int huffmantreeWPL(huffmantree ht, int i, int d) { //传入huffman树，节点位置，节点深度
    if(ht[i].lchild == 0 && ht[i].rchild == 0) { //叶子节点；算出该节点路径
        return ht[i].weight * d;
    } else { // 若该节点不是叶子节点，则该节点的路径等于左右孩子的路径和
        return huffmantreeWPL(ht, ht[i].lchild, d + 1) + huffmantreeWPL(ht, ht[i].rchild, d + 1);
    }
}
//输出huffman树各节点的信息
void printf(huffmantree ht) {
    for(int i = 1; i <= m; i++) {
        cout << "节点的序号： " << i << " ";
        cout << "父亲节点序号: " << ht[i].parent << " ";
        cout << "权值： " << ht[i].weight << " ";
        if (ht[i].c) {
            cout << "叶子节点： " << ht[i].c << " " << endl;
        } else {
            cout << "非叶子结点" << " ";
            cout << "左孩子节点序号： " << ht[i].lchild << " ";
            cout << "右孩子节点序号： " << ht[i].rchild << " " << endl;
        }
    }
}
//输出各叶子节点的编码
void Encoding(huffmantree ht, int i) {
    if(ht[i].parent == 0) {
        return;
    } else {
        Encoding(ht, ht[i].parent);
    }
    cout << ht[i].code;


}
//输出叶子节点的编码
void huffmantreeEncoding(huffmantree ht) {
    printf("\n");
    for(int i = 1; i <= num; i++) { //只输出前num,即叶子节点的编码
        if(ht[i].lchild == 0 && ht[i].rchild == 0) { //如果该节点为叶子节点
            cout << ht[i].c << " 权值:";
            printf("%d：", ht[i].weight);
            cout << "编码：";
            Encoding(ht, i);   //用递归输出该节点的编码
            printf("\n");
        }
    }

}
//对原文进行编码，存入b中
void trans(huffmantree ht) {
    FILE *fi = freopen("a.txt", "r", stdin);
    FILE *fo = freopen("b.txt", "w", stdout);
    gets(s);    //gets()读入时空格也读入，直到遇到回格键
    len = strlen(s);
    for(int i = 0; i < len; i++) {
        for(int j = 1; j <= num; j++) {
            if(s[i] == ht[j].c) {
                Encoding(ht, j);
            }
        }
        if(s[i] < 'a' || s[i] > 'z') {
            cout << s[i];
        }
    }
    cout<<endl;
    fclose(fo);
    fclose(fi);
}

//用Haffman树对b中码文进行译码，结果存入文件c中，比较a,c是否一致，以检验编码、译码的正确性。
void decoding(huffmantree ht) {
    FILE *fi1 = freopen("a.txt", "r", stdin);
    gets(s);
    fclose(fi1);

    FILE *fi2 = freopen("b.txt", "r", stdin);
    char b[101000];
    gets(b);
    fclose(fi2);

    FILE *fi3 = freopen("c.txt", "w", stdout);

    int i = m;
    int j = 0;
    while(b[j] != '\0') { //遍历字符数组/编码串
        if(b[j] == '0')
            i = ht[i].lchild; //走向左孩子
        else if(b[j] == '1')
            i = ht[i].rchild;  //走向右孩子
        else
            printf("%c", b[j]);
        if(ht[i].lchild == 0) { //看是否该节点为叶子节点
            printf("%c", ht[i].c); //是的话输出，并返回根节点
            i = m;
        }
        j++;   //无论是否找到叶子节点都读取下一个编码串字符
    }
}

int main() {
    huffmantree ht;
    countLeterNumberAndFrequency();
    creathuffmantree(ht, num, v); // 创建赫夫曼树
    cout << "WPL (树的所有叶结点的带权路径长度之和，称为树的带权路径长度表示为WPL)= " << huffmantreeWPL(ht, m, 0) << endl;
    printf(ht); //输出huffman树各节点的信息
    huffmantreeEncoding(ht);    //输出叶子节点的编码
    trans(ht);  //对原文进行编码，存入b中
    decoding(ht);   //用Haffman树对b中码文进行译码，结果存入文件c中，比较a,c是否一致，以检验编码、译码的正确性。
    return 0;
}
