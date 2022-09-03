#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

#define MAXSIZE 66
#define MAX_NAME 66
#define MAX_ID 66

using namespace std;
typedef struct 
{
	char id[MAX_ID];
	char name[MAX_NAME];
}RES;
//插入 
void Insert1(RES l[], int* len) //添加
{
	int num;
	cout << "添加客人的数量为:";
	cin>>num;
	for (int i = *len; i < *len + num; i++) 
	{
		cout<< "----------这是第"<<i+1<<"位客人----------\n";
		cout << "输入客人卡号:\n";
		cin>>l[i].id;
		for (int j = 0; j < i; j++) 
		{
			while(strcmp(l[i].id, l[j].id) == 0 && i != 0) 
			{
				cout << "卡号重复，请重新输入！\n";
				strcpy_s(l[i].id, "");
				cin>>l[i].id;	
			}
		}//id查重 
		cout << "输入姓名:\n";
		cin>>l[i].name;
		cout << "---------------------------------\n";
	}
	*len = *len + num;
}
void Insert2(RES l[], int* len) //中间插入
{
	int k,i;
	cout << "请输入要插入到哪个位置（序号）之前：";
	cin >> i;
	if (i > *len) 
	{
		i = *len;
	}
	else if (i < 1)
	{
		i = 1;
	}
	for (k = *len; k >= i; k--)
	{
		strcpy_s(l[k].id, l[k - 1].id);
		strcpy_s(l[k].name, l[k - 1].name);
	}
	cout << "输入客人卡号:\n";
	cin >> l[i-1].id;
	for (int j = 0; j<i-1; j++)
	{
		while(strcmp(l[i-1].id, l[j].id) == 0 && i != 0)
		{
			cout << "卡号重复，请重新输入！\n";
			strcpy_s(l[i - 1].id, "");
			cin >> l[i-1].id;
		}
	}
	for (int j = i; j <=*len; j++)
	{
		while (strcmp(l[i - 1].id, l[j].id) == 0 && i != 0)
		{
			cout << "卡号重复，请重新输入！\n";
			strcpy_s(l[i - 1].id, "");
			cin >> l[i - 1].id;
		}
	}//id查重
	cout << "输入姓名:\n";
	cin >> l[i-1].name;
	cout << "---------------------------------\n";
	*len += 1;
}

//按姓名查找 
void Search(RES l[], int* len) 
{
	char n[MAX_ID];
	int flag = 0;//flag=0没找到，=1找到 
	cout << "要找的客人姓名为:\n";
	cin>>n;
	for (int i = 0; i < *len; i++) 
	{
		if (strcmp(l[i].name, n) == 0) 
		{
			flag = 1;
			cout << "----------该客人已找到,他的信息如下-----------\n";
			cout << "他是第" << i + 1 << "个客人\n";
			cout << "他的卡号是:"<<l[i].id<<"\n";
			cout << "他的姓名是:"<<l[i].name<<"\n";
			cout << "----------------------------------------------\n";
		}
	}
	if (!flag)
	{
		cout<<"--------------未找到该客人!---------------\n";
	}
}

void Delete1(RES l[], int* len)//按位置删除
{
	int i,k;
	cout << "请输入要删除的客人所在的位置:";
	cin >> i;
	if (i>*len) 
	{
		cout<<" 没有这么多人!\n ";
		return;
	}
	if (i < 1) 
	{
		i = 1;
	}
	for (k = i; k < *len; k++)
	{
		strcpy_s(l[k-1].id, l[k].id);
		strcpy_s(l[k-1].name, l[k].name);
	}
	*len = *len - 1;
	return;
}

void Delete2(RES l[], int* len)//安排就餐
{
	int k;
	for (k = 1; k < *len; k++)
	{
		strcpy_s(l[k - 1].id, l[k].id);
		strcpy_s(l[k - 1].name, l[k].name);
	}
	*len = *len - 1;
	return;
}
void BubleSort(RES l[], int* len)//排序
{
	char temp1[66] = "";
	char temp2[66] = "";
	for (int i = 1; i < *len; i++) 
	{
		for (int j = 0; j < *len - i; j++) 
		{
			if (strcmp(l[j].id, l[j + 1].id) > 0)
			{
				strcpy_s(temp1,l[j].id);
				strcpy_s(temp2, l[j].name);
				strcpy_s(l[j].id,l[j + 1].id);
				strcpy_s(l[j].name, l[j + 1].name);
				strcpy_s(l[j + 1].id ,temp1);
				strcpy_s(l[j + 1].name, temp2);
			}
		}
	}
}
//按顺序输出显示 
void Display(RES l[], int* len) 
{
	cout << "**************************************\n";
	for (int i = 0; i < *len; i++) 
	{
		cout << "----------第"<<i+1<<"个客人的信息----------\n";
		cout << "客人的卡号:"<<l[i].id<<"\n";
		cout << "客人的名字:"<<l[i].name<<"\n" ;
		cout << "------------------------------------\n";
	}
	cout << "**************************************\n";
}
//菜单界面 
void menu() 
{
	cout <<"---------食堂排队管理系统----------\n";
	cout <<"输入1添加          输入2查找       \n";
	cout <<"输入3删除          输入4显示       \n";
	cout <<"输入5安排就餐      输入6中间插入   \n";
	cout <<"输入7按卡号排序    输入0退出       \n";
	cout <<"-----------------------------------\n";
}
int main() 
{
	RES l[MAXSIZE];
	int len = 0;//当前长度 
	int choice;
	while (1) 
	{
		cout << "\n        ##当前有" << len << "人排队！##\n";
		menu();
		cin >> choice;
		switch (choice) //选择模式
        {                       
		case 1:
			Insert1(l, &len); //1、添加
			Display(l, &len);
			break;     
		case 2:
			Search(l, &len); //2、按姓名查找
			break;     
		case 3:
			Delete1(l, &len); //3、删除
			Display(l, &len);
			break;     
		case 4:
			Display(l, &len); //4、显示
			break;
		case 5:
			Delete2(l, &len); //5、安排就餐
			cout << "\n已安排队伍的第一个客人就餐！\n";
			Display(l, &len);
			break;
		case 6:
			Insert2(l, &len);//6、中间插入
			Display(l, &len);
			break;
		case 7:
			BubleSort(l, &len);//按卡号排序
			Display(l, &len);
			break;
		case 0:
			exit(0);          //0、退出
		default:
			cout << "输入错误！";
		}
	}
	return 0;
}