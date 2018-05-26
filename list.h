#ifndef LIST
#define LIST
#define L 50
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct message {
	char name[20];
	char password[20];
} Item2;
typedef struct node2 {
	Item2 item;
	struct node2 * next;
}*List2, Node2;
typedef struct data {
	char name[L];
	char id[L];
	int math, en, pe, ch;
	int ranking;//总排名
	int math_r, en_r, pe_r, ch_r;
}Item;
typedef struct node {
	Item item;
	struct node * next;
}Node, *List;
void begin(void);
void screen_s(void);
void screen(void);
void sort_screen(void);
bool registe(List2 head2);//注册
List creat(void);
void del_id(List head, char s[]);
void del_name(List head, char s[]);
void tail_insert(List head);
void traverse_list(List head);
int length(List);
bool serach(List head, char s[]);
void revamp(List head, char s[]);
bool save0();//保存
bool load0();//读取
bool logAdministrator(void);
bool login(List2 head2);
bool load_user(List2 head2);
bool user_chachong(List2 head2, char s[]);//用户名查重
bool id_chachong(List head, char id[]);//id查重
bool sort_ch(List head);
bool sort_math(List head);
bool sort_en(List head);
bool sort_pe(List head);
bool sort_all(List head);
bool analyze(List head);
bool serach2(List head);//组合
bool reverse(List head);//逆置
bool sor(List head);
#endif