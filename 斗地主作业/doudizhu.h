#pragma once
#ifndef _doudizhu_h
#define _doudizhu_h
#include<easyx.h>
#include<vector>
#include <algorithm>
#include<iostream>
#include<Windows.h>
#include<string.h>
#include<time.h>
#include <graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
const double pi = 3.14159;
//牌的结构体
typedef struct pai
{
	int huase;
	int shuzi;
	pai* next;
}pai;
//出牌的结构体
typedef struct outpai
{
	int huase;  //花色
	int shuzi;  //数字
}outpai;
//牌的判断比较用于打牌用
typedef struct judgepai
{
	int type;   //类型
	int mini;   //最小
	int unit;   //单位
	vector<int> post;   //位置
}judgepai;
typedef struct menu
{
	bool man_machine;   //是否是人机
	int degree;    //难度系数
};
//用于拆牌用
//用于打牌用
typedef struct divide
{
	vector<judgepai> dan;  //单牌
	vector<judgepai> dui;  //对子
	vector<judgepai> san;  //纯三
	vector<judgepai> boom;   //炸弹
	vector<judgepai> liandan;    //连单
	vector<judgepai> liandui;   //连对
	vector<judgepai> liansan;  //连三
	int num;    //手数
	int value;  //权值
}divide;
//判断出牌原则的结构体
//1：下家是队友还是对手 2：本次接牌是接对手出牌还是队友出牌 3:对手是否报单 4：队友是否报单 5 : 对手出牌还是队友出牌
typedef struct principle
{
	int the_ene;         //是否为敌方出牌
	int post_sin_fri;    //队友是否报单
	int post_sin_ene;    //对手是否报单 
}principle;
//对于一手牌返回权值手数和顺序  
typedef struct project
{
	int value;
	int num;
	int order[5];
}project;
//用于判断各种极端情况
extern principle prin[4];
//拆出的手牌
extern divide shoupai[4];
//用来保存出牌的数组
extern pai out[10];
extern menu mymenu;  //我的菜单选项
//装生成的牌
extern int a[56];
//不要
extern int no;
//保证产生规定牌
extern int vis1[21];
extern int vis2[21];
extern int vis3[21];
//存储出牌
extern int put1[21];
extern int put2[21];
extern int put3[21];
//标志
extern int flag;
//是否退出游戏
extern bool if_out_game;
//玩家
extern int player;
//取得胜利标识符
extern int win;
//到谁出牌标识符
extern int post;
//当前分数
extern int point;
//有没有人叫3分标识符
extern int three;
//谁是地主标识符
extern int people;
//有没有结束叫地主环节
extern int on;
//叫分结束判断标记
extern int over;
//保存指针的数组
extern int *put[4];
extern int *vis[4];
extern pai *head[4];
extern pai *tail[4];
//所有牌的文件名
extern char name[60][12];
extern IMAGE mypai[60];
//之前出牌
extern outpai last[8];
//地主牌
extern outpai dizhu[5];
//现在出牌
extern outpai now[8];
//上次出了几个牌
extern int lastnum;
//这次出了几个牌
extern int nownum;
//保存上家出牌类型
extern judgepai lastout;
//初始菜单界面
void menuface();
//二级菜单界面
void second_menu();
//三级菜单界面
void third_menu();
//生成一副牌链表
void link();
//画出一副牌——自己的
void Draw();
//人人对战三副牌
void Draw_per();
//人机对战三副牌
void Draw_per_ma();
//发牌界面
void freshofpuk();
//生成一副牌链表
void form();
//出牌与不要
void outandno();
//出牌判断
bool judge(int *puts, pai *head);
//针对不要的判断
bool dont();
//不要错误
void nofalse();
//牌的转换
void change();
//胜利
void winer_print();
//画出上家出牌
void Drawlastout();
//打牌   //就是删除该结点
void putpai(int *&vis, int *&put, pai *&head, int peo);
//胜利判断
bool winner_judge();
//初始化
void initiaze();
//每次循环玩家
void round();
//结束单轮出牌
bool over_judge();
//出牌判断——出牌基本规则
judgepai* basicrule(outpai *now);
//出牌判断——接牌
bool replyrule(outpai *now);
//叫地主
void calldizhu(); 
//叫分画面
void fenshu();
//画出地主牌
void drawdizhupai();
//拆牌
void cut(pai *head,divide &shoupai);
//对于一手发牌的数据抽象
void abstract();
//找顺子函数
judgepai foundsunzi(int type, int *shuzi, int *&vis);
//寻找数组中四 三 二 一 的个数
judgepai found(int type, int *shuzi, int *&vis);
//对于一个保存数据的数组的数据处理
void dateorg(int *shuzi, divide &shoupai, int *&vis);
//匹配牌
void match(divide shoupai, int *&vis,int *&put);
//出牌——提示出牌实际上就是把牌相应位置的vis变成1
void  output(int *&vis, int *&put,vector<int> post);
//自动叫地主
void autocallpoint(pai *head, divide shoupai);
//自动出牌
void autoputpai(int *put, pai *&head, int peo);
//出牌——删除链表
void deletenode(pai *&head, int *put);
//把所选牌读入当前牌
void readinnow(pai *head, int *put);
//没有匹配牌型只能不要
void no_for_auto(int *put);
//出牌——提示出牌实际上就是把牌相应位置的
void  output_for_auto(int *&put, vector<int> post);
//人工智能中匹配牌的基本原则 —— 按照从小到大的顺序压牌
bool match_for_autoout(divide shoupai, int *&put);
//对于自动出牌    1：下家是队友还是对手 2：本次接牌是对手出牌还是队友出牌 3:对手是否报单 4：队友是否报单 5:对手出牌还是队友出牌
void autoout(divide shoupai, int *&put);
//出牌——寻找匹配位置
bool find_and_change(int n, vector<judgepai> judge, int *put, int posted);   //post为1从小到大 post为0从大到小
//从对子中组合出连对vector<judgepai>
void lianduiformdui(vector<judgepai> &dui, vector<judgepai> &liandui);
//从三中组合出连三vector<judgepai>
void liansanformsan(vector<judgepai> &san, vector<judgepai> &liansan);
//出三张的时候接单或者接对
void connectdanordui(divide &shoupai);
//数据处理，对于一副手牌怎么拆出最优
void dateorgforper(int *shuzi, divide &shoupai, int *&vis);
//找到所有顺子
void fundallshunzi(divide &shoupai, int *&shuzi, int *&vis);
//计算权值的函数
int the_value(divide shoupai);
//找出一手牌的权值 手数 和顺序方便比较
project va_nu_cmp(int *shuzi, int *&vis);
//找到所有单
void fundalldan(divide &shoupai, int *&shuzi, int *&vis);
//找到所有二
void fundalldui(divide &shoupai, int *&shuzi, int *&vis);
//找到所有三
void fundallsan(divide &shoupai, int *&shuzi, int *&vis);
//找到所有四
void fundallsi(divide &shoupai, int *&shuzi, int *&vis);
//飞机特效
void plane();
//火箭特效
void boom();
#endif


