#include "stdafx.h"
#include"doudizhu.h"
#include <algorithm>
#include <math.h>
using namespace std;
//����������Ƶ�����
pai out[10]; 
//װ���ɵ���
int a[56];
//��Ҫ
int no = 0;
//�Ƿ��˳���Ϸ
bool if_out_game = false;
//��֤�����涨��
int vis1[21];
int vis2[21];
int vis3[21];
//�洢����
int put1[21];
int put2[21];
int put3[21];
//��־
int flag = 1;
//���
int player = 1;
//�Ƿ�ʤ����ʶ��
int win = 1;
//�ֵ�˭���Ʊ�ʶ��
int post = 1;
//˭�ǵ�����ʶ��
int people = 0;
//��û�н����е�������
int on;
//��ǰ����
int point;
//��û���˽�3�ֱ�ʶ��
int three;
//�зֽ����жϱ��
int over;
//����ָ�������
int *put[4] = { NULL,put1,put2,put3 };
int *vis[4] = { NULL,vis1,vis2,vis3 };
pai *head[4] = { NULL };
pai *tail[4] = { NULL };
//�����Ƶ��ļ���
char name[60][12] = { "pk//1.jpg","pk//2.jpg","pk//3.jpg","pk//4.jpg","pk//5.jpg","pk//6.jpg","pk//7.jpg","pk//8.jpg","pk//9.jpg","pk//10.jpg","pk//11.jpg","pk//12.jpg","pk//13.jpg","pk//14.jpg","pk//15.jpg","pk//16.jpg","pk//17.jpg","pk//18.jpg","pk//19.jpg","pk//20.jpg","pk//21.jpg",
"pk//22.jpg","pk//23.jpg","pk//24.jpg","pk//25.jpg","pk//26.jpg","pk//27.jpg","pk//28.jpg","pk//29.jpg","pk//30.jpg","pk//31.jpg","pk//32.jpg","pk//33.jpg","pk//34.jpg","pk//35.jpg","pk//36.jpg","pk//37.jpg","pk//38.jpg","pk//39.jpg","pk//40.jpg","pk//41.jpg","pk//42.jpg","pk//43.jpg","pk//44.jpg","pk//45.jpg",
"pk//46.jpg","pk//47.jpg","pk//48.jpg","pk//49.jpg","pk//50.jpg","pk//51.jpg","pk//52.jpg","pk//53.jpg","pk//54.jpg" };
IMAGE mypai[60];
//֮ǰ����
outpai last[8];
//���ڳ���
outpai now[8];
//������
outpai dizhu[5];
//�ϴγ��˼�����
int lastnum;
//��γ��˼�����
int nownum;
//�ϼҳ���
judgepai lastout;
//���������
divide shoupai[4];
//�����жϸ��ּ������
principle prin[4];
//�˵�����
menu mymenu;
//��ʼ��
//��ʼ�˵�����
void menuface()
{
	initgraph(800, 600, NULL); //��ʼ������
	loadimage(NULL, "����//�����˵�.jpg", 800, 600);
	IMAGE ima1,ima2;
	loadimage(&ima1, "����//��ʼ��Ϸ.jpg", 200, 80);
	loadimage(&ima2, "����//�˳���Ϸ.jpg", 200, 80);
	putimage(300, 200, &ima1);
	putimage(300, 400, &ima2);
	PlaySound("ǰ��.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		//rectangle(300, 520, 500, 570);
		if (m.x >= 300 && m.x <= 500 && m.y >= 200 && m.y <= 280 && m.mkLButton == true)  //��ʼ��Ϸ��������˵�����
		{
			second_menu();
			break;
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 400 && m.y <= 480 && m.mkLButton == true)  //�˳���Ϸ�رճ���
		{
			if_out_game = true;
			break;
		}
	}
}
//�����˵�����
void second_menu()
{
	loadimage(NULL, "����//�����˵�.jpg", 800, 600);
	IMAGE ima1, ima2;
	loadimage(&ima1, "����//���˶�ս.jpg", 200, 80);
	loadimage(&ima2, "����//�˻���ս.jpg", 200, 80);
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
		else if (m.x >= 500 && m.x <= 700 && m.y >= 150 && m.y <= 230 && m.mkLButton == true)  //�˻���ս
		{
			mymenu.man_machine = true;
			third_menu();
			break;
		}
	}
}
//�����˵�����
void third_menu()
{
	IMAGE ima1, ima2,ima3;
	loadimage(&ima1, "����//��.jpg", 150, 60);
	loadimage(&ima2, "����//�м�.jpg", 150, 60);
	loadimage(&ima3, "����//����.jpg", 150, 60);
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
	PlaySound("���������.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
	//һ���µĶ�������5��

	loadimage(NULL, "����//�����˵�.jpg", 800, 600);
	//ͼ����
	IMAGE ima;
	loadimage(&ima,"����//����.jpg", 200, 100);
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
	PlaySound("Faded.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
	loadimage(NULL, "timg.jpg", 800, 600); //���ر���
}
//��������
bool cmp(outpai a, outpai b)
{
	if (a.shuzi != b.shuzi)
		return a.shuzi < b.shuzi;
	else if (a.huase != b.huase)
		return a.huase < b.huase;
}
//����һ�������
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
//����һ��������
//(shuzi-1)*4+huase=�Ƶ����
void link()
{
	//��һ
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
	//�ƶ�
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
	//����
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
	//������
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
//���ơ�������������
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
	int *p = vis; // vis��������¼���������е��������Ƿ��Ѿ�������ı�־
	//����һ���������ݵ���������ݴ���
	if (prin[player].the_ene)               //�з�����
		dateorg(shuzi, shoupai, p);         //������� ֻ�������
	else
		dateorgforper(shuzi, shoupai, p);  //�Ӷ����� �Լ�����
	//���ݴ������
}
//����һ���������ݵ���������ݴ����������������
void dateorg(int *shuzi,divide &shoupai,int *&vis)
{
	//��ʼ��
	shoupai.boom.clear();
	shoupai.dan.clear();
	shoupai.dui.clear();
	shoupai.san.clear();         //���ڲ��ƣ�ÿ�β�ͬ������в�ͬ�Ĳ����Ⱥ�˳��
	shoupai.liandan.clear();     //��Ӧ����������ȡ�����ŵĽ��  
	shoupai.liandui.clear();     //���������ѵ㣬����˳�ӵĲ�����ô�� ˫˳��˳�������ô��
	shoupai.liansan.clear();    //���ǰ������ȼ�������Ƹ����ϼҳ�����������
	void(*f[5])(divide &shoupai, int *&shuzi, int *&vis) = { fundallshunzi,fundallsi,fundallsan,fundalldui }; //˳ �� �� �� 
	int turn[5] = { 0,1,2,3 };
	if (lastout.type == 5)  //����
	{
		(*f[turn[0]])(shoupai, shuzi, vis);
		(*f[turn[1]])(shoupai, shuzi, vis);
		(*f[turn[2]])(shoupai, shuzi, vis);
		(*f[turn[3]])(shoupai, shuzi, vis);
		for (int i = 0; i < shoupai.liandan.size(); i++)
		{
			if (shoupai.liandan[i].mini + shoupai.liandan[i].unit> lastout.mini+lastout.unit&&shoupai.liandan[i].unit >= lastout.unit)
			{
				while (shoupai.liandan[i].mini <= lastout.mini)  //����ǰ�벿�֡�����Ϊ���ֵ���ڣ��ҵ�λ����
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
				while (shoupai.liandan[i].unit != lastout.unit)   //������벿��
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
	else if (lastout.type == 6)    //����
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
				while (shoupai.liandui[i].mini <= lastout.mini)  //����ǰ�벿�֡�����Ϊ���ֵ���ڣ��ҵ�λ����
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
				while (shoupai.liandui[i].unit != lastout.unit)   //������벿��
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
	else if (lastout.type == 7)  //����
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
				while (shoupai.liansan[i].mini <= lastout.mini)  //����ǰ�벿�֡�����Ϊ���ֵ���ڣ��ҵ�λ����
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
				while (shoupai.liansan[i].unit != lastout.unit)   //������벿��
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
	//���µ�
	fundalldan(shoupai,shuzi,vis);
	//�Ӷ������������
	//lianduiformdui(shoupai.dui, shoupai.liandui);
	//�������������
	//lianduiformdui(shoupai.san, shoupai.liansan);
}
//���ݴ�������һ��������ô������š�������Ȩֵ������   �޷Ǿ��Ǹı�˳��   �ı�˳�ӵ���ȡ
void dateorgforper(int *shuzi, divide &shoupai, int *&vis)  //��Ӧ������������еõ�Ȩֵ�ٽ��бȽϣ��õ����յĲ��Ʒ���
{
	//��ʼ��
	shoupai.boom.clear();
	shoupai.dan.clear();
	shoupai.dui.clear();
	shoupai.san.clear();         //���ڲ��ƣ�ÿ�β�ͬ������в�ͬ�Ĳ����Ⱥ�˳��
	shoupai.liandan.clear();     //��Ӧ����������ȡ�����ŵĽ��  
	shoupai.liandui.clear();     //���������ѵ㣬����˳�ӵĲ�����ô�� ˫˳��˳�������ô��
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
	connectdanordui(shoupai);  //�Ѳ����������������
	liansanformsan(shoupai.san, shoupai.liansan);
	/*fundallshunzi(shoupai, shuzi, vis);
	//������
	fundallsi(shoupai, shuzi, vis);
	//������
	fundallsan(shoupai, shuzi, vis);
	//���Ҷ�
	fundalldui(shoupai, shuzi, vis);
	//���µ�
	fundalldan(shoupai, shuzi, vis);*/
	//�Ӷ������������
	//lianduiformdui(shoupai.dui, shoupai.liandui);
	//�������������
	//lianduiformdui(shoupai.san, shoupai.liansan);
	//һ���Ƶ�����
	//shoupai.num = shoupai.liandui.size() + shoupai.liandan.size() + shoupai.boom.size() + shoupai.dui.size()+shoupai.dan.size();
	//һ���Ƶ�Ȩֵ
	//shoupai.value = the_value(shoupai);
}
//�ҳ�һ���Ƶ�Ȩֵ ���� ��˳�򷽱�Ƚ�
project va_nu_cmp(int *shuzi,int *&vis)
{
	void(*f[5])(divide &shoupai, int *&shuzi, int *&vis) = { fundallshunzi,fundallsi,fundallsan,fundalldui };  //���� �� �� �� 
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
					testshoupai.san.clear();         //���ڲ��ƣ�ÿ�β�ͬ������в�ͬ�Ĳ����Ⱥ�˳��
					testshoupai.liandan.clear();     //��Ӧ����������ȡ�����ŵĽ��  
					testshoupai.liandui.clear();     //���������ѵ㣬����˳�ӵĲ�����ô�� ˫˳��˳�������ô��
					testshoupai.liansan.clear();
					(*f[i])(testshoupai, shuzi, vis);
					(*f[j])(testshoupai, shuzi, vis);
					(*f[k])(testshoupai, shuzi, vis);
					(*f[t])(testshoupai, shuzi, vis);
					fundalldan(testshoupai, shuzi, vis);
					//�Ӷ������������
					lianduiformdui(testshoupai.dui, testshoupai.liandui);
					//�������������
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
//����Ȩֵ�ĺ���
int the_value(divide shoupai)
{
	int num = 0;
	//ը��
	for (int i = 0; i < shoupai.boom.size(); i ++ )
	{
		num += 8;
	}
	//����
	for (int i = 0; i < shoupai.dan.size(); i++)
	{
		num += 1;
	}
	//����
	for (int i = 0; i < shoupai.dui.size(); i++)
	{
		num += 2;
	}
	//����
	for (int i = 0; i < shoupai.san.size(); i++)
	{
		num +=  3;
	}
	//����
	for (int i = 0; i < shoupai.liandan.size(); i++)
	{
		num += shoupai.liandan[i].unit;
	}
	//����
	for (int i = 0; i < shoupai.liandui.size(); i++)
	{
		num += shoupai.liandui[i].unit * 2;
	}
	//����
	for (int i = 0; i < shoupai.liansan.size(); i++)
	{
		num += shoupai.liansan[i].unit * 3;
	}
	return num;
}
//�ӵ�����ϳ�����vector<judgepai>
void liandanformdan(vector<judgepai> &dan, vector<judgepai> &liandan)    //���˳��
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
						judge.post.push_back(dan[i-4].post[0]);     //������λ�ô���������
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
//�Ӷ�������ϳ�����vector<judgepai>
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
						judge.post.push_back(dui[i-2].post[0]);     //�����ӵ�λ�ô���������
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
//��������ϳ�����vector<judgepai>
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
//������������ڲ�3֮�������Ļ�ֻҪ����3֮�������һ�£��޸�������������Ĵ���
//�����ŵ�ʱ��ӵ����߽Ӷ�
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
//��Ȩֵ��������ϵ������Ʒ�װ��
//һ���ĳ�ʼ��������Ȩֵ��������϶��ɵ����Ž⡪����ʼ���ǲ�õ�һ����������
//������ÿһ�ν���ǰ����²�һ���ơ��������ϼҵĵ��ѹ�ϵ����
//����ǵи��ݳ��Ʋ���
//�������Ϊ���Ų���
//���� ������������򲻲�  //������ѳ������Ȳ�
//�������в����vector<judgepai> ���ض���   �������Ҫ�� 1���Ӷ����Ƶ�ʱ����ܲ�����    2��������һ�Ե�ʱ��û���ӵ�ʱ��  ������С����
//Ѱ���������� �� �� һ �ĸ���
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
		//�ҵ�һ������
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
//��˳�Ӻ���
judgepai foundsunzi(int type, int *shuzi, int *&vis)
{
	judgepai judge;
	judge.mini = 0;
	int num = 0;
	int charge[15];
	int count = 0;
	int flag = 1;
	int i = 0;  //����shuzi����
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
		charge[t++] = i;        //����˳�ӵ�λ��
		vis[i] = 1;            //��ͷԪ�ر�������
		judge.post.push_back(i);
		for(int j=i+1;j<=i+3;j++)
		{
			//����ں���3��Ԫ�����ҵ��˱�����һ��Ԫ��  1������ 2������λ�� 3���ı��־ 4����¼�Ƿ񱳱�����
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
		//�����������Ԫ���ж�û���ҵ�������һ��Ԫ�� ��Ѱ���жϣ�ȫ����ʼ��
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
//�ҵ�����˳��
void fundallshunzi(divide &shoupai,int *&shuzi,int *&vis)
{
	//����˳��
	while (1)
	{                            //�ȱ������ٱ�Ȩֵ  
		judgepai judge = foundsunzi(5, shuzi, vis);
		if (judge.mini != 0)
		{
			shoupai.liandan.push_back(judge);
		}
		else
			break;
	}
	//����ʣ�������ܷ��������
	int i = 0;  //����shuzi����
	while (shuzi[i] != 0 && shuzi[i]<13)
	{
		if (vis[i])
		{
			i++;
			continue;
		}
		for (int j = 0; j < shoupai.liandan.size(); j++)
		{
			//��������ֿ��Բ嵽˳�Ӻ�����ȥ  ���ȥ�� UNITE+1 post�ƽ�
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
	//�Ƿ������β�޷�����
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
//�ҵ�������
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
//�ҵ�������
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
//�ҵ����ж�
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
//�ҵ����е�
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
//����һ�ַ��Ƶ����ݳ���
void abstract()
{
	for (int i = 1; i <= 3; i++)
	{
		cut(head[i],shoupai[i]);
	}
}
//����������
void Draw()
{
	//cleardevice();

	loadimage(NULL, "timg.jpg", 800, 600);
	if (!on)
		fenshu();
	else
	{
		drawdizhupai();
		if (mymenu.man_machine)  //������˻���ս��
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
	//�ϼҳ���
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
//���˶�ս������
void Draw_per()
{
	pai *temp1 = head[1];
	pai *temp2 = head[2];
	pai *temp3 = head[3];
	int t1 = 1;
	int t2 = 1;
	int t3 = 1;
	//��һ���� ������
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
	// ����
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
	// ����
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
//�˻���ս������
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
	//��һ���� ������
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
	// ����
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
	// ����
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
//���ƽ���
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
		PlaySound("����.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
		Sleep(100);
	}
}
//�����ϼҳ���
void Drawlastout()
{
	//�ϼҳ���
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
//�����벻Ҫ
void outandno()
{
	IMAGE ima1, ima2,ima3;
	loadimage(&ima1, "click//����.jpg", 80, 30);
	loadimage(&ima2, "click//����.jpg", 80, 30);
	loadimage(&ima3, "click//��ʾ.jpg", 80, 30);
	putimage(190, 400, &ima1);
	putimage(360, 400, &ima3);
	putimage(530, 400, &ima2);
}
//����   //����ɾ���ý����԰�
void putpai(int *&vis, int *&put, pai *&head, int peo)
{
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		//�����
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
		//��Ҫ
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
		//��ʾ
		else if (m.y >= 400 && m.y <= 430 && m.x >= 360 && m.x <= 440 && m.mkLButton == true)
		{
			match(shoupai[peo],vis,put);
			break;
		}
		//����
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
//�Զ�����
void autoputpai(int *put, pai *&head, int peo)    //��ʵ���Ǹ���ƥ�����Ƶ�put�ı�
{
	//���ֳ��Ƶ�һ�����ԭ��    ���� ������С Ȩֵ���
	//���ֳ���   ���� һ��ԭ���С����   1���Լ��ǲ��ǵ���   ����ǵ���ƫ�����ϻ�ʣ������   �����ƫ�ҵ������ϻ�ʣ������
	if (last[0].shuzi == 0)
	{
		autoout(shoupai[player], put);  //�Զ�����
		readinnow(head, put);     //������֮��ĺ���������
		no = 0;
		deletenode(head, put);
		memset(put, 0, sizeof(put) * 20);
		flag = 0;
	}
	//���ֽ���     1���ϼҳ����ǵ������Ƕ���    ����ǵ���һ���ý�  ����Ƕ��ѽӲ����Ͳ���
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
			PlaySound("pass.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
			no_for_auto(put);
		}
	}
}
//�����Զ�����    1���¼��Ƕ��ѻ��Ƕ��� 2�����ν����Ƕ��ֳ��ƻ��Ƕ��ѳ��� 3:�����Ƿ񱨵� 4�������Ƿ񱨵� 5:���ֳ��ƻ��Ƕ��ѳ���

//����ѡ�ƶ��뵱ǰ��
void readinnow(pai *head,int *put)
{
	//�ѳ��ƶ��뵱ǰ��
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
	lastout.mini = situa->mini;        //���ֳ��Ƶĺ�������
	lastout.unit = situa->unit;
	Drawlastout();
	change();
}
//û��ƥ������ֻ�ܲ�Ҫ
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
//���ơ�����������ɾ�����
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
//��Բ�Ҫ���ж�
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
//��Ҫ����
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
//�Ƶ�ת��
void change()
{
	//�ѵ�ǰ�Ʊ���ϴ���
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
//ʤ����ӡ
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
//ʤ���ж�
bool winner_judge()
{
	if (win == 1)
		return true;
	else
		return false;
}
//ÿ��ѭ�����
void round()
{
	flag = 1;
	if (shoupai[player].dan.size() == 1 && shoupai[player].num == 1)
	{
		if (player == people)      //��������  ũ�����
		{
			for (int i = 1; i <= 3; i++)
			{
				if (i != player)
					prin[i].post_sin_ene = 1;
			}
		}
		else
			prin[people].post_sin_ene = 1;     //ũ�񱨵� ��������
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
//�������ֳ���
bool over_judge()
{
	if (flag == 1)
		return true;
	else
		return false;
}
//�е�����������
//(shuzi-1)*4+huase=�Ƶ����
bool judge(int puts[17], pai *head)
{
	//�ѳ��ƶ��뵱ǰ��
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
	//���ֳ���
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
	//���ֽ���
	else if (replyrule(now))
	{
		Drawlastout();
		change();
		return true;
	}
	//���ƴ���
	else
	{
		memset(now, 0, sizeof(now));
		nownum = 0;
		return false;
	}
}
//�ж϶������ź����ŵĸ���
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
//���ơ���1
bool isdanpai(outpai *now)
{
	if (now[0].shuzi > 0 && now[1].shuzi == 0)
		return true;
	else
		return false;
}
//���ӡ���2
bool isduizi(outpai *now)
{
	if (now[0].shuzi == now[1].shuzi&&now[2].shuzi == 0 && now[0].shuzi !=14&&nownum==2)
		return true;
	else
		return false;
}
//��������3
bool ispuresan(outpai *now)
{
	judgepai *judge = count(now, 3);
	if (judge->unit==1 && nownum == 3)
		return true;
	else
		return false;
}
//ը������4
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
//��������5
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
//���ԡ���6
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
//��������7
bool isliansan(outpai *now)
{
	judgepai *judge3 = count(now, 3);
	judgepai *judge2 = count(now, 2);
	//������
	if (judge3->unit * 3 == nownum&&nownum > 0)
		return true;
	//��һ
	else if (judge3->unit >= nownum / 4 && nownum % 4 == 0 && judge3->unit>0)
		return true;
	//����
	else if (judge3->unit == judge2->unit && judge3->unit * 5 == nownum&&nownum > 0)
		return true;
	else
		return false;
}
//���ġ���8
bool isliansi(outpai *now)
{
	judgepai *judge4 = count(now, 4);
	judgepai *judge2 = count(now, 2);
	//������
	if (judge4->unit * 4 == nownum&&judge4->unit>1)
		return true;
	//����
	else if (judge4->unit >= nownum / 6 && nownum % 6 == 0&&nownum>0)
		return true;
	//������
	else if (judge4->unit * 2 == judge2->unit  && judge4->unit * 8 == nownum&&nownum>0)
		return true;
	else
		return false;
}
//��Գ����жϡ���������
judgepai* basicrule(outpai *no)
{
	judgepai *situa;
	situa = new judgepai;
	//���ơ���1
	if (isdanpai(no))
	{
		situa->type = 1;
		situa->unit = 1;
		if (no[0].shuzi == 14)
			situa->mini = no[0].shuzi + no[0].huase;
		else
			situa->mini = no[0].shuzi;
	}
	//���ӡ���2
	else if (isduizi(no))
	{
		situa->type = 2;
		situa->unit = 1;
		situa->mini = no[0].shuzi;
	}
	//��������3
	else if (ispuresan(no))
	{
		situa->type = 3;
		situa->unit = 1;
		situa->mini = no[0].shuzi;
	}
	//ը������4
	else if (isboom(no))
	{
		situa->type = 4;
		situa->unit = 1;
		situa->mini = no[0].shuzi;
	}
	//��������5
	else if (issunzi(no))
	{
		situa->type = 5;
		situa->unit = nownum;
		situa->mini = no[0].shuzi;
	}
	//���ԡ���6
	else if (isliandui(no))
	{
		situa->type = 6;
		situa->unit = nownum/2;
		situa->mini = no[2].shuzi;
	}
	//��������7
	else if (isliansan(no))
	{
		judgepai* judge = count(no, 3);
		situa->type = 7;
		situa->unit = judge->unit;
		situa->mini = judge->mini;
	}
	//���ġ���8
	else if (isliansi(no))
	{
		judgepai* judge = count(no, 4);
		situa->type = 8;
		situa->unit = judge->unit;
		situa->mini = judge->mini;
	}
	//������
	else
	{
		situa->type = 0;
		situa->mini = 0;
		situa->unit = 0;
	}
	return situa;
}
//�����жϡ�������
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
//��õ�����
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
//�зֺ���
void callpoint()
{
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		//һ��
		if (m.y >= 390 && m.y <= 420 && m.x >= 200 && m.x <= 280 && m.mkLButton == true)
		{
			if (point < 1)
			{
				people = player;
				point = 1;
				over = 1;
				PlaySound("һ��.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
				break;
			}
			else
			{
				nofalse();
				break;
			}
		}
		//����
		else if (m.y >= 390 && m.y <= 420 && m.x >= 300 && m.x <= 380 && m.mkLButton == true)
		{
			if (point < 2)
			{
				people = player;
				point = 2;
				over = 1;
				PlaySound("����.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
				break;
			}
			else
			{
				nofalse();
				break;
			}
		}
		//����
		else if (m.y >= 390 && m.y <= 420 && m.x >= 400 && m.x <= 480 && m.mkLButton == true)
		{
			three = 1;
			people = player;
			over = 1;
			PlaySound("����.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
			break;
		}
		//����
		else if (m.y >= 390 && m.y <= 420 && m.x >= 500 && m.x <= 580 && m.mkLButton == true)
		{
			over = 1;
			break;
		}
	}
}
//�зֻ���
void fenshu()
{
	IMAGE ima1, ima2, ima3, ima4,ima5;
	loadimage(&ima1, "click//һ��.jpg", 80, 30);
	loadimage(&ima2, "click//����.jpg", 80, 30);
	loadimage(&ima3, "click//����.jpg", 80, 30);
	loadimage(&ima4, "click//����.jpg", 80, 30);
	putimage(200, 390, &ima1);
	putimage(300, 390, &ima2);
	putimage(400, 390, &ima3);
	putimage(500, 390, &ima4);
}
//����������
void drawdizhupai()
{
	for (int i = 52; i<= 54; i++)
	{
		IMAGE im;
		loadimage(&im, name[a[i] - 1], 80, 100);
		putimage(320 + (i-52) * 20, 50, &im);
	}
}
//��������
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
//�е���
void calldizhu()
{
	int count = 0;   //�зִ�������ֻ�ܽ�����
	while (1)
	{
		cut(head[player],shoupai[player]);
		over = 0;
		//�е���
		while (!over)
		{
			Draw();     //��������
			if (player == 1)
				callpoint();//�з�
			else
			{
				if (mymenu.man_machine)
					autocallpoint(head[player], shoupai[player]); //�Զ��з�
				else
					callpoint();//�ֶ��з�
			}
			count++;
			if (three||count >= 3)
				break;
			Sleep(200);
		}
		player++;
		if (player > 3)   //ѭ���е���
			player = 1;
		if (three||(count>=3&&people>0))   //�õ�������
		{
			on = 1;    //�����е���
			getdizhupa(head[people],tail[people]);
			break;
		}
		else if(count>=3&&people==0)  //û�˽е������·���
		{
			for (int i = 1; i <= 3; i++)
				deletelink(head[i]);
			form();
			link();
			count = 0;
		}
		Sleep(200);
	}
	player = people;  //�е�������
	PlaySound("��������.wav", NULL, SND_FILENAME | SND_ASYNC); //���Ÿ���
	//abstract();//���ݳ�ʼ���������
}
//�Զ��е���
void autocallpoint(pai *head,divide shoupai)
{
	//Ȩֵ
	int value = 0;
	for (int i = 0; i < shoupai.boom.size(); i++)   //ը��
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
	//һ��
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
	//����
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
	//����
	else if (value>=8)
	{
		three = 1;
		people = player;
		over = 1;
	}
	//����
	else if (value<4)
	{
		over = 1;
	}
}
//ƥ���ơ���������ʾ����
void match(divide shoupai,int *&vis,int *&put)
{
	//����ǵ�
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
	//����Ƕ�
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
	//�������
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
	//�����ը��
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
	//���������
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
	//�������˫
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
	//���������
	else if (lastout.type == 7)
	{
		//������
		if (shoupai.liansan.size() > 0 && lastout.unit > 1 && shoupai.liansan[shoupai.liansan.size() - 1].mini>lastout.mini)
		{
			//����
			for (int i = 0; i < shoupai.liansan.size(); i++)
			{
				if (shoupai.liansan[i].mini > lastout.mini&&shoupai.liansan[i].unit==lastout.unit)
				{
					output(vis, put, shoupai.liansan[i].post);
					break;
				}
			}
			//��һ
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
			//����
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
		//����һ
		else if(shoupai.san.size() > 0&&lastout.unit==1&&shoupai.san[shoupai.san.size()-1].mini>lastout.mini)
		{
			//��
			for (int i = 0; i < shoupai.san.size(); i++)
			{
				if (shoupai.san[i].mini > lastout.mini)
				{
					output(vis, put, shoupai.san[i].post);
					break;
				}
			}
			//��һ
			if (lastnum % 3 == 1)
			{
				for (int i = 0; i < shoupai.dan.size(); i++)
				{
					output(vis, put, shoupai.dan[i].post);
					break;
				}
			}
			//��һ��
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
//�����Զ�����    1���¼��Ƕ��ѻ��Ƕ��� 2�����ν����Ƕ��ֳ��ƻ��Ƕ��ѳ��� 3:�����Ƿ񱨵� 4�������Ƿ񱨵� 5:���ֳ��ƻ��Ƕ��ѳ���
void autoout(divide shoupai, int *&put)
{
	int post_next = 0;
	//��һ�ж��¼Ҳ��Ƕ��ֲ��ұ���������������ƴӴ�С����������������������
	if (player == people)  //�ǵ���
	{
		if (prin[1+(player) % 3].post_sin_ene) 
			post_next = 1;
	}
	else
	{
		if (prin[people].post_sin_ene)
			post_next = 1;
	}
	//�ж���Ͽ�ʼ����
	if (post_next)   //�¼Ҷ��ֶ��ұ���
	{
		if (shoupai.dui.size() > 0)    //�ȳ�����
		{
			find_and_change(shoupai.dui.size(), shoupai.dui, put, 1);
		}
		else if (shoupai.liandan.size() > 0)   //�ٳ���˳
		{
			find_and_change(shoupai.liandan.size(), shoupai.liandan, put, 1);
		}
		else if (shoupai.san.size() > 0)   //�ٳ���˳
		{
			find_and_change(shoupai.san.size(), shoupai.san, put, 1);   //������
		}
		else if (shoupai.liandui.size() > 0)      //�ٳ�˫˳
		{
			find_and_change(shoupai.liandui.size(), shoupai.liandui, put, 1);
		}
		else if (shoupai.liansan.size() > 0)     //�ٳ���˳
		{
			find_and_change(shoupai.liansan.size(), shoupai.liansan, put, 1);
		}
		else if (shoupai.dan.size() > 0)   //�ȳ�����
		{
			find_and_change(shoupai.dan.size(), shoupai.dan, put, 0);
		}
		else     //��ը��
		{
			find_and_change(shoupai.boom.size(), shoupai.boom, put, 1);
		}
	}
	else             //��ͨ���
	{
		if (shoupai.dan.size() > 0)   //�ȳ�����
		{
			find_and_change(shoupai.dan.size(), shoupai.dan, put, 1);
		}
		else if (shoupai.dui.size() > 0)    //�ٳ�����
		{
			find_and_change(shoupai.dui.size(), shoupai.dui, put, 1);
		}
		else if (shoupai.san.size() > 0)    //�ٳ�����
		{
			find_and_change(shoupai.san.size(), shoupai.san, put, 1);
		}
		else if (shoupai.liandan.size() > 0)   //�ٳ���˳
		{
			find_and_change(shoupai.liandan.size(), shoupai.liandan, put, 1);
		}
		else if (shoupai.liandui.size() > 0)      //�ٳ�˫˳
		{
			find_and_change(shoupai.liandui.size(), shoupai.liandui, put, 1);
		}
		else if (shoupai.liansan.size() > 0)     //�ٳ���˳
		{
			find_and_change(shoupai.liansan.size(), shoupai.liansan, put, 1);
		}
		else     //��ը��
		{
			find_and_change(shoupai.boom.size(), shoupai.boom, put, 1);
		}
	}
}

//�˹�������ƥ���ƵĻ���ԭ�� ���� ���մ�С�����˳��ѹ�������Զ����ƹ���  
//����Ƕ��ѳ����ܳ�����������ó�A���ϵľͲ�Ҫ����ǵ���������ô����Ҫ
//��취�ı�ƥ��ģʽ ���Ӹ�Ч
bool match_for_autoout(divide shoupai, int *&put)
{
	//����ǵ�
	if (lastout.type == 1)
	{
		if(find_and_change(shoupai.dan.size(), shoupai.dan, put, 1))
			return true;
		else
			return false;
	}
	//����Ƕ�
	else if (lastout.type == 2)
	{
		if(find_and_change(shoupai.dui.size(), shoupai.dui, put, 1))
			return true;
		else
			return false;
	}
	//�������
	else if (lastout.type == 3)
	{
		if (find_and_change(shoupai.san.size(), shoupai.san, put, 1))
			return true;
		else
			return false;
	}
	//�����ը��
	else if (lastout.type == 4)
	{
		if(find_and_change(shoupai.boom.size(), shoupai.boom, put, 1))
			return true;
		else
			return false;
	}
	//���������
	else if (lastout.type == 5)
	{
		if (find_and_change(shoupai.liandan.size(), shoupai.liandan, put, 1))
			return true;
		else
			return false;
	}
	//�������˫
	else if (lastout.type == 6)
	{
		if(find_and_change(shoupai.liandui.size(), shoupai.liandui, put, 1))
			return true;
		else
			return false;
	}
	//���������
	else if (lastout.type == 7)
	{
		//������
		if (lastout.unit > 1)
		{
			//����
			if (shoupai.liansan.size() > 0 && lastnum - lastout.unit * 3 == lastout.unit&&shoupai.dan.size() > lastout.unit) // ������һ
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
			//����
			else if (shoupai.liansan.size() > 0 && lastnum - lastout.unit * 3 == lastout.unit&&shoupai.dui.size() > lastout.unit) //��������
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
		//����һ
		else if (lastout.unit == 1&&shoupai.san.size() >0)
		{
			//����һ
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
			//����һ��
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
//���ơ���Ѱ��ƥ��λ��
bool find_and_change(int n,vector<judgepai> judge,int *put,int posted)   //postΪ1��С���� postΪ0�Ӵ�С
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
//���ơ�����ʾ����ʵ���Ͼ��ǰ�����Ӧλ�õ�vis���1������ʾ����
void  output(int *&vis,int *&put,vector<int> post) 
{
	for (int i = 0; i < post.size(); i++)
	{
		vis[post[i]+1] = 1;
		put[post[i] + 1] = 1;
	}
}

//���ơ�����ʾ����ʵ���Ͼ��ǰ�����Ӧλ�õ������Զ����ƹ���
void  output_for_auto(int *&put, vector<int> post)
{
	for (int i = 0; i < post.size(); i++)
	{
		put[post[i] + 1] = 1;
	}
}
/*//�ɻ���Ч
void plane()
{
	IMAGE ima[20];
	char name[20][13] = { "pl//1.jpg","pl//2.jpg","pl//3.jpg","pl//4.jpg","pl//5.jpg","pl//6.jpg","pl//7.jpg","pl//8.jpg","pl//9.jpg","pl//10.jpg","pl//11.jpg","pl//12.jpg","pl//13.jpg","pl//14.jpg","pl//15.jpg" };
	for (int i = 0; i < 15; i++)
	{
		loadimage(&ima[i], name[i], 80, 80);
	}

	for (int i = 0; i < 15; i++)   //���forѭ���������ƶ���
	{
		for (int j = 0; j < ; j++) //�ڲ�forѭ����������
		{
			putimage(400, )
		}
		Sleep(100);
	}
}
//�����Ч
void boom()
{

}*/