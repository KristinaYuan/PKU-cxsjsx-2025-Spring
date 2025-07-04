#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string name[5]={"dragon","ninja","iceman","lion","wolf"};
	int orderRed[5]={2,3,4,1,0};
	int orderBlue[5]={3,0,1,2,4};
	//string nameRed[5]={"iceman","lion","wolf","ninja","dragon"};
	//string nameBlue[5]={"lion","dragon","ninja","iceman","wolf"};
	for (int k=1;k<=n;k++)
	{
		cout<<"Case:"<<k<<endl;
		int M;
		cin>>M;
		int lifeRed=M,lifeBlue=M;
		int life[5]; //dragon, ninja, iceman, lion, wolf;
		int countRed[5]={0};
		int countBlue[5]={0};
		int mn=10000;
		for (int i=0;i<5;i++)
		{
			cin>>life[i];
			mn=min(mn,life[i]);
		}
		bool flag1=1,flag2=1;
		bool stop1=0,stop2=0;
		int t=0;
		int i=0,j=0;
		if (M<mn)
		{
			flag1=0,flag2=0;
			stop1=1,stop2=1;
		}
		for (;;t++)
		{
			if (flag1==1)
			{
				printf("%03d ",t);
				while (lifeRed<life[orderRed[i]])
				{
					i+=1;
					i%=5;
				}
				countRed[orderRed[i]]+=1;
				cout<<"red "<<name[orderRed[i]]<<" "<<t+1<<" born with strength "<<life[orderRed[i]]<<",";
				cout<<countRed[orderRed[i]]<<" "<<name[orderRed[i]]<<" in red headquarter"<<endl;
				lifeRed-=life[orderRed[i]];
				i+=1;
				i%=5;
				if (lifeRed<mn)
				{
					flag1=0;
					stop1=1;
				}
			}
			else if (stop1==1)
			{
				printf("%03d red headquarter stops making warriors\n",t);
				stop1=0;
			}
			if (flag2==1)
			{
				printf("%03d ",t);
				while (lifeBlue<life[orderBlue[j]])
				{
					j+=1;
					j%=5;
				}
				countBlue[orderBlue[j]]+=1;
				cout<<"blue "<<name[orderBlue[j]]<<" "<<t+1<<" born with strength "<<life[orderBlue[j]]<<",";
				cout<<countBlue[orderBlue[j]]<<" "<<name[orderBlue[j]]<<" in blue headquarter"<<endl;
				lifeBlue-=life[orderBlue[j]];
				j+=1;
				j%=5;
				if (lifeBlue<mn)
				{
					flag2=0;
					stop2=1;
				}
			}
			else if (stop2==1)
			{
				printf("%03d blue headquarter stops making warriors\n",t);
				stop2=0;
			}
			if (flag1==0 && flag2==0 && stop1==0 && stop2==0)
			{
				break;
			}
		}
	}
	return 0;
}
