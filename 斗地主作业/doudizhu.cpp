#include "stdafx.h"
#include"doudizhu.h"
#include <algorithm>
#include <math.h>
using namespace std;
//用来保存出牌的数组
pai out[10]; 
//装生成的牌
int a[56];
//不要
int no = 0;
//是否退出游戏
bool if_out_game = false;
//保证产生规定牌
int vis1[21];
int vis2[21];
int vis3[21];
//存储出牌
int put1[21];
int put2[21];
int put3[21];
//标志
int flag = 1;
//玩家
int player = 1;
//是否胜利标识符
int win = 1;
//轮到谁出牌标识符
int post = 1;
//谁是地主标识符
int people = 0;
//有没有结束叫地主环节
int on;
//当前分数
int point;
//有没有人叫3分标识符
int three;
//叫分结束判断标记
int over;
//保存指针的数组
int *put[4] = { NULL,put1,put2,put3 };
int *vis[4] = { NULL,vis1,vis2,vis3 };
pai *head[4] = { NULL };
pai *tail[4] = { NULL };
//所有牌的文件名
char name[60][12] = { "pk//1.jpg","pk//2.jpg","pk//3.jpg","pk//4.jpg","pk//5.jpg","pk//6.jpg","pk//7.jpg","pk//8.jpg","pk//9.jpg","pk//10.jpg","pk//11.jpg","pk//12.jpg","pk//13.jpg","pk//14.jpg","pk//15.jpg","pk//16.jpg","pk//17.jpg","pk//18.jpg","pk//19.jpg","pk//20.jpg","pk//21.jpg",
"pk//22.jpg","pk//23.jpg","pk//24.jpg","pk//25.jpg","pk//26.jpg","pk//27.jpg","pk//28.jpg","pk//29.jpg","pk//30.jpg","pk//31.jpg","pk//32.jpg","pk//33.jpg","pk//34.jpg","pk//35.jpg","pk//36.jpg","pk//37.jpg","pk//38.jpg","pk//39.jpg","pk//40.jpg","pk//41.jpg","pk//42.jpg","pk//43.jpg","pk//44.jpg","pk//45.jpg",
"pk//46.jpg","pk//47.jpg","pk//48.jpg","pk//49.jpg","pk//50.jpg","pk//51.jpg","pk//52.jpg","pk//53.jpg","pk//54.jpg" };
IMAGE mypai[60];
//之前出牌
outpai last[8];
//现在出牌
outpai now[8];
//地主牌
outpai dizhu[5];
//上次出了几个牌
int lastnum;
//这次出了几个牌
int nownum;
//上家出牌
judgepai lastout;
//拆出的手牌
divide shoupai[4];
//用于判断各种极端情况
principle prin[4];
//菜单变量
menu mymenu;
//初始化
//初始菜单界面
void menuface()
{
	initgraph(800, 600, NULL); //初始化画布
	loadimage(NULL, "界面//二级菜单.jpg", 800, 600);
	IMAGE ima1,ima2;
	loadimage(&ima1, "界面//开始游戏.jpg", 200, 80);
	loadimage(&ima2, "界面//退出游戏.jpg", 200, 80);
	putimage(300, 200, &ima1);
	putimage(300, 400, &ima2);
	PlaySound("前奏.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		//rectangle(300, 520, 500, 570);
		if (m.x >= 300 && m.x <= 500 && m.y >= 200 && m.y <= 280 && m.mkLButton == true)  //开始游戏进入二级菜单界面
		{
			second_menu();
			break;
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 400 && m.y <= 480 && m.mkLButton == true)  //退出游戏关闭程序
		{
			if_out_game = true;
			break;
		}
	}
}
//二级菜单界面
void second_menu()
{
	loadimage(NULL, "界面//二级菜单.jpg", 800, 600);
	IMAGE ima1, ima2;
	loadimage(&ima1, "界面//人人对战.jpg", 200, 80);
	loadimage(&ima2, "界面//人机对战.jpg", 200, 80);
	putimage(100, 150, &ima1);
	putimage(500, 150, &ima2);
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.x >= 100 && m.x <= 300 && m.y >= 150 && m.y <= 230 && m.mkLButton == true)
		{
			mymenu.man_machine = false;
			break;
		}
		else if (m.x >= 500 && m.x <= 700 && m.y >= 150 && m.y <= 230 && m.mkLButton == true)  //人机对战
		{
			mymenu.man_machine = true;
			third_menu();
			break;
		}
	}
}
//三级菜单界面
void third_menu()
{
	IMAGE ima1, ima2,ima3;
	loadimage(&ima1, "界面//简单.jpg", 150, 60);
	loadimage(&ima2, "界面//中级.jpg", 150, 60);
	loadimage(&ima3, "界面//困难.jpg", 150, 60);
	putimage(525, 240, &ima1);
	putimage(525, 310, &ima2);
	putimage(525, 380, &ima3);
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.x >= 525 && m.x <= 675 && m.y >= 240 && m.y <= 300 && m.mkLButton == true)
		{
			mymenu.degree = 1;
			break;
		}
		else if (m.x >= 525 && m.x <= 675 && m.y >= 310 && m.y <= 370 && m.mkLButton == true)
		{
			mymenu.degree = 2;
			break;
		}
		else if(m.x >= 525 && m.x <= 675 && m.y >= 380 && m.y <= 440 && m.mkLButton == true)
		{
			mymenu.degree = 3;
			break;
		}
		else if (m.x >= 100 && m.x <= 300 && m.y >= 150 && m.y <= 230 && m.mkLButton == true)
		{
			mymenu.man_machine = false;
			break;
		}
	}
	PlaySound("欢快的音乐.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
	//一个新的动画——5秒

	loadimage(NULL, "界面//二级菜单.jpg", 800, 600);
	//图像处理
	IMAGE ima;
	loadimage(&ima,"界面//动画.jpg", 200, 100);
	for (int i=0;i<48;i++)
	{
		putimage(60+i*10,400, &ima);
		Sleep(100);
	}

}
void initiaze()
{
	form();
	link();
	PlaySound("Faded.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
	loadimage(NULL, "timg.jpg", 800, 600); //加载背景
}
//排序所用
bool cmp(outpai a, outpai b)
{
	if (a.shuzi != b.shuzi)
		return a.shuzi < b.shuzi;
	else if (a.huase != b.huase)
		return a.huase < b.huase;
}
//产生一套随机牌
void form()
{
	int t = 0;
	for (int i = 1; i <= 54; i++)
	{
		a[i] = i;
	}
	for (int i = 1; i <= 54; i++)
	{
		loadimage(&mypai[i], name[a[i - 1]], 80, 100);
	}
	srand((unsigned int)time(NULL));
	while (t < 100)
	{
		int n1 = rand() % 54 + 1;
		int n2 = rand() % 54 + 1;
		int p = a[n1];
		a[n1] = a[n2];
		a[n2] = p;
		t++;
	}
	sort(a + 1, a + 18);
	sort(a + 18, a + 35);
	sort(a + 35, a + 52);
}
//生成一副牌链表
//(shuzi-1)*4+huase=牌的序号
void link()
{
	//牌一
	for (int i = 1; i <= 17; i++)
	{
		pai *temp;
		temp = new pai;
		if (a[i] % 4 == 0)
		{
			temp->shuzi = a[i] / 4;
			temp->huase = 4;
		}
		else
		{
			temp->shuzi = a[i] / 4 + 1;
			temp->huase = a[i] % 4;
		}
		if (head[1] == NULL)
		{
			head[1] = temp;
			tail[1] = temp;
		}
		else
		{
			tail[1]->next = temp;
			tail[1] = temp;
		}
	}
	tail[1]->next = NULL;
	//牌二
	for (int i = 18; i <= 34; i++)
	{
		pai *temp;
		temp = new pai;
		if (a[i] % 4 == 0)
		{
			temp->shuzi = a[i] / 4;
			temp->huase = 4;
		}
		else
		{
			temp->shuzi = a[i] / 4 + 1;
			temp->huase = a[i] % 4;
		}
		if (head[2] == NULL)
		{
			head[2] = temp;
			tail[2] = temp;
		}
		else
		{
			tail[2]->next = temp;
			tail[2] = temp;
		}
	}
	tail[2]->next = NULL;
	//牌三
	for (int i = 35; i <= 51; i++)
	{
		pai *temp;
		temp = new pai;
		if (a[i] % 4 == 0)
		{
			temp->shuzi = a[i] / 4;
			temp->huase = 4;
		}
		else
		{
			temp->shuzi = a[i] / 4 + 1;
			temp->huase = a[i] % 4;
		}
		if (head[3] == NULL)
		{
			head[3] = temp;
			tail[3] = temp;
		}
		else
		{
			tail[3]->next = temp;
			tail[3] = temp;
		}
	}
	tail[3]->next = NULL;
	//地主牌
	for (int i = 52; i <= 54; i++)
	{
		if (a[i] % 4 == 0)
		{
			dizhu[i-52].shuzi = a[i] / 4;
			dizhu[i - 52].huase = 4;
		}
		else
		{
			dizhu[i - 52].shuzi = a[i] / 4 + 1;
			dizhu[i - 52].huase = a[i] % 4;
		}
	}
}
//拆牌——拆出最优组合
void cut(pai *head,divide &shoupai)
{
	pai *temp = head;
	judgepai judge;
	int shuzi[25];
	int vis[25];
	memset(shuzi, 0, sizeof(shuzi));
	memset(vis, 0, sizeof(vis));
	int t = 0;
	while (temp)
	{
		shuzi[t++] = temp->shuzi;
		temp = temp->next;
	}
	int *p = vis; // vis是用来记录手牌数组中单个数字是否已经被拆过的标志
	//对于一个保存数据的数组的数据处理
	if (prin[player].the_ene)               //敌方出牌
		dateorg(shuzi, shoupai, p);         //特殊拆牌 只拆基本牌
	else
		dateorgforper(shuzi, shoupai, p);  //接队友牌 自己出牌
	//数据处理完毕
}
//对于一个保存数据的数组的数据处理——用于特殊出牌
void dateorg(int *shuzi,divide &shoupai,int *&vis)
{
	//初始化
	shoupai.boom.clear();
	shoupai.dan.clear();
	shoupai.dui.clear();
	shoupai.san.clear();         //对于拆牌，每次不同情况会有不同的拆牌先后顺序
	shoupai.liandan.clear();     //我应该怎样才能取得最优的结果  
	shoupai.liandui.clear();     //两个技术难点，对于顺子的拆牌怎么办 双顺三顺的组合怎么办
	shoupai.liansan.clear();    //这是按照优先级处理的牌根据上家出牌类型来拆
	void(*f[5])(divide &shoupai, int *&shuzi, int *&vis) = { fundallshunzi,fundallsi,fundallsan,fundalldui }; //顺 四 三 二 
	int turn[5] = { 0,1,2,3 };
	if (lastout.type == 5)  //连单
	{
		(*f[turn[0]])(shoupai, shuzi, vis);
		(*f[turn[1]])(shoupai, shuzi, vis);
		(*f[turn[2]])(shoupai, shuzi, vis);
		(*f[turn[3]])(shoupai, shuzi, vis);
		for (int i = 0; i < shoupai.liandan.size(); i++)
		{
			if (shoupai.liandan[i].mini + shoupai.liandan[i].unit> lastout.mini+lastout.unit&&shoupai.liandan[i].unit >= lastout.unit)
			{
				while (shoupai.liandan[i].mini <= lastout.mini)  //剪掉前半部分——因为最大值大于，且单位大于
				{
					judgepai judge;
					judge.mini = shoupai.liandan[i].mini;
					judge.post.push_back(shoupai.liandan[i].post[0]);
					judge.type = 1;
					judge.unit = 1;
					shoupai.liandan[i].mini += 1;
					shoupai.liandan[i].post.erase(shoupai.liandan[i].post.begin());
					shoupai.liandan[i].unit -= 1;
					shoupai.dan.push_back(judge);
				}
				while (shoupai.liandan[i].unit != lastout.unit)   //剪掉后半部分
				{
					judgepai judge;
					judge.mini = shoupai.liandan[i].mini+shoupai.liandan[i].unit-1;
					judge.post.push_back(shoupai.liandan[i].post[shoupai.liandan[i].post.size()-1]);
					judge.type = 1;
					judge.unit = 1;
					shoupai.liandan[i].post.pop_back();
					shoupai.liandan[i].unit -= 1;
					shoupai.dan.push_back(judge);
				}
				break;
			}
		}
	}
	else if (lastout.type == 6)    //连对
	{
		(*f[turn[3]])(shoupai, shuzi, vis);
		(*f[turn[0]])(shoupai, shuzi, vis);
		(*f[turn[1]])(shoupai, shuzi, vis);
		(*f[turn[2]])(shoupai, shuzi, vis);
		lianduiformdui(shoupai.dui, shoupai.liandui);
		for (int i = 0; i < shoupai.liandui.size(); i++)
		{
			if (shoupai.liandui[i].mini + shoupai.liandui[i].unit > lastout.mini + lastout.unit&&shoupai.liandui[i].unit >= lastout.unit)
			{
				while (shoupai.liandui[i].mini <= lastout.mini)  //剪掉前半部分——因为最大值大于，且单位大于
				{
					judgepai judge;
					judge.mini = shoupai.liandui[i].mini;
					judge.post.push_back(shoupai.liandui[i].post[0]);
					judge.post.push_back(shoupai.liandui[i].post[1]);
					judge.type = 2;
					judge.unit = 1;
					shoupai.liandui[i].mini += 1;
					shoupai.liandui[i].post.erase(shoupai.liandui[i].post.begin());
					shoupai.liandui[i].post.erase(shoupai.liandui[i].post.begin()+1);
					shoupai.liandui[i].unit -= 1;
					shoupai.dui.push_back(judge);
				}
				while (shoupai.liandui[i].unit != lastout.unit)   //剪掉后半部分
				{
					judgepai judge;
					judge.mini = shoupai.liandui[i].mini + shoupai.liandui[i].unit - 1;
					judge.post.push_back(shoupai.liandui[i].post[shoupai.liandui[i].post.size()-1]);
					judge.post.push_back(shoupai.liandui[i].post[shoupai.liandui[i].post.size()-2]);
					judge.type = 2;
					judge.unit = 1;
					shoupai.liandui[i].post.pop_back();
					shoupai.liandui[i].post.pop_back();
					shoupai.liandui[i].unit -= 1;
					shoupai.dui.push_back(judge);
				}
				break;
			}
		}
	}
	else if (lastout.type == 7)  //三带
	{
		(*f[turn[2]])(shoupai, shuzi, vis);
		(*f[turn[0]])(shoupai, shuzi, vis);
		(*f[turn[1]])(shoupai, shuzi, vis);
		(*f[turn[3]])(shoupai, shuzi, vis);
		lianduiformdui(shoupai.san, shoupai.liansan);
		for (int i = 0; i < shoupai.liansan.size(); i++)
		{
			if (shoupai.liansan[i].mini + shoupai.liansan[i].unit > lastout.mini + lastout.unit&&shoupai.liansan[i].unit >= lastout.unit)
			{
				while (shoupai.liansan[i].mini <= lastout.mini)  //剪掉前半部分——因为最大值大于，且单位大于
				{
					judgepai judge;
					judge.mini = shoupai.liansan[i].mini;
					judge.post.push_back(shoupai.liansan[i].post[0]);
					judge.post.push_back(shoupai.liansan[i].post[1]);
					judge.post.push_back(shoupai.liansan[i].post[2]);
					judge.type = 3;
					judge.unit = 1;
					shoupai.liansan[i].mini += 1;
					shoupai.liansan[i].post.erase(shoupai.liansan[i].post.begin());
					shoupai.liansan[i].post.erase(shoupai.liansan[i].post.begin() + 1);
					shoupai.liansan[i].post.erase(shoupai.liansan[i].post.begin() + 2);
					shoupai.liansan[i].unit -= 1;
					shoupai.san.push_back(judge);
				}
				while (shoupai.liansan[i].unit != lastout.unit)   //剪掉后半部分
				{
					judgepai judge;
					judge.mini = shoupai.liansan[i].mini + shoupai.liansan[i].unit - 1;
					judge.post.push_back(shoupai.liansan[i].post[shoupai.liansan[i].post.size() - 1]);
					judge.post.push_back(shoupai.liansan[i].post[shoupai.liansan[i].post.size() - 2]);
					judge.post.push_back(shoupai.liansan[i].post[shoupai.liansan[i].post.size() - 3]);
					judge.type = 3;
					judge.unit = 1;
					shoupai.liansan[i].post.pop_back();
					shoupai.liansan[i].post.pop_back();
					shoupai.liansan[i].post.pop_back();
					shoupai.liansan[i].unit -= 1;
					shoupai.san.push_back(judge);
				}
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			(*f[turn[i]])(shoupai, shuzi, vis);
		}
	}
	//留下单
	fundalldan(shoupai,shuzi,vis);
	//从对子中组合连对
	//lianduiformdui(shoupai.dui, shoupai.liandui);
	//从三中组合连三
	//lianduiformdui(shoupai.san, shoupai.liansan);
}
//数据处理，对于一副手牌怎么拆出最优——根据权值和手数   无非就是改变顺序   改变顺子的提取
void dateorgforper(int *shuzi, divide &shoupai, int *&vis)  //我应该在这个函数中得到权值再进行比较，得到最终的拆牌方案
{
	//初始化
	shoupai.boom.clear();
	shoupai.dan.clear();
	shoupai.dui.clear();
	shoupai.san.clear();         //对于拆牌，每次不同情况会有不同的拆牌先后顺序
	shoupai.liandan.clear();     //我应该怎样才能取得最优的结果  
	shoupai.liandui.clear();     //两个技术难点，对于顺子的拆牌怎么办 双顺三顺的组合怎么办
	shoupai.liansan.clear();
	project pro = va_nu_cmp(shuzi, vis);
	void(*f[5])(divide &shoupai, int *&shuzi, int *&vis) = { fundallshunzi,fundallsi,fundallsan,fundalldui };
	memset(vis, 0, sizeof(vis) * 20);
	for (int i = 0; i < 4; i++)
	{
		(*f[pro.order[i]])(shoupai, shuzi, vis);
	}
	fundalldan(shoupai, shuzi, vis);
	lianduiformdui(shoupai.dui, shoupai.liandui);
	connectdanordui(shoupai);  //把拆出的三都尽量带牌
	liansanformsan(shoupai.san, shoupai.liansan);
	/*fundallshunzi(shoupai, shuzi, vis);
	//再找四
	fundallsi(shoupai, shuzi, vis);
	//再找三
	fundallsan(shoupai, shuzi, vis);
	//再找二
	fundalldui(shoupai, shuzi, vis);
	//留下单
	fundalldan(shoupai, shuzi, vis);*/
	//从对子中组合连对
	//lianduiformdui(shoupai.dui, shoupai.liandui);
	//从三中组合连三
	//lianduiformdui(shoupai.san, shoupai.liansan);
	//一副牌的手数
	//shoupai.num = shoupai.liandui.size() + shoupai.liandan.size() + shoupai.boom.size() + shoupai.dui.size()+shoupai.dan.size();
	//一副牌的权值
	//shoupai.value = the_value(shoupai);
}
//找出一手牌的权值 手数 和顺序方便比较
project va_nu_cmp(int *shuzi,int *&vis)
{
	void(*f[5])(divide &shoupai, int *&shuzi, int *&vis) = { fundallshunzi,fundallsi,fundallsan,fundalldui };  //连单 四 三 二 
	divide testshoupai;
	testshoupai.num = testshoupai.value = 0;
	project pro;
	pro.num = 100; pro.value = 0;
	for(int i=0;i<=3;i++)
		for (int j = 0; j <= 3 ; j++)
		{
			if (j == i) continue;
			for (int k = 0; k <= 3; k++)
			{
				if (k == i||k==j) continue;
				for (int t = 0; t <= 3; t++)
				{
					if (t == i || t == j || t == k) continue;
					memset(vis, 0, sizeof(vis) * 17);
					testshoupai.boom.clear();
					testshoupai.dan.clear();
					testshoupai.dui.clear();
					testshoupai.san.clear();         //对于拆牌，每次不同情况会有不同的拆牌先后顺序
					testshoupai.liandan.clear();     //我应该怎样才能取得最优的结果  
					testshoupai.liandui.clear();     //两个技术难点，对于顺子的拆牌怎么办 双顺三顺的组合怎么办
					testshoupai.liansan.clear();
					(*f[i])(testshoupai, shuzi, vis);
					(*f[j])(testshoupai, shuzi, vis);
					(*f[k])(testshoupai, shuzi, vis);
					(*f[t])(testshoupai, shuzi, vis);
					fundalldan(testshoupai, shuzi, vis);
					//从对子中组合连对
					lianduiformdui(testshoupai.dui, testshoupai.liandui);
					//从三中组合连三
					lianduiformdui(testshoupai.san, testshoupai.liansan);
					testshoupai.num = testshoupai.liandui.size() + testshoupai.liandan.size() + testshoupai.boom.size() + testshoupai.dui.size() + testshoupai.dan.size();
					testshoupai.value = the_value(testshoupai);
					if (testshoupai.num<pro.num)
					{
						pro.order[0] = i;
						pro.order[1] = j;
						pro.order[2] = k;
						pro.order[3] = t;
						pro.num = testshoupai.num;
						pro.value = testshoupai.value;
					}
					else if (testshoupai.num == pro.num)
					{
						if (testshoupai.value > pro.value)
						{
							pro.order[0] = i;
							pro.order[1] = j;
							pro.order[2] = k;
							pro.order[3] = t;
							pro.num = testshoupai.num;
							pro.value = testshoupai.value;
						}
					}
				}
			}
		}
			
	return pro;
}
//计算权值的函数
int the_value(divide shoupai)
{
	int num = 0;
	//炸弹
	for (int i = 0; i < shoupai.boom.size(); i ++ )
	{
		num += 8;
	}
	//单牌
	for (int i = 0; i < shoupai.dan.size(); i++)
	{
		num += 1;
	}
	//对子
	for (int i = 0; i < shoupai.dui.size(); i++)
	{
		num += 2;
	}
	//三张
	for (int i = 0; i < shoupai.san.size(); i++)
	{
		num +=  3;
	}
	//连单
	for (int i = 0; i < shoupai.liandan.size(); i++)
	{
		num += shoupai.liandan[i].unit;
	}
	//连对
	for (int i = 0; i < shoupai.liandui.size(); i++)
	{
		num += shoupai.liandui[i].unit * 2;
	}
	//连三
	for (int i = 0; i < shoupai.liansan.size(); i++)
	{
		num += shoupai.liansan[i].unit * 3;
	}
	return num;
}
//从单中组合出连单vector<judgepai>
void liandanformdan(vector<judgepai> &dan, vector<judgepai> &liandan)    //组合顺子
{
	int post = 1;
	while (1)
	{
		judgepai judge;
		judge.mini = 0;
		judge.unit = 0;
		int num = 0;
		for (int i = post; i < dan.size(); i++)
		{
			if (dan[i].mini == dan[i - 1].mini + 1)
			{
				num++;
				if (num == 4)
				{
					judge.unit = num;
					judge.mini = dan[i - 2].mini;
					int t = 0;
					judge.post.clear();
					for (int j = i - 4; j <= i; j++)
					{
						judge.post.push_back(dan[i-4].post[0]);     //将单的位置存入连单中
						dan.erase(dan.begin() +( i-4));
					}
				}
				else if (num > 4)
				{
					judge.unit = num;
					judge.post.push_back(dan[i].post[0]);
					dan.erase(dan.begin() + i);
				}
			}
			else
			{
				if (num >= 4)
				{
					post = i + 1;
					break;
				}
				else
					num = 0;
			}
		}
		if (judge.mini != 0)
		{
			if (num == 0)
				liandan.push_back(judge);
			else
			{
				liandan.push_back(judge);
				break;
			}
		}
		else
			break;
	}
}
//从对子中组合出连对vector<judgepai>
void lianduiformdui(vector<judgepai> &dui, vector<judgepai> &liandui)
{
	int post = 1;
	while (1)
	{
		judgepai judge;
		judge.mini = 0;
		judge.unit = 0;
		int num = 0;
		for (int i = post; i <dui.size(); i++)
		{
			if (dui[i].mini == dui[i - 1].mini + 1)
			{
				num++;
				if (num == 2)
				{
					judge.unit = num;
					judge.mini = dui[i - 2].mini;
					int t = 0;
					judge.post.clear();
					for (int j = i - 2; j <= i; j++)
					{
						judge.post.push_back(dui[i-2].post[0]);     //将对子的位置存入连对中
						judge.post.push_back(dui[i-2].post[1]);
						dui.erase(dui.begin() +( i-2));
					}
				}
				else if (num > 2)
				{
					judge.unit = num;
					judge.post.push_back(dui[i].post[0]);
					judge.post.push_back(dui[i].post[1]);
					dui.erase(dui.begin() + i);
				}
			}
			else
			{
				if (num >= 2)
				{
					post = i + 1;
					break;
				}
				else
					num = 0;
			}
		}
		if (judge.mini != 0)
		{
			if (num == 0)
				liandui.push_back(judge);
			else
			{
				liandui.push_back(judge);
				break;
			}
	}
	else
		break;
	}
}
//从三中组合出连三vector<judgepai>
void liansanformsan(vector<judgepai> &san, vector<judgepai> &liansan)
{
	post = 1;
	while (1)
	{
		judgepai judge;
		judge.mini = 0;
		judge.unit = 0;
		int num = 0;
		for (int i = post; i < san.size(); i++)
		{
			if (san[i].mini == san[i - 1].mini + 1)
			{
				num++;
				if (num == 1)
				{
					judge.unit = num;
					judge.mini = san[i - 1].mini;
					int t = 0;
					judge.post.clear();
					for (int j = i - 1; j <= i; j++)
					{
						for (int q = 0; q<san[i - 1].post.size(); q++)
						{
							judge.post.push_back(san[i - 1].post[q]);
						}
						/*judge.post.push_back(san[i-1].post[0]);
						judge.post.push_back(san[i-1].post[1]);
						judge.post.push_back(san[i-1].post[2]);*/
						san.erase(san.begin() + i - 1);
					}
				}
				else if (num > 1)
				{
					judge.unit = num;
					for (int q = 0; san[i - 1].post[q] > 0; q++)
					{
						judge.post.push_back(san[i].post[q]);
					}
					/*judge.post.push_back(san[i].post[0]);
					judge.post.push_back(san[i].post[1]);
					judge.post.push_back(san[i].post[2]);*/
					san.erase(san.begin() + i);
				}
			}
			else
			{
				if (num >= 1)
				{
					post = i + 1;
					break;
				}
				else
					num = 0;
			}
		}
		if (judge.mini != 0)
		{
			if (num == 0)
				liansan.push_back(judge);
			else
			{
				liansan.push_back(judge);
				break;
			}
		}
		else
			break;
	}
}
//把这个函数放在拆3之后这样的话只要拆完3之后在组合一下，修改三中组合连三的代码
//出三张的时候接单或者接对
void connectdanordui(divide &shoupai)
{
	for (int i = 0; i < shoupai.san.size(); i++)
	{
		if (shoupai.dan.size() > 0)
		{
			shoupai.san[i].post.push_back(shoupai.dan[0].post[0]);
			shoupai.dan.erase(shoupai.dan.begin());
		}
		else if (shoupai.dui.size() > 0)
		{
			shoupai.san[i].post.push_back(shoupai.dui[0].post[0]);
			shoupai.san[i].post.push_back(shoupai.dui[0].post[1]);
			shoupai.dui.erase(shoupai.dui.begin());
		}
	}
}
//将权值和手数组合的最优牌封装好
//一来的初始牌型是由权值和手数组合而成的最优解——初始牌是拆好的一副完整手牌
//后来的每一次接牌前会从新拆一遍牌——根据上家的敌友关系拆牌
//如果是敌根据出牌拆牌
//如果是友为最优拆牌
//方案 如果地主出牌则不补  //如果队友出牌则先补
//从连对中拆出对vector<judgepai> 返回对子   两种情况要用 1：接对手牌的时候可能拆大对子    2：打三带一对的时候没对子的时候  ——拆小对子
//寻找数组中四 三 二 一 的个数
judgepai found(int type,int *shuzi,int *&vis)
{
	judgepai judge;
	judge.mini = 0;
	int num = 0;
	int count = 0;
	for (int i = 1; shuzi[i] != 0; i++)
	{
		if (shuzi[i] == shuzi[i - 1]&&!vis[i]&&!vis[i-1])
		{
			num++;
		}
		else
			num = 0;
		//找到一个就行
		if (num == type - 1&&!vis[i])
		{
			judge.mini = shuzi[i];
			judge.post.clear();
			for (int j = 0; j < type; j++)
			{
				vis[i - j] = 1;
				judge.post.push_back(i-j);
			}
			break;
		}
	}
	if (judge.mini > 0)
	{
		judge.type = type;
		judge.unit = 1;
	}
	return judge;
}
//找顺子函数
judgepai foundsunzi(int type, int *shuzi, int *&vis)
{
	judgepai judge;
	judge.mini = 0;
	int num = 0;
	int charge[15];
	int count = 0;
	int flag = 1;
	int i = 0;  //遍历shuzi数组
	int t = 0;  //
	judge.post.clear();
	while(shuzi[i] != 0&&shuzi[i]<13)
	{
		if (vis[i])
		{
			i++;
			continue;
		}
		flag = 1;
		charge[t++] = i;        //保存顺子的位置
		vis[i] = 1;            //开头元素被遍历过
		judge.post.push_back(i);
		for(int j=i+1;j<=i+3;j++)
		{
			//如果在后面3个元素中找到了比他大一的元素  1：计数 2：保存位置 3：改变标志 4：记录是否背遍历过
			if (shuzi[i] == shuzi[j]-1 && !vis[j]&&shuzi[j]<13)
			{
				num++;
				if (num == type - 1)
					break;
				flag = 0;
				i = j;
				break;
			}
		}
		//如果后面三个元素中都没有找到比他大一的元素 则寻找中断，全部初始化
		if (flag)
		{
			if (num == type - 1)
			{
				break;
			}
			else
			{
				num = 0;
				flag = 1;
				judge.post.clear();
				for (int q = 0; q < t; q++)
				{
					vis[charge[q]] = 0;
				}
				memset(charge, 0, sizeof(charge));
				t = 0;
				i++;
			}
		}
	}
	if (num ==type-1)
	{
		judge.mini = shuzi[judge.post[0]];
		judge.type = type;
		judge.unit = num;
	}
	return judge;
}
//找到所有顺子
void fundallshunzi(divide &shoupai,int *&shuzi,int *&vis)
{
	//先找顺子
	while (1)
	{                            //先比手数再比权值  
		judgepai judge = foundsunzi(5, shuzi, vis);
		if (judge.mini != 0)
		{
			shoupai.liandan.push_back(judge);
		}
		else
			break;
	}
	//其他剩余牌中能否与其组合
	int i = 0;  //遍历shuzi数组
	while (shuzi[i] != 0 && shuzi[i]<13)
	{
		if (vis[i])
		{
			i++;
			continue;
		}
		for (int j = 0; j < shoupai.liandan.size(); j++)
		{
			//如果此数字可以插到顺子后则插过去  插过去后 UNITE+1 post推进
			if (shuzi[i] == shoupai.liandan[j].mini+ shoupai.liandan[j].unit)
			{
				shoupai.liandan[j].post.push_back(i);
				shoupai.liandan[j].unit += 1;
				vis[i] = 1;
				break;
			}
		}
		i++;
	}
	//是否可以首尾无缝连接
	if (shoupai.liandan.size() > 2)
	{
		if (shoupai.liandan[1].mini == shoupai.liandan[0].mini + shoupai.liandan[0].unit)
		{
			for (int i = 0; i < shoupai.liandan[1].post.size(); i++)
			{
				shoupai.liandan[0].post.push_back(shoupai.liandan[1].post[i]);
			}
			shoupai.liandan[0].unit += shoupai.liandan[1].unit;
			shoupai.liandan.pop_back();
		}
	}
}
//找到所有四
void fundallsi(divide &shoupai, int *&shuzi, int *&vis)
{
	while (1)
	{
		judgepai judge = found(4, shuzi, vis);
		if (judge.mini != 0)
		{
			shoupai.boom.push_back(judge);
		}
		else
			break;
	}
}
//找到所有三
void fundallsan(divide &shoupai, int *&shuzi, int *&vis)
{
	while (1)
	{
		judgepai judge = found(3, shuzi, vis);
		if (judge.mini != 0)
		{
			shoupai.san.push_back(judge);
		}
		else
			break;
	}
}
//找到所有二
void fundalldui(divide &shoupai, int *&shuzi, int *&vis)
{
	while (1)
	{
		judgepai judge = found(2, shuzi, vis);
		if (judge.mini != 0 && judge.mini != 14)
		{
			shoupai.dui.push_back(judge);
		}
		else if (judge.mini == 14)
		{
			judge.type = 14;
			shoupai.boom.push_back(judge);
		}
		else
			break;
	}
}
//找到所有单
void fundalldan(divide &shoupai, int *&shuzi, int *&vis)
{
	while (1)
	{
		judgepai judge;
		judge.mini = 0;
		for (int i = 0; shuzi[i] != 0; i++)
		{
			if (!vis[i])
			{
				judge.mini = shuzi[i];
				judge.unit = 1;
				judge.post.push_back(i);
				vis[i] = 1;
				break;
			}
		}
		if (judge.mini != 0)
		{
			shoupai.dan.push_back(judge);
		}
		else
			break;
	}
}
//对于一手发牌的数据抽象
void abstract()
{
	for (int i = 1; i <= 3; i++)
	{
		cut(head[i],shoupai[i]);
	}
}
//画出三副牌
void Draw()
{
	//cleardevice();

	loadimage(NULL, "timg.jpg", 800, 600);
	if (!on)
		fenshu();
	else
	{
		drawdizhupai();
		if (mymenu.man_machine)  //如果是人机对战版
		{
			if (player == 1)
				outandno();
		}
		else
		{
			outandno();
		}
		
	}
	//BeginBatchDraw();
	if (mymenu.man_machine)
		Draw_per_ma();
	else
		Draw_per();
	//FlushBatchDraw();
	//上家出牌
	/*for (int i = 0; i< lastnum; i++)
	{
		int num = (last[i].shuzi - 1) * 4 + last[i].huase;
		IMAGE im;
		loadimage(&im, name[num - 1], 80, 100);
		if(player==2)
			putimage(380 + i * 20, 340, &im);
		else if (player == 3)
			putimage(650 + i * 20, 230, &im);
		else 
			putimage(100+i*20, 230, &im);
	}*/
	/*IMAGE image;
	loadimage(&image, "22.jpg", 30, 30);
	post = player;
	switch (post)
	{
	case 1:
		putimage(380, 340, &image);
		break;
	case 2:
		putimage(650, 230, &image);
		break;
	case 3:
		putimage(100, 230, &image);
		break;
	}*/

	if (player != 1&&mymenu.man_machine)
		Sleep(1000);
	else
		Sleep(100);
	//cleardevice();
}
//人人对战三副牌
void Draw_per()
{
	pai *temp1 = head[1];
	pai *temp2 = head[2];
	pai *temp3 = head[3];
	int t1 = 1;
	int t2 = 1;
	int t3 = 1;
	//第一副牌 —主牌
	while (temp1 != NULL)
	{
		int num = (temp1->shuzi - 1) * 4 + temp1->huase;
		if (vis1[t1])
		{
			putimage(150 + (t1 - 1) * 20, 430, &mypai[num]);
		}
		else
			putimage(150 + (t1 - 1) * 20, 450, &mypai[num]);
		t1++;
		temp1 = temp1->next;
	}
	// 左牌
	while (temp3 != NULL)
	{
		int num = (temp3->shuzi - 1) * 4 + temp3->huase;
		if (vis3[t3])
		{
			putimage(30, 50 + (t3 - 1) * 20, &mypai[num]);
		}
		else
			putimage(10, 50 + (t3 - 1) * 20, &mypai[num]);
		t3++;
		temp3 = temp3->next;
	}
	// 右牌
	while (temp2 != NULL)
	{
		int num = (temp2->shuzi - 1) * 4 + temp2->huase;
		if (vis2[t2])
		{
			putimage(690, 50 + (t2 - 1) * 20, &mypai[num]);
		}
		else
			putimage(710, 50 + (t2 - 1) * 20, &mypai[num]);
		t2++;
		temp2 = temp2->next;
	}
}
//人机对战三副牌
void Draw_per_ma()
{
	pai *temp1 = head[1];
	pai *temp2 = head[2];
	pai *temp3 = head[3];
	int t1 = 1;
	int t2 = 1;
	int t3 = 1;
	IMAGE ima;
	loadimage(&ima,"back.jpg", 80, 100);
	//第一副牌 —主牌
	while (temp1 != NULL)
	{
		int num = (temp1->shuzi - 1) * 4 + temp1->huase;
		if (vis1[t1])
		{
			putimage(150 + (t1 - 1) * 20, 430, &mypai[num]);
		}
		else
			putimage(150 + (t1 - 1) * 20, 450, &mypai[num]);
		t1++;
		temp1 = temp1->next;
	}
	// 左牌
	while (temp3 != NULL)
	{
		if (vis3[t3])
		{
			putimage(30, 50 + (t3 - 1) * 20, &ima);
		}
		else
			putimage(10, 50 + (t3 - 1) * 20, &ima);
		t3++;
		temp3 = temp3->next;
	}
	// 右牌
	while (temp2 != NULL)
	{
		if (vis2[t2])
		{
			putimage(690, 50 + (t2 - 1) * 20, &ima);
		}
		else
			putimage(710, 50 + (t2 - 1) * 20, &ima);
		t2++;
		temp2 = temp2->next;
	}
}
//发牌界面
void freshofpuk()
{
	pai *temp1 = head[1];
	pai *temp2 = head[2];
	pai *temp3 = head[3];
	int t1 = 1;
	int t2 = 1;
	int t3 = 1;
	IMAGE ima;
	loadimage(&ima, "back.jpg", 80, 100);
	while (temp1 != NULL||temp2 != NULL||temp3!=NULL)
	{
		int num1 = (temp1->shuzi - 1) * 4 + temp1->huase;
		int num2 = (temp2->shuzi - 1) * 4 + temp2->huase;
		int num3 = (temp3->shuzi - 1) * 4 + temp3->huase;
		putimage(150 + (t1 - 1) * 20, 450, &mypai[num1]);
		if (mymenu.man_machine)
		{
			putimage(710, 50 + (t2 - 1) * 20, &ima);
			putimage(10, 50 + (t3 - 1) * 20, &ima);
		}
		else
		{
			putimage(710, 50 + (t2 - 1) * 20, &mypai[num2]);
			putimage(10, 50 + (t3 - 1) * 20, &mypai[num3]);
		}
		t1++,t2++,t3++;
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp3 = temp3->next;
		PlaySound("出牌.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
		Sleep(100);
	}
}
//画出上家出牌
void Drawlastout()
{
	//上家出牌
	for (int i = 0; i< nownum; i++)
	{
		int num = (now[i].shuzi - 1) * 4 + now[i].huase;
		IMAGE im;
		loadimage(&im, name[num - 1], 80, 100);
		if (player == 1)
			putimage(380-(nownum*10) + i * 20, 340, &im);
		else if (player == 2)
			putimage(620- (nownum * 10) + i * 20, 230, &im);
		else
			putimage(100 + i * 20, 230, &im);
	}
	Sleep(800);
}
//出牌与不要
void outandno()
{
	IMAGE ima1, ima2,ima3;
	loadimage(&ima1, "click//出牌.jpg", 80, 30);
	loadimage(&ima2, "click//不出.jpg", 80, 30);
	loadimage(&ima3, "click//提示.jpg", 80, 30);
	putimage(190, 400, &ima1);
	putimage(360, 400, &ima3);
	putimage(530, 400, &ima2);
}
//打牌   //就是删除该结点测试版
void putpai(int *&vis, int *&put, pai *&head, int peo)
{
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		//点击牌
		if (m.y >= 450 && m.y <= 550 && m.x >= 150 && m.x <= 550 && m.mkLButton == true && peo == 1)
		{
			int q = (m.x - 150 + 20) / 20;
			if (vis1[q] == 0)
				vis1[q] = 1;
			else
				vis1[q] = 0;
			if (put1[q] == 0)
				put1[q] = 1;
			else
				put1[q] = 0;
			break;
		}
		if (m.y >= 50 && m.y <= 450 && m.x >= 710 && m.x <= 790 && m.mkLButton == true && peo == 2)
		{
			int q = (m.y - 50 + 20) / 20;
			if (vis2[q] == 0)
				vis2[q] = 1;
			else
				vis2[q] = 0;
			if (put2[q] == 0)
				put2[q] = 1;
			else
				put2[q] = 0;
			break;
		}

		if (m.y >= 50 && m.y <= 450 && m.x >= 10 && m.x <= 90 && m.mkLButton == true && peo == 3)
		{
			int q = (m.y - 50 + 20) / 20;
			if (vis3[q] == 0)
				vis3[q] = 1;
			else
				vis3[q] = 0;
			if (put3[q] == 0)
				put3[q] = 1;
			else
				put3[q] = 0;
			break;
		}
		//不要
		else if (m.y >= 400 && m.y <= 430 && m.x >= 530 && m.x <= 610 && m.mkLButton == true)
		{
			no++;
			if (dont())
			{
				memset(vis, 0, sizeof(vis) * 20);
				memset(put, 0, sizeof(put) * 20);
				flag = 0;
				break;
			}
			else
			{
				nofalse();
				break;
			}
		}
		//提示
		else if (m.y >= 400 && m.y <= 430 && m.x >= 360 && m.x <= 440 && m.mkLButton == true)
		{
			match(shoupai[peo],vis,put);
			break;
		}
		//出牌
		else if (m.y >= 400 && m.y <= 430 && m.x >= 190 && m.x <= 270 && m.mkLButton == true)
		{
			int *q = put;
			if (judge(q, head))
			{
				no = 0;
				deletenode(head, put);
				memset(vis, 0, sizeof(vis) * 20);
				memset(put, 0, sizeof(put) * 20);
				flag = 0;
				break;
			}
			else
			{
				nofalse();
				break;
			}
	}
		}
}
//自动出牌
void autoputpai(int *put, pai *&head, int peo)    //其实就是根据匹配手牌的put改变
{
	//先手出牌的一般拆牌原则    —— 手数最小 权值最大
	//先手出牌   —— 一般原则从小到大   1：自己是不是地主   如果是地主偏家手上还剩几张牌   如果是偏家地主手上还剩几张牌
	if (last[0].shuzi == 0)
	{
		autoout(shoupai[player], put);  //自动出牌
		readinnow(head, put);     //出完牌之后的后续处理工作
		no = 0;
		deletenode(head, put);
		memset(put, 0, sizeof(put) * 20);
		flag = 0;
	}
	//后手接牌     1：上家出牌是地主还是对友    如果是地主一定得接  如果是队友接不到就不接
	else if (last[0].shuzi!=0)
	{
		if (match_for_autoout(shoupai[player], put))
		{
			readinnow(head, put);
			no = 0;
			deletenode(head, put);
			memset(put, 0, sizeof(put) * 20);
			flag = 0;
		}
		else
		{
			PlaySound("pass.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
			no_for_auto(put);
		}
	}
}
//对于自动出牌    1：下家是队友还是对手 2：本次接牌是对手出牌还是队友出牌 3:对手是否报单 4：队友是否报单 5:对手出牌还是队友出牌

//把所选牌读入当前牌
void readinnow(pai *head,int *put)
{
	//把出牌读入当前牌
	pai *temp = head;
	int t = 1;
	while (temp)
	{
		if (put[t])
		{
			now[nownum].huase = temp->huase;
			now[nownum].shuzi = temp->shuzi;
			nownum++;
		}
		temp = temp->next;
		t++;
	}
	sort(now, now + nownum, cmp);
	judgepai *situa = basicrule(now);
	lastout.type = situa->type;
	lastout.mini = situa->mini;        //后手出牌的后续处理
	lastout.unit = situa->unit;
	Drawlastout();
	change();
}
//没有匹配牌型只能不要
void no_for_auto(int *put)
{
	no++;
	if (no >= 2)
	{
		memset(last, 0, sizeof(last));
		lastout.mini = 0;
	}
	memset(put, 0, sizeof(put) * 20);
	flag = 0;
}
//出牌——从链表中删除结点
void deletenode(pai *&head,int *put)
{
	pai *temp = head;
	pai *q = head;
	int t = 1;
	while (put[t] && head)
	{
		q = head;
		head = head->next;
		delete q;
		t++;
	}
	t++;
	if (head == NULL)
	{
		win = 0;
		winer_print();
	}
	else
	{
		pai *ptemp = head;
		pai *p = head->next;
		while (1)
		{
			temp = p;
			if (temp == NULL)
				break;
			p = temp->next;
			if (put[t])
			{
				q = temp;
				ptemp->next = temp->next;
				delete q;
			}
			else
			{
				ptemp = ptemp->next;
			}
			t++;
		}
	}
}
//针对不要的判断
bool dont()
{
	if (no > 2 || last[0].shuzi == 0)
	{
		memset(last, 0, sizeof(last));
		lastout.mini = 0;
		no--;
		return false;
	}
	else if (no == 2)
	{
		memset(last, 0, sizeof(last));
		lastout.mini = 0;
		return true;
	}
	else
		return true;
}
//不要错误
void nofalse()
{
	IMAGE ima;
	loadimage(&ima, "baogao.jpg", 200, 100);
	while (1)
	{
		putimage(300, 300, &ima);
		Sleep(500);
		break;
	}
}
//牌的转换
void change()
{
	//把当前牌变成上次牌
	memset(last, 0, sizeof(last));
	for (int i = 0; i < nownum; i++)
	{
		last[i].huase = now[i].huase;
		last[i].shuzi = now[i].shuzi;
	}
	memset(now, 0, sizeof(now));
	lastnum = nownum;
	nownum = 0;
}
//胜利打印
void winer_print()
{
	IMAGE ima;
	loadimage(&ima, "timg3.jpg", 200, 100);
	while (1)
	{
		putimage(300, 200, &ima);
		Sleep(500);
		break;
	}
}
//胜利判断
bool winner_judge()
{
	if (win == 1)
		return true;
	else
		return false;
}
//每次循环玩家
void round()
{
	flag = 1;
	if (shoupai[player].dan.size() == 1 && shoupai[player].num == 1)
	{
		if (player == people)      //地主报单  农民更新
		{
			for (int i = 1; i <= 3; i++)
			{
				if (i != player)
					prin[i].post_sin_ene = 1;
			}
		}
		else
			prin[people].post_sin_ene = 1;     //农民报单 地主更新
	}

	if (people == player)
		prin[(player + 4) % 3].the_ene = 1;
	else
	{
		if (1 + (player % 3) == people)
			prin[people].the_ene = 1;
	}
	player++;
	if (player > 3) player = 1;
	cut(head[player], shoupai[player]);
}
//结束单轮出牌
bool over_judge()
{
	if (flag == 1)
		return true;
	else
		return false;
}
//叫地主和抢地主
//(shuzi-1)*4+huase=牌的序号
bool judge(int puts[17], pai *head)
{
	//把出牌读入当前牌
	pai *temp = head;
	int t = 1;
	while (temp)
	{
		if (puts[t])
		{
			now[nownum].huase = temp->huase;
			now[nownum].shuzi = temp->shuzi;
			nownum++;
		}
		temp = temp->next;
		t++;
	}
	sort(now, now + nownum, cmp);
	//先手出牌
	if (last[0].shuzi == 0)
	{
		judgepai *situa = basicrule(now);
		if (situa->type > 0)
		{
			Drawlastout();
			change();
			lastout.type = situa->type;
			lastout.mini = situa->mini;
			lastout.unit = situa->unit;
			return true;
		}
		else
		{
			memset(now, 0, sizeof(now));
			nownum = 0;
			return false;
		}
	}
	//后手接牌
	else if (replyrule(now))
	{
		Drawlastout();
		change();
		return true;
	}
	//出牌错误
	else
	{
		memset(now, 0, sizeof(now));
		nownum = 0;
		return false;
	}
}
//判断对子三张和四张的个数
judgepai* count(outpai *now,int shuzi)
{
	judgepai *judge = new judgepai;
	judge->mini = 0;
	int num = 0;
	int count = 0;
	for (int i = 1; now[i].shuzi != 0; i++)
	{
		if (now[i].shuzi == now[i - 1].shuzi)
		{
			num++;
		}
		else
			num = 0;
		if (num == shuzi-1) 
			count++;
		else if (num == shuzi)
		{
			count--;
			if (judge->mini > 0)
				judge->mini = 0;
		}
		if (count == 1&&judge->mini==0)
			judge->mini = now[i].shuzi;
	}
	judge->type = 0;
	judge->unit = count;
	return judge;
}
//单牌——1
bool isdanpai(outpai *now)
{
	if (now[0].shuzi > 0 && now[1].shuzi == 0)
		return true;
	else
		return false;
}
//对子——2
bool isduizi(outpai *now)
{
	if (now[0].shuzi == now[1].shuzi&&now[2].shuzi == 0 && now[0].shuzi !=14&&nownum==2)
		return true;
	else
		return false;
}
//纯三——3
bool ispuresan(outpai *now)
{
	judgepai *judge = count(now, 3);
	if (judge->unit==1 && nownum == 3)
		return true;
	else
		return false;
}
//炸弹——4
bool isboom(outpai *now)
{
	judgepai *judge4 = count(now, 4);
	if (judge4->unit == 1 && nownum == 4)
		return true;
	else if (nownum == 2 && now[0].shuzi == now[1].shuzi&&now[0].shuzi == 14)
		return true;
	else
		return false;
}
//连单——5
bool issunzi(outpai *now)
{
	int num = 0;
	for (int i = 1; now[i].shuzi != 0; i++)
	{
		if (now[i].shuzi == now[i - 1].shuzi + 1)
			num++;
	}
	if (num == nownum - 1 && num >= 4 && now[nownum - 1].shuzi<13)
		return true;
	else
		return false;
}
//连对——6
bool isliandui(outpai *now)
{
	int num = 0;
	for (int i = 1; now[i].shuzi != 0; i = i + 2)
	{
		if (now[i].shuzi == now[i - 1].shuzi)
			num++;
		else
			num = 0;
	}
	if (num >= 3)
		return true;
	else
		return false;
}
//连三——7
bool isliansan(outpai *now)
{
	judgepai *judge3 = count(now, 3);
	judgepai *judge2 = count(now, 2);
	//纯连三
	if (judge3->unit * 3 == nownum&&nownum > 0)
		return true;
	//带一
	else if (judge3->unit >= nownum / 4 && nownum % 4 == 0 && judge3->unit>0)
		return true;
	//带二
	else if (judge3->unit == judge2->unit && judge3->unit * 5 == nownum&&nownum > 0)
		return true;
	else
		return false;
}
//连四——8
bool isliansi(outpai *now)
{
	judgepai *judge4 = count(now, 4);
	judgepai *judge2 = count(now, 2);
	//纯连四
	if (judge4->unit * 4 == nownum&&judge4->unit>1)
		return true;
	//带二
	else if (judge4->unit >= nownum / 6 && nownum % 6 == 0&&nownum>0)
		return true;
	//带二对
	else if (judge4->unit * 2 == judge2->unit  && judge4->unit * 8 == nownum&&nownum>0)
		return true;
	else
		return false;
}
//针对出牌判断—基本出牌
judgepai* basicrule(outpai *no)
{
	judgepai *situa;
	situa = new judgepai;
	//单牌——1
	if (isdanpai(no))
	{
		situa->type = 1;
		situa->unit = 1;
		if (no[0].shuzi == 14)
			situa->mini = no[0].shuzi + no[0].huase;
		else
			situa->mini = no[0].shuzi;
	}
	//对子——2
	else if (isduizi(no))
	{
		situa->type = 2;
		situa->unit = 1;
		situa->mini = no[0].shuzi;
	}
	//纯三——3
	else if (ispuresan(no))
	{
		situa->type = 3;
		situa->unit = 1;
		situa->mini = no[0].shuzi;
	}
	//炸弹——4
	else if (isboom(no))
	{
		situa->type = 4;
		situa->unit = 1;
		situa->mini = no[0].shuzi;
	}
	//连单——5
	else if (issunzi(no))
	{
		situa->type = 5;
		situa->unit = nownum;
		situa->mini = no[0].shuzi;
	}
	//连对——6
	else if (isliandui(no))
	{
		situa->type = 6;
		situa->unit = nownum/2;
		situa->mini = no[2].shuzi;
	}
	//连三——7
	else if (isliansan(no))
	{
		judgepai* judge = count(no, 3);
		situa->type = 7;
		situa->unit = judge->unit;
		situa->mini = judge->mini;
	}
	//连四——8
	else if (isliansi(no))
	{
		judgepai* judge = count(no, 4);
		situa->type = 8;
		situa->unit = judge->unit;
		situa->mini = judge->mini;
	}
	//都不是
	else
	{
		situa->type = 0;
		situa->mini = 0;
		situa->unit = 0;
	}
	return situa;
}
//出牌判断——接牌
bool replyrule(outpai *n)
{
	judgepai *no=basicrule(n);
	if (nownum==lastnum&&lastout.type == no->type&&no->mini > lastout.mini)
	{
		lastout.type = no->type;
		lastout.mini = no->mini;
		lastout.unit = no->unit;
		return true;
	}
	else if (no->type == 4&& lastout.type!=4)
	{
		lastout.type = no->type;
		lastout.mini = no->mini;
		lastout.unit = no->unit;
		return true;
	}
	else if (no->type == 4&& no->mini == 14)
	{
		lastout.type = no->type;
		lastout.mini = no->mini;
		lastout.unit = no->unit;
		return true;
	}
	else
		return false;
}
//获得地主牌
void getdizhupa(pai *&head,pai *&tail)
{
	for (int i = 0; i <= 2; i++)
	{
		pai *temp = new pai;
		temp->huase = dizhu[i].huase;
		temp->shuzi = dizhu[i].shuzi;
		if (temp->shuzi < head->shuzi)
		{
			temp->next = head;
			head = temp;
			continue;
		}
		else if (temp->shuzi == head->shuzi&&temp->huase < head->huase)
		{
			temp->next = head;
			head = temp;
			continue;
		}
		else if (temp->shuzi > tail->shuzi)
		{
			tail->next = temp;
			tail = temp;
			continue;
		}
		else if (temp->shuzi == tail->shuzi&&temp->huase > tail->huase)
		{
			tail->next = temp;
			tail = temp;
			continue;
		}
		pai *ptemp = head;
		pai *qtemp = ptemp->next;
		while (qtemp)
		{
			if (temp->shuzi < qtemp->shuzi)
			{
				ptemp->next = temp;
				temp->next = qtemp;
				break;
			}
			else if (temp->shuzi == qtemp->shuzi&&temp->huase < qtemp->huase)
			{
				ptemp->next = temp;
				temp->next = qtemp;
				break;
			}
			qtemp = qtemp->next;
			ptemp = ptemp->next;
		}
	}
	tail->next= NULL;
}
//叫分函数
void callpoint()
{
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		//一分
		if (m.y >= 390 && m.y <= 420 && m.x >= 200 && m.x <= 280 && m.mkLButton == true)
		{
			if (point < 1)
			{
				people = player;
				point = 1;
				over = 1;
				PlaySound("一分.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
				break;
			}
			else
			{
				nofalse();
				break;
			}
		}
		//两分
		else if (m.y >= 390 && m.y <= 420 && m.x >= 300 && m.x <= 380 && m.mkLButton == true)
		{
			if (point < 2)
			{
				people = player;
				point = 2;
				over = 1;
				PlaySound("二分.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
				break;
			}
			else
			{
				nofalse();
				break;
			}
		}
		//三分
		else if (m.y >= 390 && m.y <= 420 && m.x >= 400 && m.x <= 480 && m.mkLButton == true)
		{
			three = 1;
			people = player;
			over = 1;
			PlaySound("三分.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
			break;
		}
		//不叫
		else if (m.y >= 390 && m.y <= 420 && m.x >= 500 && m.x <= 580 && m.mkLButton == true)
		{
			over = 1;
			break;
		}
	}
}
//叫分画面
void fenshu()
{
	IMAGE ima1, ima2, ima3, ima4,ima5;
	loadimage(&ima1, "click//一倍.jpg", 80, 30);
	loadimage(&ima2, "click//二倍.jpg", 80, 30);
	loadimage(&ima3, "click//三倍.jpg", 80, 30);
	loadimage(&ima4, "click//不抢.jpg", 80, 30);
	putimage(200, 390, &ima1);
	putimage(300, 390, &ima2);
	putimage(400, 390, &ima3);
	putimage(500, 390, &ima4);
}
//画出地主牌
void drawdizhupai()
{
	for (int i = 52; i<= 54; i++)
	{
		IMAGE im;
		loadimage(&im, name[a[i] - 1], 80, 100);
		putimage(320 + (i-52) * 20, 50, &im);
	}
}
//销毁链表
void deletelink(pai *&head)
{
	pai *temp = head;
	while (temp)
	{
		pai *ptemp = temp;
		temp = temp->next;
		delete ptemp;
	}
	head = NULL;
}
//叫地主
void calldizhu()
{
	int count = 0;   //叫分次数——只能叫三次
	while (1)
	{
		cut(head[player],shoupai[player]);
		over = 0;
		//叫地主
		while (!over)
		{
			Draw();     //画出界面
			if (player == 1)
				callpoint();//叫分
			else
			{
				if (mymenu.man_machine)
					autocallpoint(head[player], shoupai[player]); //自动叫分
				else
					callpoint();//手动叫分
			}
			count++;
			if (three||count >= 3)
				break;
			Sleep(200);
		}
		player++;
		if (player > 3)   //循环叫地主
			player = 1;
		if (three||(count>=3&&people>0))   //得到地主牌
		{
			on = 1;    //结束叫地主
			getdizhupa(head[people],tail[people]);
			break;
		}
		else if(count>=3&&people==0)  //没人叫地主从新发牌
		{
			for (int i = 1; i <= 3; i++)
				deletelink(head[i]);
			form();
			link();
			count = 0;
		}
		Sleep(200);
	}
	player = people;  //叫地主结束
	PlaySound("抢到地主.wav", NULL, SND_FILENAME | SND_ASYNC); //播放歌曲
	//abstract();//根据初始化链表拆牌
}
//自动叫地主
void autocallpoint(pai *head,divide shoupai)
{
	//权值
	int value = 0;
	for (int i = 0; i < shoupai.boom.size(); i++)   //炸弹
	{
		value += 4;
	}
	pai *post = head;
	while (post)
	{
		if (post->shuzi == 13)
			value += 2;
		else if (post->shuzi == 14)
			value += 3;
		post = post->next;
	}
	//一分
	if (value>=4&&value<6)
	{
		if (point < 1)
		{
			people = player;
			point = 1;
			over = 1;
		}
		else
		{
			over = 1;
		}
	}
	//两分
	else if (value<8&&value>=6)
	{
		if (point < 2)
		{
			people = player;
			point = 2;
			over = 1;
		}
		else
		{
			over = 1;
		}
	}
	//三分
	else if (value>=8)
	{
		three = 1;
		people = player;
		over = 1;
	}
	//不叫
	else if (value<4)
	{
		over = 1;
	}
}
//匹配牌——用于提示功能
void match(divide shoupai,int *&vis,int *&put)
{
	//如果是单
	if (lastout.type == 1)
	{
		if (shoupai.dan.size() > 0)
		{
			for (int i = 0; i < shoupai.dan.size(); i++)
			{
				if (shoupai.dan[i].mini > lastout.mini)
				{
					output(vis,put, shoupai.dan[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
		output(vis, put, shoupai.boom[0].post);
	}
	//如果是对
	else if (lastout.type == 2)
	{
		if (shoupai.dui.size() > 0)
		{
			for (int i = 0; i < shoupai.dui.size(); i++)
			{
				if (shoupai.dui[i].mini > lastout.mini)
				{
					output(vis,  put, shoupai.dui[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
			output(vis, put, shoupai.boom[0].post);
	}
	//如果是三
	else if (lastout.type == 3)
	{
		if (shoupai.san.size() > 0)
		{
			for (int i = 0; i < shoupai.san.size(); i++)
			{
				if (shoupai.san[i].mini > lastout.mini)
				{
					output(vis, put, shoupai.san[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
			output(vis, put, shoupai.boom[0].post);
	}
	//如果是炸弹
	else if (lastout.type == 4)
	{
		if (shoupai.boom.size() > 0)
		{
			for (int i = 0; i < shoupai.boom.size(); i++)
			{
				if (shoupai.boom[i].mini > lastout.mini)
				{
					output(vis, put, shoupai.boom[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
			output(vis, put, shoupai.boom[0].post);
	}
	//如果是连单
	else if (lastout.type == 5)
	{
		if (shoupai.liandan.size() > 0)
		{
			for (int i = 0; i < shoupai.liandan.size(); i++)
			{
				if (shoupai.liandan[i].mini > lastout.mini)
				{
					output(vis, put, shoupai.liandan[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
			output(vis, put, shoupai.boom[0].post);
	}
	//如果是连双
	else if (lastout.type == 6)
	{
		if (shoupai.liandui.size() > 0)
		{
			for (int i = 0; i < shoupai.liandui.size(); i++)
			{
				if (shoupai.liandui[i].mini > lastout.mini)
				{
					output(vis, put, shoupai.liandui[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
			output(vis, put, shoupai.boom[0].post);
	}
	//如果是连三
	else if (lastout.type == 7)
	{
		//连三带
		if (shoupai.liansan.size() > 0 && lastout.unit > 1 && shoupai.liansan[shoupai.liansan.size() - 1].mini>lastout.mini)
		{
			//连三
			for (int i = 0; i < shoupai.liansan.size(); i++)
			{
				if (shoupai.liansan[i].mini > lastout.mini&&shoupai.liansan[i].unit==lastout.unit)
				{
					output(vis, put, shoupai.liansan[i].post);
					break;
				}
			}
			//带一
			if (lastnum - lastout.unit * 3 == lastout.unit)
			{
				int num = 0;
				for (int i = 0; i < shoupai.dan.size(); i++)
				{
					if (shoupai.dan[i].mini > lastout.mini)
					{
						num++;
						output(vis, put, shoupai.dan[i].post);
						break;
					}
					if (num >= lastout.unit) break;
				}
			}
			//带对
			else if (lastnum - lastout.unit * 3 == lastout.unit * 2)
			{
				int num = 0;
				for (int i = 0; i < shoupai.dui.size(); i++)
				{
					if (shoupai.dui[i].mini > lastout.mini)
					{
						num++;
						output(vis, put, shoupai.dui[i].post);
						break;
					}
					if (num >= lastout.unit) break;
				}
			}
		}
		//三带一
		else if(shoupai.san.size() > 0&&lastout.unit==1&&shoupai.san[shoupai.san.size()-1].mini>lastout.mini)
		{
			//三
			for (int i = 0; i < shoupai.san.size(); i++)
			{
				if (shoupai.san[i].mini > lastout.mini)
				{
					output(vis, put, shoupai.san[i].post);
					break;
				}
			}
			//带一
			if (lastnum % 3 == 1)
			{
				for (int i = 0; i < shoupai.dan.size(); i++)
				{
					output(vis, put, shoupai.dan[i].post);
					break;
				}
			}
			//带一对
			else
			{
				for (int i = 0; i < shoupai.dui.size(); i++)
				{
					output(vis, put, shoupai.dui[i].post);
					break;
				}
			}
		}
		else if (shoupai.boom.size() > 0)
			output(vis, put, shoupai.boom[0].post);
	}
}
//对于自动出牌    1：下家是队友还是对手 2：本次接牌是对手出牌还是队友出牌 3:对手是否报单 4：队友是否报单 5:对手出牌还是队友出牌
void autoout(divide shoupai, int *&put)
{
	int post_next = 0;
	//第一判断下家不是对手并且报单——如果有则单牌从大到小出如果有其他牌则打其他牌
	if (player == people)  //是地主
	{
		if (prin[1+(player) % 3].post_sin_ene) 
			post_next = 1;
	}
	else
	{
		if (prin[people].post_sin_ene)
			post_next = 1;
	}
	//判断完毕开始出牌
	if (post_next)   //下家对手而且报单
	{
		if (shoupai.dui.size() > 0)    //先出对子
		{
			find_and_change(shoupai.dui.size(), shoupai.dui, put, 1);
		}
		else if (shoupai.liandan.size() > 0)   //再出单顺
		{
			find_and_change(shoupai.liandan.size(), shoupai.liandan, put, 1);
		}
		else if (shoupai.san.size() > 0)   //再出单顺
		{
			find_and_change(shoupai.san.size(), shoupai.san, put, 1);   //出三张
		}
		else if (shoupai.liandui.size() > 0)      //再出双顺
		{
			find_and_change(shoupai.liandui.size(), shoupai.liandui, put, 1);
		}
		else if (shoupai.liansan.size() > 0)     //再出三顺
		{
			find_and_change(shoupai.liansan.size(), shoupai.liansan, put, 1);
		}
		else if (shoupai.dan.size() > 0)   //先出单牌
		{
			find_and_change(shoupai.dan.size(), shoupai.dan, put, 0);
		}
		else     //出炸弹
		{
			find_and_change(shoupai.boom.size(), shoupai.boom, put, 1);
		}
	}
	else             //普通情况
	{
		if (shoupai.dan.size() > 0)   //先出单牌
		{
			find_and_change(shoupai.dan.size(), shoupai.dan, put, 1);
		}
		else if (shoupai.dui.size() > 0)    //再出对子
		{
			find_and_change(shoupai.dui.size(), shoupai.dui, put, 1);
		}
		else if (shoupai.san.size() > 0)    //再出三张
		{
			find_and_change(shoupai.san.size(), shoupai.san, put, 1);
		}
		else if (shoupai.liandan.size() > 0)   //再出单顺
		{
			find_and_change(shoupai.liandan.size(), shoupai.liandan, put, 1);
		}
		else if (shoupai.liandui.size() > 0)      //再出双顺
		{
			find_and_change(shoupai.liandui.size(), shoupai.liandui, put, 1);
		}
		else if (shoupai.liansan.size() > 0)     //再出三顺
		{
			find_and_change(shoupai.liansan.size(), shoupai.liansan, put, 1);
		}
		else     //出炸弹
		{
			find_and_change(shoupai.boom.size(), shoupai.boom, put, 1);
		}
	}
}

//人工智能中匹配牌的基本原则 —— 按照从小到大的顺序压牌用于自动出牌功能  
//如果是队友出牌能出则出如果必须得出A以上的就不要如果是地主出牌怎么都得要
//想办法改变匹配模式 更加高效
bool match_for_autoout(divide shoupai, int *&put)
{
	//如果是单
	if (lastout.type == 1)
	{
		if(find_and_change(shoupai.dan.size(), shoupai.dan, put, 1))
			return true;
		else
			return false;
	}
	//如果是对
	else if (lastout.type == 2)
	{
		if(find_and_change(shoupai.dui.size(), shoupai.dui, put, 1))
			return true;
		else
			return false;
	}
	//如果是三
	else if (lastout.type == 3)
	{
		if (find_and_change(shoupai.san.size(), shoupai.san, put, 1))
			return true;
		else
			return false;
	}
	//如果是炸弹
	else if (lastout.type == 4)
	{
		if(find_and_change(shoupai.boom.size(), shoupai.boom, put, 1))
			return true;
		else
			return false;
	}
	//如果是连单
	else if (lastout.type == 5)
	{
		if (find_and_change(shoupai.liandan.size(), shoupai.liandan, put, 1))
			return true;
		else
			return false;
	}
	//如果是连双
	else if (lastout.type == 6)
	{
		if(find_and_change(shoupai.liandui.size(), shoupai.liandui, put, 1))
			return true;
		else
			return false;
	}
	//如果是连三
	else if (lastout.type == 7)
	{
		//连三带
		if (lastout.unit > 1)
		{
			//连三
			if (shoupai.liansan.size() > 0 && lastnum - lastout.unit * 3 == lastout.unit&&shoupai.dan.size() > lastout.unit) // 连三带一
			{
				if (find_and_change(shoupai.liansan.size(), shoupai.liansan, put, 1))
				{
					for (int i = 0; i < lastout.unit; i++)
					{
						output_for_auto(put, shoupai.dan[i].post);
					}
					return true;
				}
				else
					return false;
			}
			//带对
			else if (shoupai.liansan.size() > 0 && lastnum - lastout.unit * 3 == lastout.unit&&shoupai.dui.size() > lastout.unit) //连三带对
			{
				if (find_and_change(shoupai.liansan.size(), shoupai.liansan, put, 1))
				{
					for (int i = 0; i < lastout.unit; i++)
					{
						output_for_auto(put, shoupai.dui[i].post);
					}
					return true;
				}
				else
					return false;
			}
		}
		//三带一
		else if (lastout.unit == 1&&shoupai.san.size() >0)
		{
			//三带一
			if (lastnum % 3 == 1 && shoupai.dan.size() > 0)
			{
				if (find_and_change(shoupai.san.size(), shoupai.san, put, 1))
				{
					output_for_auto(put, shoupai.dan[0].post);
					return true;
				}
				else
					return false;
			}
			//三带一对
			else if (shoupai.san.size() > 0 && lastnum % 3 == 2 && shoupai.dui.size() > 0)
			{
				if (find_and_change(shoupai.san.size(), shoupai.san, put, 1))
				{
					output_for_auto(put, shoupai.dui[0].post);
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
	}
	else
		return false;
}
//出牌——寻找匹配位置
bool find_and_change(int n,vector<judgepai> judge,int *put,int posted)   //post为1从小到大 post为0从大到小
{
	if (posted)
	{
		for (int i = 0; i < n; i++)
		{
			if (judge[i].mini > lastout.mini&&judge[i].unit==lastout.unit||lastout.mini==0)
			{
				output_for_auto(put, judge[i].post);
					return true;
			}
		}
		return false;
	}
	else
	{
		for (int i = n-1; i >= 0; i--)
		{
			if (judge[i].mini > lastout.mini)
			{
				output_for_auto(put, judge[i].post);
				return true;
			}
		}
		return false;
	}
}
//出牌——提示出牌实际上就是把牌相应位置的vis变成1用于提示功能
void  output(int *&vis,int *&put,vector<int> post) 
{
	for (int i = 0; i < post.size(); i++)
	{
		vis[post[i]+1] = 1;
		put[post[i] + 1] = 1;
	}
}

//出牌——提示出牌实际上就是把牌相应位置的用于自动出牌功能
void  output_for_auto(int *&put, vector<int> post)
{
	for (int i = 0; i < post.size(); i++)
	{
		put[post[i] + 1] = 1;
	}
}
/*//飞机特效
void plane()
{
	IMAGE ima[20];
	char name[20][13] = { "pl//1.jpg","pl//2.jpg","pl//3.jpg","pl//4.jpg","pl//5.jpg","pl//6.jpg","pl//7.jpg","pl//8.jpg","pl//9.jpg","pl//10.jpg","pl//11.jpg","pl//12.jpg","pl//13.jpg","pl//14.jpg","pl//15.jpg" };
	for (int i = 0; i < 15; i++)
	{
		loadimage(&ima[i], name[i], 80, 80);
	}

	for (int i = 0; i < 15; i++)   //外层for循环用来控制动画
	{
		for (int j = 0; j < ; j++) //内层for循环用来控制
		{
			putimage(400, )
		}
		Sleep(100);
	}
}
//火箭特效
void boom()
{

}*/