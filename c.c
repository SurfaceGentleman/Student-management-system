#include"list.h"
int main(void)
{
	printf("Loadng...");
	List2 head2;
	head2 = (List2)malloc(sizeof(Node2));
	head2->next = NULL;
	load_user(head2);
	int x2, x3;
	char x1[200];
	system("CLS");
	List head = creat();
	load0(head);
	sort_all(head);
	bool flag = true;
	bool flag2 = true;
	while (true) {
		begin();
		puts("Please input the number:");
		scanf("%s", x1);
		getchar();
		if (!strcmp("1", x1)) {
			if (logAdministrator())
			{
				puts("Successful!");
				system("CLS");
				flag = true;//每次循环起始为真
				while (flag) {
					screen();
					puts("Please input number:");
					scanf("%d", &x2);
					while (getchar() != '\n') {
						continue;
					}
					switch (x2)
					{
					case 1: {
						tail_insert(head);
						sort_all(head);
						//traverse_list(head);
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						//getchar();
						system("CLS");
						//screen();
						break;
					}
					case 2: {
						char x[20];
						printf("Please choose the way to delete:");
						puts("'1' means id,'2' means name.");
						//while (getchar() != '\n')
						//	continue;
						while (true) {
							scanf("%s", &x);
							if (!strcmp(x, "1")) {
								char i[20];
								printf("Please input the student's id:");
								scanf("%s", i);
								del_id(head, i);
								sort_all(head);
								break;
							}
							else if (!strcmp(x, "2")) {
								char s[20];
								printf("Please input the student's name:");
								scanf("%s", s);
								del_name(head, s);
								sort_all(head);
								break;
							}
							puts("Please corrent item!");
							printf("\nPress Enter（回车键） to continue!");
							getchar();
							break;
						}
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						getchar();
						system("CLS");
						//screen();
						break;
					}
					case 3: {
						char t[20];
						printf("Please enter the student's ID:(8)");
						scanf("%s", t);
						revamp(head, t);
						sort_all(head);
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						system("CLS");
						//screen();
						break;
					}
					case 4: {
						char i[20];
						printf("Please enter the student's ID:(8)");
						scanf("%s", i);
						serach(head, i);
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						getchar();
						system("CLS");
						//screen();
						break;
					}
					case 5: {
						if (save0(head)) {
							printf("\nSuccesefully!");
							printf("\nPress Enter（回车键） to continue!");
							getchar();
							system("CLS");
							//screen();
							break;
						}
						else {
							puts("Error!No data!");
							printf("\nPress Enter（回车键） to continue!");
							getchar();
							system("CLS");
							break;
						}
						break;
					}
					case 6: {
						serach2(head);
						getchar();
						printf("\nPress Enter（回车键） to continue!");
						system("CLS");
						//screen();
						break;
					}
					case 7: {
						system("CLS");
						flag2 = true;
						int x;
						puts("Please input thw way which you want:");
						puts("1:normal\t2:invert");
						scanf("%d", &x);
						while (getchar() != '\n')
							continue;
						system("CLS");
						if (x == 1) {
							while (flag2) {
								sort_screen();
								puts("Please input the way which you want:");
								puts("Please input number:");
								scanf("%d", &x2);
								while (getchar() != '\n')
									continue;
								switch (x2) {
								case 1: {
									sort_ch(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									//fflush(stdin);
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 2: {
									sort_math(head);
									traverse_list(head);
									//getchar();
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									system("CLS");
									break;
								}
								case 3: {
									sort_en(head);
									traverse_list(head);
									//getchar();
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									system("CLS");
									break;
								}
								case 4: {
									sort_pe(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 5: {
									sort_all(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									getchar();
								//	getchar();
									system("CLS");
									break;
								}
								case 6: {
									flag2 = false;
									system("CLS");
									screen();
									break;
								}
								default: {
									puts("Please input correct item!");
									printf("\nPress Enter（回车键） to continue!");
									system("CLS");
									//screen();
									break;
								}
								}
							}
						}
						else if (x == 2) {
							while (flag2) {
								sort_screen();
								puts("Please input the way which you want:");
								puts("Please input number:");
								scanf("%d", &x2);
								while (getchar() != '\n')
									continue;
								switch (x2) {
								case 1: {
									sort_ch(head);
									reverse(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									//fflush(stdin);
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 2: {
									sort_math(head);
									reverse(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 3: {
									sort_en(head);
									reverse(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 4: {
									sort_pe(head);
									reverse(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 5: {
									sort_all(head);
									reverse(head);
									traverse_list(head);
									printf("\nPress Enter（回车键） to continue!");
									getchar();
									//getchar();
									system("CLS");
									break;
								}
								case 6: {
									flag2 = false;
									system("CLS");
									screen();
									break;
								}
								default: {
									puts("Please input correct item!");
									printf("\nPress Enter（回车键） to continue!");
									system("CLS");
									//screen();
									break;
								}
								}
							}
						}
						else {
							puts("Error!");
							printf("\nPress Enter（回车键） to continue!");
							getchar();
						}
						printf("\nPress Enter（回车键） to continue!");
						system("CLS");
						break;
					}
					case 8: {
						flag = false;
						system("CLS");
						//begin();
						break;
					}
					case 9: {
						//sort_all(head);
						traverse_list(head);
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						system("CLS");
						break;
					}
					case 10: {
						if (analyze(head)) {
							printf("\nPress Enter（回车键） to continue!");
							getchar();
							system("CLS");
							break;
						}
						else {
							puts("No data!");
							printf("\nPress Enter（回车键） to continue!");
							getchar();
							system("CLS");
							break;
						}
					}
					default: {
						printf("Please enter the corrent number!\n");
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						system("CLS");
						//screen();
						break;
					}
					}
				}
			}
			else {
				puts("Error!");
				printf("\nPress Enter（回车键） to continue!");
				getchar();
				getchar();
				system("CLS");
				continue;
			}

		}
		else if (!strcmp("2", x1)) {
			bool flag3 = true;
			system("CLS");
			if (login(head2)) {
				//puts("Successful!");
				while (true) {
					puts("-----------------------------------------------------------------------------------------------");
					puts("Please input id:(输入任意字符退出)");
					char x[20];
					scanf("%s", x);
					puts("-----------------------------------------------------------------------------------------------");
					if (serach(head, x)) {
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						getchar();
						system("CLS");
						continue;
					}
					else {
						printf("\nPress Enter（回车键） to continue!");
						getchar();
						getchar();
						system("CLS");
						break;
					}
				}
				continue;
			}
			else {
				puts("Error!");
				printf("\nPress Enter（回车键） to continue!");
				getchar();
				system("CLS");
				continue;
			}
		}
		else if (!strcmp("3", x1)) {
			registe(head2);
			load_user(head2);
			printf("\nPress Enter（回车键） to continue!");
			getchar();
			getchar();
			system("CLS");
			continue;
		}
		else if (!strcmp("4", x1)) {
			puts("Thanks for using!");
			exit(0);
		}
		else {
			puts("Please input correct item!");
			printf("\nPress Enter（回车键） to continue!");
			getchar();
			system("CLS");
			continue;
		}
	}
	return 0;
}
