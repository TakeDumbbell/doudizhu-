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
//�ƵĽṹ��
typedef struct pai
{
	int huase;
	int shuzi;
	pai* next;
}pai;
//���ƵĽṹ��
typedef struct outpai
{
	int huase;  //��ɫ
	int shuzi;  //����
}outpai;
//�Ƶ��жϱȽ����ڴ�����
typedef struct judgepai
{
	int type;   //����
	int mini;   //��С
	int unit;   //��λ
	vector<int> post;   //λ��
}judgepai;
typedef struct menu
{
	bool man_machine;   //�Ƿ����˻�
	int degree;    //�Ѷ�ϵ��
};
//���ڲ�����
//���ڴ�����
typedef struct divide
{
	vector<judgepai> dan;  //����
	vector<judgepai> dui;  //����
	vector<judgepai> san;  //����
	vector<judgepai> boom;   //ը��
	vector<judgepai> liandan;    //����
	vector<judgepai> liandui;   //����
	vector<judgepai> liansan;  //����
	int num;    //����
	int value;  //Ȩֵ
}divide;
//�жϳ���ԭ��Ľṹ��
//1���¼��Ƕ��ѻ��Ƕ��� 2�����ν����ǽӶ��ֳ��ƻ��Ƕ��ѳ��� 3:�����Ƿ񱨵� 4�������Ƿ񱨵� 5 : ���ֳ��ƻ��Ƕ��ѳ���
typedef struct principle
{
	int the_ene;         //�Ƿ�Ϊ�з�����
	int post_sin_fri;    //�����Ƿ񱨵�
	int post_sin_ene;    //�����Ƿ񱨵� 
}principle;
//����һ���Ʒ���Ȩֵ������˳��  
typedef struct project
{
	int value;
	int num;
	int order[5];
}project;
//�����жϸ��ּ������
extern principle prin[4];
//���������
extern divide shoupai[4];
//����������Ƶ�����
extern pai out[10];
extern menu mymenu;  //�ҵĲ˵�ѡ��
//װ���ɵ���
extern int a[56];
//��Ҫ
extern int no;
//��֤�����涨��
extern int vis1[21];
extern int vis2[21];
extern int vis3[21];
//�洢����
extern int put1[21];
extern int put2[21];
extern int put3[21];
//��־
extern int flag;
//�Ƿ��˳���Ϸ
extern bool if_out_game;
//���
extern int player;
//ȡ��ʤ����ʶ��
extern int win;
//��˭���Ʊ�ʶ��
extern int post;
//��ǰ����
extern int point;
//��û���˽�3�ֱ�ʶ��
extern int three;
//˭�ǵ�����ʶ��
extern int people;
//��û�н����е�������
extern int on;
//�зֽ����жϱ��
extern int over;
//����ָ�������
extern int *put[4];
extern int *vis[4];
extern pai *head[4];
extern pai *tail[4];
//�����Ƶ��ļ���
extern char name[60][12];
extern IMAGE mypai[60];
//֮ǰ����
extern outpai last[8];
//������
extern outpai dizhu[5];
//���ڳ���
extern outpai now[8];
//�ϴγ��˼�����
extern int lastnum;
//��γ��˼�����
extern int nownum;
//�����ϼҳ�������
extern judgepai lastout;
//��ʼ�˵�����
void menuface();
//�����˵�����
void second_menu();
//�����˵�����
void third_menu();
//����һ��������
void link();
//����һ���ơ����Լ���
void Draw();
//���˶�ս������
void Draw_per();
//�˻���ս������
void Draw_per_ma();
//���ƽ���
void freshofpuk();
//����һ��������
void form();
//�����벻Ҫ
void outandno();
//�����ж�
bool judge(int *puts, pai *head);
//��Բ�Ҫ���ж�
bool dont();
//��Ҫ����
void nofalse();
//�Ƶ�ת��
void change();
//ʤ��
void winer_print();
//�����ϼҳ���
void Drawlastout();
//����   //����ɾ���ý��
void putpai(int *&vis, int *&put, pai *&head, int peo);
//ʤ���ж�
bool winner_judge();
//��ʼ��
void initiaze();
//ÿ��ѭ�����
void round();
//�������ֳ���
bool over_judge();
//�����жϡ������ƻ�������
judgepai* basicrule(outpai *now);
//�����жϡ�������
bool replyrule(outpai *now);
//�е���
void calldizhu(); 
//�зֻ���
void fenshu();
//����������
void drawdizhupai();
//����
void cut(pai *head,divide &shoupai);
//����һ�ַ��Ƶ����ݳ���
void abstract();
//��˳�Ӻ���
judgepai foundsunzi(int type, int *shuzi, int *&vis);
//Ѱ���������� �� �� һ �ĸ���
judgepai found(int type, int *shuzi, int *&vis);
//����һ���������ݵ���������ݴ���
void dateorg(int *shuzi, divide &shoupai, int *&vis);
//ƥ����
void match(divide shoupai, int *&vis,int *&put);
//���ơ�����ʾ����ʵ���Ͼ��ǰ�����Ӧλ�õ�vis���1
void  output(int *&vis, int *&put,vector<int> post);
//�Զ��е���
void autocallpoint(pai *head, divide shoupai);
//�Զ�����
void autoputpai(int *put, pai *&head, int peo);
//���ơ���ɾ������
void deletenode(pai *&head, int *put);
//����ѡ�ƶ��뵱ǰ��
void readinnow(pai *head, int *put);
//û��ƥ������ֻ�ܲ�Ҫ
void no_for_auto(int *put);
//���ơ�����ʾ����ʵ���Ͼ��ǰ�����Ӧλ�õ�
void  output_for_auto(int *&put, vector<int> post);
//�˹�������ƥ���ƵĻ���ԭ�� ���� ���մ�С�����˳��ѹ��
bool match_for_autoout(divide shoupai, int *&put);
//�����Զ�����    1���¼��Ƕ��ѻ��Ƕ��� 2�����ν����Ƕ��ֳ��ƻ��Ƕ��ѳ��� 3:�����Ƿ񱨵� 4�������Ƿ񱨵� 5:���ֳ��ƻ��Ƕ��ѳ���
void autoout(divide shoupai, int *&put);
//���ơ���Ѱ��ƥ��λ��
bool find_and_change(int n, vector<judgepai> judge, int *put, int posted);   //postΪ1��С���� postΪ0�Ӵ�С
//�Ӷ�������ϳ�����vector<judgepai>
void lianduiformdui(vector<judgepai> &dui, vector<judgepai> &liandui);
//��������ϳ�����vector<judgepai>
void liansanformsan(vector<judgepai> &san, vector<judgepai> &liansan);
//�����ŵ�ʱ��ӵ����߽Ӷ�
void connectdanordui(divide &shoupai);
//���ݴ�������һ��������ô�������
void dateorgforper(int *shuzi, divide &shoupai, int *&vis);
//�ҵ�����˳��
void fundallshunzi(divide &shoupai, int *&shuzi, int *&vis);
//����Ȩֵ�ĺ���
int the_value(divide shoupai);
//�ҳ�һ���Ƶ�Ȩֵ ���� ��˳�򷽱�Ƚ�
project va_nu_cmp(int *shuzi, int *&vis);
//�ҵ����е�
void fundalldan(divide &shoupai, int *&shuzi, int *&vis);
//�ҵ����ж�
void fundalldui(divide &shoupai, int *&shuzi, int *&vis);
//�ҵ�������
void fundallsan(divide &shoupai, int *&shuzi, int *&vis);
//�ҵ�������
void fundallsi(divide &shoupai, int *&shuzi, int *&vis);
//�ɻ���Ч
void plane();
//�����Ч
void boom();
#endif


