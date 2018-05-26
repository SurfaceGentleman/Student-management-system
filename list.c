#include"list.h"
static void copy(Item item, List p);
List creat(void)
{
	List head;
	head = (List)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}
void tail_insert(List head)
{
	Item val;
	List pnew, p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	printf("Please input the student's id:(length == 8,请输入数字)\n");
	scanf("%s", val.id);
	int len = strlen(val.id);
	if (len != 8) {
		puts("Error!Please input correct item!");
		getchar();
		return;
	}
	bool result = true;
	for (int i = 0; i < len; i++) {
		if (val.id[i] < '0' || val.id[i] > '9') {
			puts("Please input numbers!!!");
			result = false;
		}
	}
	if (!result) {
		puts("请输入数字！！！！");
		return;
	}
	if (id_chachong(head, val.id)) {
		printf("Please enter the name：\n");
		
		getchar();
		//fflush(stdin);
		gets(val.name);
		if (strlen(val.name) > 12) {
			puts("User name is too long!");
			return false;
		}
		for (int i = 0; i < strlen(val.name); i++) {
			if ('0' <= val.name[i] && val.name[i] <= '9') {
				puts("Error!Please input alpha!");
				return false;
			}
		}
		//getchar();
		//getchar();
		printf("Please input in turn(Chinese,Math,English,PE):\n");
		//while (getchar() != '\n')
		//	continue;
		if (scanf("%d%d%d%d", &val.ch, &val.math, &val.en, &val.pe) != 4 || val.ch > 100 || val.ch < 0 ||
			val.en > 100 || val.math > 100 || val.math < 0 || val.pe > 100 || val.pe < 0) {
			puts("Error!Please input correct item!");
			while (getchar() != '\n')
				continue;
			return;
		}
		pnew = (List)malloc(sizeof(Node));
		copy(val, pnew);
		p->next = pnew;
		pnew->next = NULL;
		puts("Suessfully!");
	}
	else
		puts("Error!The username already exist!");
	getchar();
	return;
}
void traverse_list(List head)
{
	List p = head->next;
	puts("\t\t语文\t\t数学\t\t英语\t\t体育");
	while (p)
	{
		printf("-------------------------------------------------------------------------------------------------------\n\
NAME:%s\t\tID:%s\nSCORE:\t\t%d\t\t%d\t\t%d\t\t%d\t\
RANKING(总成绩排名):%d\n\
\
",
p->item.name, p->item.id, p->item.ch, p->item.math, p->item.en, p->item.pe, p->item.ranking);
		p = p->next;
	}
	printf("-------------------------------------------------------------------------------------------------------\n");
	return;
}
int length(List head)
{
	List p = head->next;
	int len = 0;
	while (p != NULL)
	{
		++len;
		p = p->next;
	}
	return len;
}
bool insert(List head, int pos)
{
	int i = 0;
	List p = head;
	Item val;
	while (NULL != p && i < pos - 1)
	{
		p = p->next;
		++i;
	}
	if (i > pos - 1 || NULL == p)
		return false;
	//分配新的
	List pnew = (List)malloc(sizeof(Node));
	if (NULL == pnew)
	{
		puts("error!");
		exit(-1);
	}
	//输入
	printf("Please enter the name：\n");
	scanf("%s", val.name);
	printf("Please input in turn(Chinese,Math,English,PE):\n");
	scanf("%d%d%d%d", &val.ch, &val.math, &val.en, &val.pe);
	printf("Please input the student's id:(length == 8)\n");
	scanf("%s", val.id);
	//传值
	copy(val, p);
	//将新的节点存入p的后面
	List q = p->next;
	p->next = pnew;
	pnew->next = q;
	return true;
}
void del_id(List head, char n[L])
{
	List p = head->next, t;
	if (p->next == NULL) {
		if (!strcmp(n, p->item.id)) {
			printf("The student whos id is %s has been delete!\n", p->item.name);
			head->next = NULL;
			return;
		}
	}
	while (p->next != NULL) {
		if (!strcmp(n, p->next->item.id)) {
			t = p->next;
			p->next = t->next;
			printf("The student whos id is %s has been delete!", t->item.id);
			free(t);
			return;
		}
		p = p->next;
	}
	printf("Not found\n");
	return;
}
void del_name(List head, char s[])
{
	List p = head->next, t;
	if (p->next == NULL) {
		if (!strcmp(p->item.name, s)) {
			printf("The student whos name is %s has been delete!\n", p->item.name);
			head->next = NULL;
			return;
		}
	}
	while (p->next != NULL) {
		if (!strcmp(p->next->item.name, s)) {
			t = p->next;
			p->next = t->next;
			printf("The student whos name is %s has been delete!\n", t->item.name);
			free(t);
			return;
		}
		p = p->next;
	}
	printf("Not found\n");
	return;
}
bool serach(List head, char s[])//查找学生信息
{
	List p = head->next;
	while (p) {
		if (!strcmp(p->item.id, s)) {
			puts("The student whom you search has been found!");
			printf("---------------------------------------------------------\n\t\
---------------------------------------------------------\n\
			NAME:%s\t\t\tID:%s\nSCORE: Chinese:%d  Math:%d  English:%d  PE:%d\
\t\tRANKING(总成绩排名):%d",
p->item.name, p->item.id, p->item.ch, p->item.math, p->item.en, p->item.pe, p->item.ranking);
			return true;
		}
		p = p->next;
	}
	//puts("Not found!");
	return false;
}
void revamp(List head, char s[])
{
	List p = head->next;
	Item val;
	FILE * load = fopen("b.txt", "r");//读取
	FILE * save = fopen("a.txt", "w");//存储
	while (p != NULL) {
		if (!strcmp(p->item.id, s)) {
			puts("The student whom you search has been found!");
			printf("---------------------------------------------------------\n\t\
			NAME:%s\t\t\tID:%s\nSCORE: Chinese:%d  Math:%d  English:%d  PE:%d\n",
				p->item.name, p->item.id, p->item.ch, p->item.math, p->item.en, p->item.pe);
			puts("Now,please enter the new message!");
			printf("Please input in turn(Chinese,Math,English,PE):\n");
			if (scanf("%d%d%d%d", &val.ch, &val.math, &val.en, &val.pe) != 4 || val.ch > 100 || val.ch < 0 ||
				val.en > 100 || val.math > 100 || val.math < 0 || val.pe > 100 || val.pe < 0) {
				puts("Error!Please input correct item!");
				while (getchar() != '\n')
					continue;
				return;
			}
			p->item.ch = val.ch;
			p->item.math = val.math;
			p->item.en = val.en;
			p->item.pe = val.pe;
			puts("The message has been revamped successfully!\nThe new message:\n");
			printf("---------------------------------------------------------\n\t\
			NAME:%s\t\t\tID:%s\nSCORE: Chinese:%d  Math:%d  English:%d  PE:%d\n",
				p->item.name, p->item.id, p->item.ch, p->item.math, p->item.en, p->item.pe);
			break;
		}
		p = p->next;
	}
	puts("Not found!");
	getchar();
	return;
}
static void copy(Item item, List p)
{
	p->item = item;
}
void screen(void)
{
	putchar('\n');
	putchar('\n');
	printf("\t\t************************** Student management system ***********************************\t\t\n");
	printf("\t\t*          1.add                                         （添加）                      *\t\t\n");
	printf("\t\t*          2.delete a student                            （删除）                      *\t\t\n");
	printf("\t\t*          3.revamp a student's message                  （修改）                      *\t\t\n");
	printf("\t\t*          4.search a student(use student id)            （查找）                      *\t\t\n");
	printf("\t\t*          5.save message                                （保存）                      *\t\t\n");
	printf("\t\t*          6.search the students who passed all subjects （查看已通过所有科目的学生）  *\t\t\n");
	printf("\t\t*          7.sort  grade(by your heart)                  （排序）                      *\t\t\n");
	printf("\t\t*          8.back                                        （返回）                      *\t\t\n");
	printf("\t\t*          9.view all data                               （查看所有学生）              *\t\t\n");
	printf("\t\t*          10.analyze                                    （成绩分析）                  *\t\t\n");
	printf("\t\t*                                                        Administrator                 *\t\t\n");
	printf("\t\t******************************** Thanks for using!  ************************************\t\t\n");
}
bool save0(List head)
{
	FILE * save = fopen("student.txt", "w");
	if (save == NULL) {
		puts("Error!");
		return false;
	}
	List p = head->next;
	while (p) {
		fprintf(save, "%s %d %d %d %d %s\n",
			p->item.name, p->item.ch, p->item.math, p->item.en, p->item.pe, p->item.id);
		p = p->next;
	}
	fclose(save);
	return true;
}
bool load0(List head)
{
	FILE * load = fopen("student.txt", "r");
	if (load == NULL) {
		puts("Error!");
		return false;
	}
	Item val;
	List p = head, pnew;
	while (!feof(load)) {
		fscanf(load, "%s %d %d %d %d %s\n", val.name, &val.ch, &val.math, &val.en, &val.pe, val.id);
		while (p->next != NULL) {
			p = p->next;
		}
		pnew = (List)malloc(sizeof(Node));
		copy(val, pnew);
		p->next = pnew;
		pnew->next = NULL;
	}
	fclose(load);
	return true;
}
bool logAdministrator(void)//管理员登陆
{
	char n[200], pass[200] = { 0 };
	char t_n[20], t_pass[20];//真正的账号和密码
	char ch;//临时字符
	FILE * fp = fopen("super.txt", "r");
	fscanf(fp, "%s\n%s\n", t_n, t_pass);
	puts("Please input Administrator name:");
	scanf("%s", n);
	if (strcmp(n, t_n)) {
		puts("Administrator name or password is error!");
		return false;
	}
	puts("Please input Administrator password:");
	int i = 0;
	while ((ch = getch()) != '\r') {
		if (ch == 8) {
			if (i > 0) {
				i--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			else {
				putchar('\a');
			}
		}
		if (!isdigit(ch) && !isalpha(ch)) {
			continue;
		}
		putchar('*');
		pass[i++] = ch;
	}
	pass[i] = '\0';
	//puts(pass);
	if (!strcmp(n, t_n) && !strcmp(pass, t_pass)) {
		//puts("Success!\n");
		putchar('\n');
		return true;
	}
	puts("\nAdministrator name or password is error!");
	return false;
}
bool load_user(List2 head2)
{
	List2 prev, p;
	FILE * fp1 = fopen("message.txt", "r");
	if (fp1 == NULL) {
		puts("Error!");
		exit(-1);
		return false;
	}
	p = head2->next;
	prev = head2;
	//全部读取
	while (!feof(fp1)) {
		p = (List2)malloc(sizeof(Node2));
		p->next = NULL;
		prev->next = p;
		fscanf(fp1, "%s\n%s\n", p->item.name, p->item.password);
		prev = p;
		p = p->next;
	}
	fclose(fp1);
	return true;
}
bool login(List2 head2)//登陆
{
	puts("Login");
	puts("-----------------------------------------------------------------------------------------------");
	char n[20], pass[20] = { 0 };//临时存储
	char ch;
	List2 p = head2->next;
	puts("Please input your name:");
	//puts("-----------------------------------------------------------------------------------------------");
	gets(n);
	while (p) {
		if (strcmp(p->item.name, n) == 0) {
			puts("Please input password:");
			int i = 0;
			while ((ch = getch()) != '\r') {
				if (ch == 8) {
					if (i > 0) {
						i--;
						putchar('\b');
						putchar(' ');
						putchar('\b');
					}
					else {
						putchar('\a');
					}
				}
				if (!isdigit(ch) && !isalpha(ch)) {
					continue;
				}
				putchar('*');
				pass[i++] = ch;
			}
			pass[i] = '\0';
			putchar('\n');
			if (strcmp(p->item.password, pass) == 0) {
				puts("Right!");
				return true;
			}
			else {
				puts("Error!");
				return false;
			}
		}
		p = p->next;
	}
	return false;
}
bool registe(List2 head2)//注册
{
	char n[200], pass[200] = { 0 };
	char ch;
	FILE * fp2 = fopen("message.txt", "a+");
	puts("Please input your name:(length: 1 ~ 12)");
	scanf("%s", n);
	if (strlen(n) > 12) {
		puts("User name is too long!");
		return false;
	}
	for (int i = 0; i < strlen(n); i++) {
		if (!isalpha(n[i])) {
			puts("Error!Please input alpha(英文字母)！");
			return false;
		}
	}
	if (user_chachong(head2, n)) {
		puts("Please input your password:(length: 8 ~ 12)");
		int i = 0;
		while ((ch = getch()) != '\r') {
			if (ch == 8) {
				if (i > 0) {
					i--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
				else {
					putchar('\a');
				}
			}
			if (!isdigit(ch) && !isalpha(ch)) {
				continue;
			}
			putchar('*');
			pass[i++] = ch;
		}
		pass[i] = '\0';
		if (strlen(pass) > 13) {
			puts("\nUser password is too long!");
			return false;
		}
		else if (strlen(pass) < 8) {
			puts("\nUser password is too short!");
			return false;
		}
		fprintf(fp2, "\n%s\n%s", n, pass);
		fclose(fp2);
		printf("\nSuessfully!\n");
		puts("现在您可以通过账号登陆学生端了！");
		return true;
	}
	else {
		puts("\nError!The user name already exists.");
		return false;
	}
}
void begin(void)
{
	putchar('\n');
	putchar('\n');
	printf("\t\t**************************           Login           ***************************\t\t\n");
	printf("\t\t*          1.     Administrator login               （管理员登陆）             *\t\t\n");
	printf("\t\t*          2.     Student login                     （学生登陆）               *\t\t\n");
	printf("\t\t*          3.     registe a new account             （注册一个学生账号）       *\t\t\n");
	printf("\t\t*          4.     exit                                                         *\t\t\n");
	printf("\t\t*                                                                              *\t\t\n");
	printf("\t\t*                                          欢迎使用学生管理系统（汉化版）      *\t\t\n");
	printf("\t\t************************************************    汉化：开朗的男子   *********\t\t\n");
}
void screen_s(void)
{
	putchar('\n');
	putchar('\n');
	printf("\t\t************************** Student management system ***************************\t\t\n");
	printf("\t\t*          1.search your mark                                                  *\t\t\n");
	printf("\t\t*                                                              Student         *\t\t\n");
	printf("\t\t******************************** Thanks for using!  ****************************\t\t\n");
}
bool user_chachong(List2 head2, char s[])//用户名查重
{
	List2 p = head2->next;
	while (p) {
		if (!strcmp(s, p->item.name)) {
			return false;
		}
		p = p->next;
	}
	return true;
}
bool id_chachong(List head, char id[])//学号查重
{
	List p = head->next;
	while (p) {
		if (!strcmp(id, p->item.id)) {
			return false;
		}
		p = p->next;
	}
	return true;
}
bool sort_all(List head)
{
	int len = length(head);
	if (head->next == NULL) {
		return false;
	}
	Item val;
	List p, q;
	int i, j;
	p = (List)malloc(sizeof(Node));
	q = (List)malloc(sizeof(Node));
	int sum1 = p->item.ch + p->item.pe + p->item.en + p->item.math;
	for (i = 0, p = head->next; i < len - 1; i++, p = p->next) {
		for (j = i + 1, q = p->next; j < len; ++j, q = q->next) {
			int sum_p = p->item.ch + p->item.pe + p->item.en + p->item.math;
			int sum_q = q->item.ch + q->item.pe + q->item.en + q->item.math;
			if (sum_p < sum_q) {
				val = p->item;
				p->item = q->item;
				q->item = val;
			}
		}
	}
	p = head->next;
	i = 1;
	while (p) {
		p->item.ranking = i++;
		p = p->next;
	}
	//reverse(head);
	return true;
}
void sort_screen(void)
{
	putchar('\n');
	putchar('\n');
	printf("\t\t**************************           Sort            ***************************\t\t\n");
	printf("\t\t*          1.     Chinese ranking                                              *\t\t\n");
	printf("\t\t*          2.     Math ranking                                                 *\t\t\n");
	printf("\t\t*          3.     English ranking                                              *\t\t\n");
	printf("\t\t*          4.     Pe      ranking                                              *\t\t\n");
	printf("\t\t*          5.     Overall ranking                                              *\t\t\n");
	printf("\t\t*          6.     Return to the previous menu.                                 *\t\t\n");
	printf("\t\t******************************** By : Cheerful man  ****************************\t\t\n");
}
bool analyze(List head)
{
	List p = head->next;
	int all = length(head);
	int sum_s = length(head);
	float avg_c = 0, avg_m = 0, avg_e = 0, avg_p = 0, avg = 0;
	int passing_c = 0, passing_m = 0, passing_e = 0, passing_p = 0, pass = 0;
	if (head->next == NULL) {
		return false;
	}
	while (p) {
		if (p->item.ch >= 60) {
			passing_c++;
		}
		if (p->item.math >= 60) {
			passing_m++;
		}
		if (p->item.en >= 60) {
			passing_e++;
		}
		if (p->item.pe >= 60) {
			passing_p++;
		}
		if (p->item.ch >= 60 && p->item.math >= 60 && p->item.en >= 60 && p->item.pe >= 60) {
			pass++;
		}
		avg_c += p->item.ch;
		avg_m += p->item.math;
		avg_e += p->item.en;
		avg_p += p->item.pe;
		avg += p->item.ch + p->item.math + p->item.en + p->item.pe;
		p = p->next;
	}
	avg_c /= sum_s;
	avg_m /= sum_s;
	avg_e /= sum_s;
	avg_p /= sum_s;
	avg /= sum_s;
	puts("Average Score（平均分）");
	puts("-----------------------------------------------------------------------------------------------");
	printf("Chinese:%.2f\t\t\tPASS:%d\t\t\tFAIL:%d\n", avg_c, passing_c, all - passing_c);
	puts("-----------------------------------------------------------------------------------------------");
	printf("Math:%.2f\t\t\tPASS:%d\t\t\tFAIL:%d\n", avg_m, passing_m, all - passing_m);
	puts("-----------------------------------------------------------------------------------------------");
	printf("English:%.2f\t\t\tPASS:%d\t\t\tFAIL:%d\n", avg_e, passing_e, all - passing_e);
	puts("-----------------------------------------------------------------------------------------------");
	printf("PE:%.2f\t\t\tPASS:%d\t\t\tFAIL:%d\n", avg_p, passing_p, all - passing_p);
	puts("-----------------------------------------------------------------------------------------------");
	printf("Total score:%.2f\t\tPASS:%d\t\t\tFAIL:%d\n", avg, pass, all - pass);
	puts("-----------------------------------------------------------------------------------------------");
	return true;
}
bool serach2(List head)//组合查询
{
	List p = head->next;
	if (head->next == NULL) {
		puts("No data!");
		return false;
	}
	int i = 0;
	printf("Students who have passed all the subjects:\n");
	printf("-----------------------------------------------\n");
	while (p) {
		if (p->item.ch >= 60 && p->item.math >= 60 && p->item.en >= 60 && p->item.pe >= 60) {
			printf("%s\n", p->item.name);
		}
		p = p->next;
	}
	printf("\n---------------   END  -------------------\n\n");
	p = head->next;
	printf("Students who have didn't pass all the subjects:\n");
	printf("-----------------------------------------------\n");
	while (p) {
		if (p->item.ch < 60 || p->item.math < 60 || p->item.en < 60 || p->item.pe < 60) {
			printf("%s\n", p->item.name);
		}
		p = p->next;
	}
	printf("\n---------------   END  -------------------\n\n");
	return true;
}
bool reverse(List head)
{
	List q, p;
	p = head->next;
	if (head->next == NULL) {
		puts("No data!");
		return false;
	}
	head->next = NULL;
	while (p) {
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
	return true;
}
bool sort_math(List head)
{
	List p, pre, tail;
	if (head->next == NULL) {
		return false;
	}
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail) {
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if (p->next->item.math < p->item.math) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	return true;
}
bool sort_ch(List head)
{
	List p, pre, tail, t;
	if (head->next == NULL) {
		return false;
	}
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail) {
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if (p->next->item.ch < p->item.ch) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	return true;
}
bool sort_pe(List head)
{
	List p, pre, tail, t;
	if (head->next == NULL) {
		return false;
	}
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail) {
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if (p->next->item.pe < p->item.pe) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	return true;
}
bool sort_en(List head)
{
	List p, pre, tail, t;
	if (head->next == NULL) {
		return false;
	}
	tail = NULL;
	pre = head;
	while ((head->next->next) != tail) {
		p = head->next;
		pre = head;
		while (p->next != tail) {
			if (p->next->item.en < p->item.en) {
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = pre->next;
			}
			p = p->next;
			pre = pre->next;
		}
		tail = p;
	}
	return true;
}