#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string name[5]={"dragon","ninja","iceman","lion","wolf"};
	string weapon[3]={"sword","bomb","arrow"};
	int orderRed[5]={2,3,4,1,0};
	int orderBlue[5]={3,0,1,2,4};
	
	int t;
	cin>>t;
	for (int caseNumber=1;caseNumber<=t;caseNumber++)
	{
		int M,N,K,T;
		cin>>M>>N>>K>>T;
		int life[5],attack[5];
		for (int i=0;i<5;i++)
		{
			cin>>life[i];
		}
		for (int i=0;i<5;i++)
		{
			cin>>attack[i];
		}
		
		cout<<"Case "<<caseNumber<<":"<<endl;
		
		int lifeRed=M;
		int lifeBlue=M;
		int numRed=0;
		int numBlue=0;
		bool createRed=1;
		bool createBlue=1; 
		vector<int> warriorRed;
		vector<int> warriorBlue;
		vector<int> positionRed;
		vector<int> positionBlue;
		vector<int> attackRed;
		vector<int> attackBlue;
		vector< vector<int> > weaponRed; //{swordNum,bombNum,arrowNum,usedarrowNum}
		vector< vector<int> > weaponBlue;
		vector<int> energyRed;
		vector<int> energyBlue;
		vector<int> loyaltyRed;
		vector<int> loyaltyBlue;
		vector<bool> aliveRed;
		vector<bool> aliveBlue;
		
		vector< vector<int> > warriorCity; //{numberRed,numberBlue}
		vector<int> temp;
		temp.push_back(0);
		temp.push_back(0);
		for (int i=0;i<=N+1;i++)
		{
			warriorCity.push_back(temp);
		}
		
		bool flag=0;
		
		for (int time=0;time<=T;time++)
		{
			int hour=time/60,minute=time%60;
			// 双方的司令部中各有一个武士降生
			if (minute==0)
			{
				if (createRed==1)
				{
					int index=orderRed[hour%5];
					if (life[index]>lifeRed)
					{
						createRed=0;
					}
					else
					{
						printf("%03d:00",hour);
						cout<<" red "<<name[index]<<" "<<hour+1<<" born"<<endl;
						warriorRed.push_back(index);
						numRed+=1;
						lifeRed-=life[index];
						positionRed.push_back(0);
						vector<int> w;
						w.push_back(0);
						w.push_back(0);
						w.push_back(0);
						w.push_back(0);
						loyaltyRed.push_back(0);
						if (name[index]=="dragon")
						{
							w[(hour+1)%3]+=1;
						}
						if (name[index]=="ninja")
						{
							w[(hour+1)%3]+=1;
							w[(hour+2)%3]+=1;
						}
						if (name[index]=="iceman")
						{
							w[(hour+1)%3]+=1;
						}
						if (name[index]=="lion")
						{
							cout<<"Its loyalty is "<<lifeRed<<endl;
							loyaltyRed[numRed-1]=lifeRed;
							w[(hour+1)%3]+=1;
						}
						if (name[index]=="wolf")
						{
							
						}
						weaponRed.push_back(w);
						energyRed.push_back(life[index]);
						aliveRed.push_back(1);
						attackRed.push_back(attack[index]);
						warriorCity[0][0]=hour+1;
					}
				}
				if (createBlue==1)
				{
					int index=orderBlue[hour%5];
					if (life[index]>lifeBlue)
					{
						createBlue=0;
					}
					else
					{
						printf("%03d:00",hour);
						cout<<" blue "<<name[index]<<" "<<hour+1<<" born"<<endl;
						warriorBlue.push_back(index);
						numBlue+=1;
						lifeBlue-=life[index];
						positionBlue.push_back(N+1);
						vector<int> w;
						w.push_back(0);
						w.push_back(0);
						w.push_back(0);
						w.push_back(0);
						loyaltyBlue.push_back(0);
						if (name[index]=="dragon")
						{
							w[(hour+1)%3]+=1;
						}
						if (name[index]=="ninja")
						{
							w[(hour+1)%3]+=1;
							w[(hour+2)%3]+=1;
						}
						if (name[index]=="iceman")
						{
							w[(hour+1)%3]+=1;
						}
						if (name[index]=="lion")
						{
							cout<<"Its loyalty is "<<lifeBlue<<endl;
							loyaltyBlue[numBlue-1]=lifeBlue;
							w[(hour+1)%3]+=1;
						}
						if (name[index]=="wolf")
						{
							
						}
						weaponBlue.push_back(w);
						energyBlue.push_back(life[index]);
						aliveBlue.push_back(1);
						attackBlue.push_back(attack[index]);
						warriorCity[N+1][1]=hour+1;
					}
				}
			}
			
			// 该逃跑的lion就在这一时刻逃跑了
			if (minute==5)
			{
				for (int i=0;i<=N+1;i++)
				{
					int a=warriorCity[i][0],b=warriorCity[i][1];
					if (a!=0)
					{
						if (name[warriorRed[a-1]]=="lion" && loyaltyRed[a-1]<=0 && aliveRed[a-1]==1)
						{
							printf("%03d:05",hour);
							cout<<" red lion "<<a<<" ran away"<<endl;
							aliveRed[a-1]=0;
							int p=positionRed[a-1];
							warriorCity[p][0]=0;
						}
					}
					if (b!=0)
					{
						if (name[warriorBlue[b-1]]=="lion" && loyaltyBlue[b-1]<=0 && aliveBlue[b-1]==1)
						{
							printf("%03d:05",hour);
							cout<<" blue lion "<<b<<" ran away"<<endl;
							aliveBlue[b-1]=0;
							int p=positionBlue[b-1];
							warriorCity[p][1]=0;
						}
					}
				}
			}
			
			// 所有的武士朝敌人司令部方向前进一步
			if (minute==10)
			{
				int cityRed[22]={0},cityBlue[22]={0};
				for (int i=0;i<=N+1;i++)
				{
					if (warriorCity[i][0]!=0)
					{
						cityRed[i+1]=warriorCity[i][0];
					}
					if (warriorCity[i][1]!=0)
					{
						cityBlue[i-1]=warriorCity[i][1];
					}
				}
				for (int i=0;i<=N+1;i++)
				{
					warriorCity[i][0]=cityRed[i];
					warriorCity[i][1]=cityBlue[i];
					if (warriorCity[i][0]!=0)
					{
						int number=warriorCity[i][0];
						positionRed[number-1]+=1;
						if (name[warriorRed[number-1]]=="iceman")
						{
							energyRed[number-1]-=energyRed[number-1]/10;
						}
						if (name[warriorRed[number-1]]=="lion")
						{
							loyaltyRed[number-1]=loyaltyRed[number-1]-K;
						}
					}
					if (warriorCity[i][1]!=0)
					{
						int number=warriorCity[i][1];
						positionBlue[number-1]-=1;
						if (name[warriorBlue[number-1]]=="iceman")
						{
							energyBlue[number-1]-=energyBlue[number-1]/10;
						}
						if (name[warriorBlue[number-1]]=="lion")
						{
							loyaltyBlue[number-1]=loyaltyBlue[number-1]-K;
						}
					}
				}
				if (warriorCity[0][1]!=0)
				{
					printf("%03d:10",hour);
					cout<<" blue "<<name[warriorBlue[warriorCity[0][1]-1]]<<" "<<warriorCity[0][1]<<" reached red headquarter";
					cout<<" with "<<energyBlue[warriorCity[0][1]-1]<<" elements and force "<<attackBlue[warriorCity[0][1]-1]<<endl;
					printf("%03d:10",hour);
					cout<<" red headquarter was taken"<<endl;
					flag=1;
				}
				for (int i=1;i<=N;i++)
				{
					if (warriorCity[i][0]+warriorCity[i][1]!=0)
					{
						if (warriorCity[i][0]*warriorCity[i][1]!=0)
						{
							printf("%03d:10",hour);
							cout<<" red "<<name[warriorRed[warriorCity[i][0]-1]]<<" "<<warriorCity[i][0]<<" marched to city "<<i;
							cout<<" with "<<energyRed[warriorCity[i][0]-1]<<" elements and force "<<attackRed[warriorCity[i][0]-1]<<endl;
							printf("%03d:10",hour);
							cout<<" blue "<<name[warriorBlue[warriorCity[i][1]-1]]<<" "<<warriorCity[i][1]<<" marched to city "<<i;
							cout<<" with "<<energyBlue[warriorCity[i][1]-1]<<" elements and force "<<attackBlue[warriorCity[i][1]-1]<<endl;
						}
						else if (warriorCity[i][0]!=0)
						{
							printf("%03d:10",hour);
							cout<<" red "<<name[warriorRed[warriorCity[i][0]-1]]<<" "<<warriorCity[i][0]<<" marched to city "<<i;
							cout<<" with "<<energyRed[warriorCity[i][0]-1]<<" elements and force "<<attackRed[warriorCity[i][0]-1]<<endl;
						}
						else if (warriorCity[i][1]!=0)
						{
							printf("%03d:10",hour);
							cout<<" blue "<<name[warriorBlue[warriorCity[i][1]-1]]<<" "<<warriorCity[i][1]<<" marched to city "<<i;
							cout<<" with "<<energyBlue[warriorCity[i][1]-1]<<" elements and force "<<attackBlue[warriorCity[i][1]-1]<<endl;
						}
					}
				}
				if (warriorCity[N+1][0]!=0)
				{
					printf("%03d:10",hour);
					cout<<" red "<<name[warriorRed[warriorCity[N+1][0]-1]]<<" "<<warriorCity[N+1][0]<<" reached blue headquarter";
					cout<<" with "<<energyRed[warriorCity[N+1][0]-1]<<" elements and force "<<attackRed[warriorCity[N+1][0]-1]<<endl;
					printf("%03d:10",hour);
					cout<<" blue headquarter was taken"<<endl;					
					flag=1;
				}
			}
			if (flag==1)
			{
				break;
			}
			
			// 在有wolf及其敌人的城市，wolf要抢夺对方的武器
			if (minute==35)
			{
				for (int i=1;i<=N;i++)
				{
					if (warriorCity[i][0]*warriorCity[i][1]!=0)
					{
						int a=warriorCity[i][0],b=warriorCity[i][1];
						if (name[warriorRed[a-1]]=="wolf" && name[warriorBlue[b-1]]=="wolf")
						{
							
						}
						else if (name[warriorRed[a-1]]=="wolf" && weaponRed[a-1][0]+weaponRed[a-1][1]+weaponRed[a-1][2]+weaponRed[a-1][3]<10)
						{
							if (weaponBlue[b-1][0]!=0)
							{
								int x=min(weaponBlue[b-1][0],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
								weaponRed[a-1][0]+=x;
								weaponBlue[b-1][0]-=x;
								printf("%03d:35",hour);
								cout<<" red wolf "<<a<<" took "<<x<<" sword";
								cout<<" from blue "<<name[warriorBlue[b-1]]<<" "<<b<<" in city "<<i<<endl;
							}
							else if (weaponBlue[b-1][1]!=0)
							{
								int x=min(weaponBlue[b-1][1],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
								weaponRed[a-1][1]+=x;
								weaponBlue[b-1][1]-=x;
								printf("%03d:35",hour);
								cout<<" red wolf "<<a<<" took "<<x<<" bomb";
								cout<<" from blue "<<name[warriorBlue[b-1]]<<" "<<b<<" in city "<<i<<endl;
							}
							else if (weaponBlue[b-1][2]+weaponBlue[b-1][3]!=0)
							{
								int cnt=0;
								if (weaponBlue[b-1][2]!=0)
								{
									int x=min(weaponBlue[b-1][2],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
									weaponRed[a-1][2]+=x;
									weaponBlue[b-1][2]-=x;
									cnt+=x;
								}
								if (weaponBlue[b-1][3]!=0)
								{
									int x=min(weaponBlue[b-1][3],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
									weaponRed[a-1][3]+=x;
									weaponBlue[b-1][3]-=x;
									cnt+=x;
								}
								printf("%03d:35",hour);
								cout<<" red wolf "<<a<<" took "<<cnt<<" arrow";
								cout<<" from blue "<<name[warriorBlue[b-1]]<<" "<<b<<" in city "<<i<<endl;
							}
						}
						else if (name[warriorBlue[b-1]]=="wolf" && weaponBlue[b-1][0]+weaponBlue[b-1][1]+weaponBlue[b-1][2]+weaponBlue[b-1][3]<10)
						{
							if (weaponRed[a-1][0]!=0)
							{
								int x=min(weaponRed[a-1][0],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
								weaponBlue[b-1][0]+=x;
								weaponRed[a-1][0]-=x;
								printf("%03d:35",hour);
								cout<<" blue wolf "<<b<<" took "<<x<<" sword";
								cout<<" from red "<<name[warriorRed[a-1]]<<" "<<a<<" in city "<<i<<endl;
							}
							else if (weaponRed[a-1][1]!=0)
							{
								int x=min(weaponRed[a-1][1],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
								weaponBlue[b-1][1]+=x;
								weaponRed[a-1][1]-=x;
								printf("%03d:35",hour);
								cout<<" blue wolf "<<b<<" took "<<x<<" bomb";
								cout<<" from red "<<name[warriorRed[a-1]]<<" "<<a<<" in city "<<i<<endl;
							}
							else if (weaponRed[a-1][2]+weaponRed[a-1][3]!=0)
							{
								int cnt=0;
								if (weaponRed[a-1][2]!=0)
								{
									int x=min(weaponRed[a-1][2],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
									weaponBlue[b-1][2]+=x;
									weaponRed[a-1][2]-=x;
									cnt+=x;
								}
								if (weaponRed[a-1][3]!=0)
								{
									int x=min(weaponRed[a-1][3],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
									weaponBlue[b-1][3]+=x;
									weaponRed[a-1][3]-=x;
									cnt+=x;
								}
								printf("%03d:35",hour);
								cout<<" blue wolf "<<b<<" took "<<cnt<<" arrow";
								cout<<" from red "<<name[warriorRed[a-1]]<<" "<<a<<" in city "<<i<<endl;
							}
						}
					}
				}
			}
			
			// 在有两个武士的城市，会发生战斗
			if (minute==40)
			{
				for (int i=1;i<=N;i++)
				{
					if (warriorCity[i][0]!=0 && warriorCity[i][1]!=0)
					{
						int a=warriorCity[i][0],b=warriorCity[i][1];
						int x=weaponRed[a-1][0]+weaponRed[a-1][1]+weaponRed[a-1][2]+weaponRed[a-1][3];
						int y=weaponBlue[b-1][0]+weaponBlue[b-1][1]+weaponBlue[b-1][2]+weaponBlue[b-1][3];
						int m=x,n=y;
						int usedTimesRed[3]={0},usedTimesBlue[3]={0};
						vector<int> allowedRed;
						vector<int> allowedBlue;
						for (int j=0;j<weaponRed[a-1][0]+weaponRed[a-1][1]+weaponRed[a-1][3];j++)
						{
							allowedRed.push_back(1);
						}
						for (int j=weaponRed[a-1][0]+weaponRed[a-1][1]+weaponRed[a-1][3];j<m;j++)
						{
							allowedRed.push_back(2);
						}
						for (int j=0;j<weaponBlue[b-1][0]+weaponBlue[b-1][1]+weaponBlue[b-1][3];j++)
						{
							allowedBlue.push_back(1);
						}
						for (int j=weaponBlue[b-1][0]+weaponBlue[b-1][1]+weaponBlue[b-1][3];j<n;j++)
						{
							allowedBlue.push_back(2);
						}
						int p=0,q=0;
						if (i%2==0)
						{
							int cycle=0;
							while (x>0 || y>0)
							{
								int tmp1=energyRed[a-1],tmp2=energyBlue[b-1];
								if (y>0)
								{
									while (allowedBlue[q]==0)
									{
										q+=1;
										q%=n;
									}
									if (q<weaponBlue[b-1][0])
									{
										int hurt=attackBlue[b-1]*2/10;
										energyRed[a-1]-=hurt;
										usedTimesBlue[0]+=1;
									}
									else if (q<weaponBlue[b-1][0]+weaponBlue[b-1][1])
									{
										int hurt=attackBlue[b-1]*4/10;
										energyRed[a-1]-=hurt;
										if (name[warriorBlue[b-1]]!="ninja")
										{
											energyBlue[b-1]-=hurt/2;
										}
										allowedBlue[q]-=1;
										usedTimesBlue[1]+=1;
										y-=1;
									}
									else
									{
										int hurt=attackBlue[b-1]*3/10;
										energyRed[a-1]-=hurt;
										allowedBlue[q]-=1;
										usedTimesBlue[2]+=1;
										if (allowedBlue[q]==0)
										{
											y-=1;
										}
									}
									q+=1;
									q%=n;
									if (energyRed[a-1]<=0 || energyBlue[b-1]<=0)
									{
										break;
									}
								}
								if (x>0)
								{
									while (allowedRed[p]==0)
									{
										p+=1;
										p%=m;
									}
									if (p<weaponRed[a-1][0])
									{
										int hurt=attackRed[a-1]*2/10;
										energyBlue[b-1]-=hurt;
										usedTimesRed[0]+=1;
									}
									else if (p<weaponRed[a-1][0]+weaponRed[a-1][1])
									{
										int hurt=attackRed[a-1]*4/10;
										energyBlue[b-1]-=hurt;
										if (name[warriorRed[a-1]]!="ninja")
										{
											energyRed[a-1]-=hurt/2;
										}
										allowedRed[p]-=1;
										usedTimesRed[1]+=1;
										x-=1;
									}
									else
									{
										int hurt=attackRed[a-1]*3/10;
										energyBlue[b-1]-=hurt;
										allowedRed[p]-=1;
										usedTimesRed[2]+=1;
										if (allowedRed[p]==0)
										{
											x-=1;
										}
									}
									p+=1;
									p%=m;
									if (energyRed[a-1]<=0 || energyBlue[b-1]<=0)
									{
										break;
									}
								}
								if (energyRed[a-1]==tmp1 && energyBlue[b-1]==tmp2)
								{
									cycle+=1;
								}
								else
								{
									cycle=0;
								}
								if (cycle>=20)
								{
									break;
								}
							}
						}
						else
						{
							int cycle=0;
							while (x>0 || y>0)
							{
								int tmp1=energyRed[a-1],tmp2=energyBlue[b-1];
								if (x>0)
								{
									while (allowedRed[p]==0)
									{
										p+=1;
										p%=m;
									}
									if (p<weaponRed[a-1][0])
									{
										int hurt=attackRed[a-1]*2/10;
										energyBlue[b-1]-=hurt;
										usedTimesRed[0]+=1;
									}
									else if (p<weaponRed[a-1][0]+weaponRed[a-1][1])
									{
										int hurt=attackRed[a-1]*4/10;
										energyBlue[b-1]-=hurt;
										if (name[warriorRed[a-1]]!="ninja")
										{
											energyRed[a-1]-=hurt/2;
										}
										allowedRed[p]-=1;
										usedTimesRed[1]+=1;
										x-=1;
									}
									else
									{
										int hurt=attackRed[a-1]*3/10;
										energyBlue[b-1]-=hurt;
										allowedRed[p]-=1;
										usedTimesRed[2]+=1;
										if (allowedRed[p]==0)
										{
											x-=1;
										}
									}
									p+=1;
									p%=m;
									if (energyRed[a-1]<=0 || energyBlue[b-1]<=0)
									{
										break;
									}
								}
								if (y>0)
								{
									while (allowedBlue[q]==0)
									{
										q+=1;
										q%=n;
									}
									if (q<weaponBlue[b-1][0])
									{
										int hurt=attackBlue[b-1]*2/10;
										energyRed[a-1]-=hurt;
										usedTimesBlue[0]+=1;
									}
									else if (q<weaponBlue[b-1][0]+weaponBlue[b-1][1])
									{
										int hurt=attackBlue[b-1]*4/10;
										energyRed[a-1]-=hurt;
										if (name[warriorBlue[b-1]]!="ninja")
										{
											energyBlue[b-1]-=hurt/2;
										}
										allowedBlue[q]-=1;
										usedTimesBlue[1]+=1;
										y-=1;
									}
									else
									{
										int hurt=attackBlue[b-1]*3/10;
										energyRed[a-1]-=hurt;
										allowedBlue[q]-=1;
										usedTimesBlue[2]+=1;
										if (allowedBlue[q]==0)
										{
											y-=1;
										}
									}
									q+=1;
									q%=n;
									if (energyRed[a-1]<=0 || energyBlue[b-1]<=0)
									{
										break;
									}
								}
								if (energyRed[a-1]==tmp1 && energyBlue[b-1]==tmp2)
								{
									cycle+=1;
								}
								else
								{
									cycle=0;
								}
								if (cycle>=20)
								{
									break;
								}
							}
						}
						weaponRed[a-1][1]-=usedTimesRed[1];
						if (weaponRed[a-1][3]>=usedTimesRed[2])
						{
							weaponRed[a-1][3]-=usedTimesRed[2];
						}
						else if (weaponRed[a-1][3]+weaponRed[a-1][2]>=usedTimesRed[2])
						{
							weaponRed[a-1][3]=usedTimesRed[2]-weaponRed[a-1][3];
							weaponRed[a-1][2]-=weaponRed[a-1][3];
						}
						else
						{
							weaponRed[a-1][3]=weaponRed[a-1][2]*2+weaponRed[a-1][3]-usedTimesRed[2];
							weaponRed[a-1][2]=0;
						}
						weaponBlue[b-1][1]-=usedTimesBlue[1];
						if (weaponBlue[b-1][3]>=usedTimesBlue[2])
						{
							weaponBlue[b-1][3]-=usedTimesBlue[2];
						}
						else if (weaponBlue[b-1][3]+weaponBlue[b-1][2]>=usedTimesBlue[2])
						{
							weaponBlue[b-1][3]=usedTimesBlue[2]-weaponBlue[b-1][3];
							weaponBlue[b-1][2]-=weaponBlue[b-1][3];
						}
						else
						{
							weaponBlue[b-1][3]=weaponBlue[b-1][2]*2+weaponBlue[b-1][3]-usedTimesBlue[2];
							weaponBlue[b-1][2]=0;
						}
						/*
						cout<<"red "<<name[warriorRed[a-1]]<<" ";
						cout<<weaponRed[a-1][0]<<" "<<weaponRed[a-1][1]<<" "<<weaponRed[a-1][2]<<" "<<weaponRed[a-1][3]<<endl;
						cout<<"blue "<<name[warriorBlue[b-1]]<<" ";
						cout<<weaponBlue[b-1][0]<<" "<<weaponBlue[b-1][1]<<" "<<weaponBlue[b-1][2]<<" "<<weaponBlue[b-1][3]<<endl;
						*/
						if (energyRed[a-1]<=0 && energyBlue[b-1]<=0)
						{
							printf("%03d:40",hour);
							cout<<" both red "<<name[warriorRed[a-1]]<<" "<<a<<" and blue "<<name[warriorBlue[b-1]]<<" "<<b;
							cout<<" died in city "<<i<<endl;
							warriorCity[i][0]=0,warriorCity[i][1]=0;
							aliveRed[a-1]=0,aliveBlue[b-1]=0;
						}
						else if (energyRed[a-1]<=0)
						{
							printf("%03d:40",hour);
							cout<<" blue "<<name[warriorBlue[b-1]]<<" "<<b<<" killed red "<<name[warriorRed[a-1]]<<" "<<a;
							cout<<" in city "<<i<<" remaining "<<energyBlue[b-1]<<" elements"<<endl;
							if (name[warriorBlue[b-1]]=="dragon")
							{
								printf("%03d:40",hour);
								cout<<" blue dragon "<<b<<" yelled in city "<<i<<endl;
							}
							warriorCity[i][0]=0;
							aliveRed[a-1]=0;
							if (weaponRed[a-1][0]!=0)
							{
								int x=min(weaponRed[a-1][0],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
								weaponBlue[b-1][0]+=x;
								weaponRed[a-1][0]-=x;
							}
							if (weaponRed[a-1][1]!=0)
							{
								int x=min(weaponRed[a-1][1],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
								weaponBlue[b-1][1]+=x;
								weaponRed[a-1][1]-=x;
							}
							if (weaponRed[a-1][2]!=0)
							{
								int x=min(weaponRed[a-1][2],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
								weaponBlue[b-1][2]+=x;
								weaponRed[a-1][2]-=x;
							}
							if (weaponRed[a-1][3]!=0)
							{
								int x=min(weaponRed[a-1][3],10-weaponBlue[b-1][0]-weaponBlue[b-1][1]-weaponBlue[b-1][2]-weaponBlue[b-1][3]);
								weaponBlue[b-1][3]+=x;
								weaponRed[a-1][3]-=x;
							}
						}
						else if (energyBlue[b-1]<=0)
						{
							printf("%03d:40",hour);
							cout<<" red "<<name[warriorRed[a-1]]<<" "<<a<<" killed blue "<<name[warriorBlue[b-1]]<<" "<<b;
							cout<<" in city "<<i<<" remaining "<<energyRed[a-1]<<" elements"<<endl;
							if (name[warriorRed[a-1]]=="dragon")
							{
								printf("%03d:40",hour);
								cout<<" red dragon "<<a<<" yelled in city "<<i<<endl;
							}
							warriorCity[i][1]=0;
							aliveBlue[b-1]=0;
							if (weaponBlue[b-1][0]!=0)
							{
								int x=min(weaponBlue[b-1][0],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
								weaponRed[a-1][0]+=x;
								weaponBlue[b-1][0]-=x;
							}
							if (weaponBlue[b-1][1]!=0)
							{
								int x=min(weaponBlue[b-1][1],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
								weaponRed[a-1][1]+=x;
								weaponBlue[b-1][1]-=x;
							}
							if (weaponBlue[b-1][2]!=0)
							{
								int x=min(weaponBlue[b-1][2],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
								weaponRed[a-1][2]+=x;
								weaponBlue[b-1][2]-=x;
							}
							if (weaponBlue[b-1][3]!=0)
							{
								int x=min(weaponBlue[b-1][3],10-weaponRed[a-1][0]-weaponRed[a-1][1]-weaponRed[a-1][2]-weaponRed[a-1][3]);
								weaponRed[a-1][3]+=x;
								weaponBlue[b-1][3]-=x;
							}
						}
						else
						{
							printf("%03d:40",hour);
							cout<<" both red "<<name[warriorRed[a-1]]<<" "<<a<<" and blue "<<name[warriorBlue[b-1]]<<" "<<b;
							cout<<" were alive in city "<<i<<endl;
							if (name[warriorRed[a-1]]=="dragon")
							{
								printf("%03d:40",hour);
								cout<<" red dragon "<<a<<" yelled in city "<<i<<endl;
							}
							if (name[warriorBlue[b-1]]=="dragon")
							{
								printf("%03d:40",hour);
								cout<<" blue dragon "<<b<<" yelled in city "<<i<<endl;
							}
						}
					}
				}
			}
			
			// 司令部报告它拥有的生命元数量
			if (minute==50)
			{
				printf("%03d:50",hour);
				cout<<" "<<lifeRed<<" elements in red headquarter"<<endl;
				printf("%03d:50",hour);
				cout<<" "<<lifeBlue<<" elements in blue headquarter"<<endl;
			}
			
			// 每个武士报告其拥有的武器情况
			if (minute==55)
			{
				for (int i=0;i<=N+1;i++)
				{
					if (warriorCity[i][0]+warriorCity[i][1]!=0)
					{
						if (warriorCity[i][0]!=0)
						{
							int index=warriorCity[i][0];
							printf("%03d:55",hour);
							cout<<" red "<<name[warriorRed[index-1]]<<" "<<index<<" has ";
							cout<<weaponRed[index-1][0]<<" sword "<<weaponRed[index-1][1]<<" bomb "<<weaponRed[index-1][2]+weaponRed[index-1][3]<<" arrow ";
							cout<<"and "<<energyRed[index-1]<<" elements"<<endl;
						}
						if (warriorCity[i][1]!=0)
						{
							int index=warriorCity[i][1];
							printf("%03d:55",hour);
							cout<<" blue "<<name[warriorBlue[index-1]]<<" "<<index<<" has ";
							cout<<weaponBlue[index-1][0]<<" sword "<<weaponBlue[index-1][1]<<" bomb "<<weaponBlue[index-1][2]+weaponBlue[index-1][3]<<" arrow ";
							cout<<"and "<<energyBlue[index-1]<<" elements"<<endl;
						}
					}
				}
				/*
				cout<<endl;
				for (int i=0;i<numRed;i++)
				{
					if (aliveRed[i]==1)
					{
						cout<<i+1<<" "<<name[warriorRed[i]]<<" "<<energyRed[i]<<" "<<attackRed[i]<<" ";
						cout<<weaponRed[i][0]<<" "<<weaponRed[i][1]<<" "<<weaponRed[i][2]<<" "<<weaponRed[i][3]<<endl;
					}
				}
				cout<<endl;
				for (int i=0;i<numBlue;i++)
				{
					if (aliveBlue[i]==1)
					{
						cout<<i+1<<" "<<name[warriorBlue[i]]<<" "<<energyBlue[i]<<" "<<attackBlue[i]<<" ";
						cout<<weaponBlue[i][0]<<" "<<weaponBlue[i][1]<<" "<<weaponBlue[i][2]<<" "<<weaponBlue[i][3]<<endl;
					}
				}
				cout<<endl<<endl;
				*/
			}
		}
	}
	return 0;
}
