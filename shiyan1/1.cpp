#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class Sales
{
public:
	string serial;
	int market;
	int posno;
	string date;
	int sn;
	int id;
	float num;
	float price;
	float total;
	void print()
	{
		cout<<serial<<" "<<market<<" "<<posno<<" "<<date<<" "<<sn<<" "
			<<id<<" "<<num<<" "<<price<<" "<<total<<endl;
	}
};
int main()
{
	ofstream outfile("fl.txt",ifstream::app);
	if (!outfile)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	char name[50];
	ifstream infile;
	cout<<"输入要打开的txt文件名：1019.txt，1020.txt，1021.txt"<<endl;
	//int N=3;
	//for (int k=0;k<N;k++)
	//{
		//cout<<"输入要打开的第"<<k+1<<"个文件名"<<endl;
		cin>>name;
		infile.open(name,ios::in);//ifstream infile("1019.txt",ios::in);
		cin.clear();
		/*string contents;*/
		if (infile.fail())
		{
			cout<<"error open!"<<endl;
		}
		//ofstream outfile("fl.txt",ofstream::app);
		//ofstream outfile("fl.txt",ios::out);
		//if (!outfile)
		//{
			//cout<<"open error!"<<endl;
			//exit(1);
		//}
		
		Sales sal[13000];
		int sal_size=0;
		while (!infile.eof())
		{
			infile>>sal[sal_size].serial>>sal[sal_size].market>>sal[sal_size].posno>>sal[sal_size].date>>
				sal[sal_size].sn>>sal[sal_size].id>>sal[sal_size].num>>sal[sal_size].price>>sal[sal_size].total;
			sal_size++;
		}
		cout<<"文档"<<name<<"的长度是："<<sal_size<<endl;
		//char Tc;
		//Tc=getchar();
		//cout<<Tc<<endl;
		int I;
		for (int i=0; i<sal_size;i++)
		{
			//sal[i].print();
			if (sal[i].num<0)
			{
				sal[i].num=-sal[i].num;
			}
			sal[i].date.assign(sal[i].serial,0,8);
			outfile<<sal[i].serial<<"\t"<<sal[i].market<<"\t"<<sal[i].date<<"\t"<<sal[i].sn<<"\t"
				<<sal[i].id<<"\t"<<sal[i].num<<"\t"<<sal[i].price<<endl;
			I=i;
		}
		cout<<"文档fl.txt的长度是："<<sal_size<<"\t"<<I<<endl;
		char TTc;
		cin>>TTc;//TTc=getchar();
		cout<<TTc<<endl;
		infile.close();			
	//}
	outfile.close();
	return 0;
}
