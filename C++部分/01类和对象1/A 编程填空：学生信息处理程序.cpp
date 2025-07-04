#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
	string name="";
	int age;
	int number;
	int average[4];
	double score;
public:	
	void input(){
		char c=getchar();
		while (c!=',')
		{
			name+=c;
			c=getchar();
		}
		cin>>age;
		getchar();
		cin>>number;
		for (int i=0;i<4;i++)
		{
			getchar();
			cin>>average[i];
		}
	}
	void calculate(){
		score=0.25*(average[0]+average[1]+average[2]+average[3]);
	}
	void output()
	{
		cout<<name<<","<<age<<","<<number<<","<<score;
	}
};

int main() {
	Student student;        // ������Ķ���
	student.input();        // ��������
	student.calculate();    // ����ƽ���ɼ�
	student.output();       // �������
}
