#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	// dragon,ninja,iceman,lion,wolf
	string nameRed[5]={"iceman","lion","wolf","ninja","dragon"};
	string nameBlue[5]={"lion","dragon","ninja","iceman","wolf"};
	string weapon[3]={"sword","bomb","arrow"};
	
	int t;
	cin>>t;
	
	for (int caseNumber=1;caseNumber<=t;caseNumber++){
		
		// 初始设定 
		int M,N,R,K,T;
		cin>>M>>N>>R>>K>>T;
		map<string,int> life;
		map<string,int> attack;
		cin>>life["dragon"]>>life["ninja"]>>life["iceman"]>>life["lion"]>>life["wolf"];
		cin>>attack["dragon"]>>attack["ninja"]>>attack["iceman"]>>attack["lion"]>>attack["wolf"];
		
		cout<<"Case "<<caseNumber<<":"<<endl;
		
		// 红蓝方情况记录 warriorCity使用编号 其余index为编号-1 
		int lifeRed=M;
		int lifeBlue=M;
		int numRed=0;
		int numBlue=0;
		vector<string> warriorRed;
		vector<string> warriorBlue;
		vector<int> positionRed;
		vector<int> positionBlue;
		vector<int> attackRed;
		vector<int> attackBlue;
		vector< vector<int> > weaponRed; //{swordAttack,bombHave,arrowLeftchances} 为0即视作没有这件武器 
		vector< vector<int> > weaponBlue;
		vector<int> energyRed;
		vector<int> energyBlue;
		vector<int> loyaltyRed; //for lions
		vector<int> loyaltyBlue;
		vector<double> moraleRed; //for dragons
		vector<double> moraleBlue;
		vector<bool> aliveRed;
		vector<bool> aliveBlue;
		int enemyRed=0;
		int enemyBlue=0;
		vector< vector<int> > warriorCity(N+2,vector<int>(2,0)); //{numberRed,numberBlue}
		vector<int> energyCity(N+2,0);
		vector<int> winCity(N+2,0); //Red=1,Blue=2 上次胜利的一方 
		vector<int> flagCity(N+2,0); //Red=1,Blue=2
		bool flag=0;
		
		for (int time=0;time<=T;time++){
			
			int hour=time/60,minute=time%60;
			
			// 双方的司令部中各有一个武士降生
			if (minute==0){
				if (lifeRed>=life[nameRed[numRed%5]]){
					string w=nameRed[numRed%5];
					lifeRed-=life[w];
					numRed+=1;
					warriorRed.push_back(w);
					positionRed.push_back(0);
					attackRed.push_back(attack[w]);
					weaponRed.push_back(vector<int>(3,0));
					energyRed.push_back(life[w]);
					loyaltyRed.push_back(0);
					moraleRed.push_back(0);
					aliveRed.push_back(1);
					warriorCity[0][0]=numRed;
					printf("%03d:00 ",hour);
					cout<<"red "<<w<<" "<<numRed<<" born"<<endl;
					if (w=="dragon"){
						string s=weapon[numRed%3];
						if (s=="sword"){
							weaponRed[numRed-1][0]=attack["dragon"]/5;
						}
						if (s=="bomb"){
							weaponRed[numRed-1][1]=1;
						}
						if (s=="arrow"){
							weaponRed[numRed-1][2]=3;
						}
						double morale=1.0*lifeRed/life["dragon"];
						printf("Its morale is %.2lf\n",morale);
						moraleRed[numRed-1]=morale;
					}
					if (w=="ninja"){
						string s=weapon[numRed%3];
						if (s=="sword"){
							weaponRed[numRed-1][0]=attack["ninja"]/5;
						}
						if (s=="bomb"){
							weaponRed[numRed-1][1]=1;
						}
						if (s=="arrow"){
							weaponRed[numRed-1][2]=3;
						}
						s=weapon[(numRed+1)%3];
						if (s=="sword"){
							weaponRed[numRed-1][0]=attack["ninja"]/5;
						}
						if (s=="bomb"){
							weaponRed[numRed-1][1]=1;
						}
						if (s=="arrow"){
							weaponRed[numRed-1][2]=3;
						}
					}
					if (w=="iceman"){
						string s=weapon[numRed%3];
						if (s=="sword"){
							weaponRed[numRed-1][0]=attack["iceman"]/5;
						}
						if (s=="bomb"){
							weaponRed[numRed-1][1]=1;
						}
						if (s=="arrow"){
							weaponRed[numRed-1][2]=3;
						}
					}
					if (w=="lion"){
						int loyalty=lifeRed;
						loyaltyRed[numRed-1]=loyalty;
						cout<<"Its loyalty is "<<loyalty<<endl;
					}
					if (w=="wolf"){
						
					}
				}
				if (lifeBlue>=life[nameBlue[numBlue%5]]){
					string w=nameBlue[numBlue%5];
					lifeBlue-=life[w];
					numBlue+=1;
					warriorBlue.push_back(w);
					positionBlue.push_back(N+1);
					attackBlue.push_back(attack[w]);
					weaponBlue.push_back(vector<int>(3,0));
					energyBlue.push_back(life[w]);
					loyaltyBlue.push_back(0);
					moraleBlue.push_back(0);
					aliveBlue.push_back(1);
					warriorCity[N+1][1]=numBlue;
					printf("%03d:00 ",hour);
					cout<<"blue "<<w<<" "<<numBlue<<" born"<<endl;
					if (w=="dragon"){
						string s=weapon[numBlue%3];
						if (s=="sword"){
							weaponBlue[numBlue-1][0]=attack["dragon"]/5;
						}
						if (s=="bomb"){
							weaponBlue[numBlue-1][1]=1;
						}
						if (s=="arrow"){
							weaponBlue[numBlue-1][2]=3;
						}
						double morale=1.0*lifeBlue/life["dragon"];
						printf("Its morale is %.2lf\n",morale);
						moraleBlue[numBlue-1]=morale;
					}
					if (w=="ninja"){
						string s=weapon[numBlue%3];
						if (s=="sword"){
							weaponBlue[numBlue-1][0]=attack["ninja"]/5;
						}
						if (s=="bomb"){
							weaponBlue[numBlue-1][1]=1;
						}
						if (s=="arrow"){
							weaponBlue[numBlue-1][2]=3;
						}
						s=weapon[(numBlue+1)%3];
						if (s=="sword"){
							weaponBlue[numBlue-1][0]=attack["ninja"]/5;
						}
						if (s=="bomb"){
							weaponBlue[numBlue-1][1]=1;
						}
						if (s=="arrow"){
							weaponBlue[numBlue-1][2]=3;
						}
					}
					if (w=="iceman"){
						string s=weapon[numBlue%3];
						if (s=="sword"){
							weaponBlue[numBlue-1][0]=attack["iceman"]/5;
						}
						if (s=="bomb"){
							weaponBlue[numBlue-1][1]=1;
						}
						if (s=="arrow"){
							weaponBlue[numBlue-1][2]=3;
						}
					}
					if (w=="lion"){
						int loyalty=lifeBlue;
						loyaltyBlue[numBlue-1]=loyalty;
						cout<<"Its loyalty is "<<loyalty<<endl;
					}
					if (w=="wolf"){
						
					}
				}
			}
			
			// 该逃跑的lion就在这一时刻逃跑了
			if (minute==5){
				for (int i=0;i<=N+1;i++){
					int a=warriorCity[i][0],b=warriorCity[i][1];
					if (a!=0){
						if (warriorRed[a-1]=="lion" && loyaltyRed[a-1]<=0 && aliveRed[a-1]==1){
							printf("%03d:05",hour);
							cout<<" red lion "<<a<<" ran away"<<endl;
							aliveRed[a-1]=0;
							int p=positionRed[a-1];
							warriorCity[p][0]=0;
						}
					}
					if (b!=0){
						if (warriorBlue[b-1]=="lion" && loyaltyBlue[b-1]<=0 && aliveBlue[b-1]==1){
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
			if (minute==10){
				int cityRed[22]={0},cityBlue[22]={0};
				for (int i=0;i<=N+1;i++){
					if (warriorCity[i][0]!=0){
						cityRed[i+1]=warriorCity[i][0];
					}
					if (warriorCity[i][1]!=0){
						cityBlue[i-1]=warriorCity[i][1];
					}
				}
				for (int i=0;i<=N+1;i++){
					warriorCity[i][0]=cityRed[i];
					warriorCity[i][1]=cityBlue[i];
					if (warriorCity[i][0]!=0){
						int number=warriorCity[i][0];
						positionRed[number-1]+=1;
						if (warriorRed[number-1]=="iceman" && positionRed[number-1]%2==0){
							energyRed[number-1]=max(energyRed[number-1]-9,1);
							attackRed[number-1]+=20;
						}
					}
					if (warriorCity[i][1]!=0){
						int number=warriorCity[i][1];
						positionBlue[number-1]-=1;
						if (warriorBlue[number-1]=="iceman" && (N+1-positionBlue[number-1])%2==0){
							energyBlue[number-1]=max(energyBlue[number-1]-9,1);
							attackBlue[number-1]+=20;
						}
					}
				}
				if (warriorCity[0][1]!=0){
					printf("%03d:10 ",hour);
					cout<<"blue "<<warriorBlue[warriorCity[0][1]-1]<<" "<<warriorCity[0][1]<<" reached red headquarter";
					cout<<" with "<<energyBlue[warriorCity[0][1]-1]<<" elements and force "<<attackBlue[warriorCity[0][1]-1]<<endl;
					enemyRed+=1;
					if (enemyRed==2){
						printf("%03d:10 ",hour);
						cout<<"red headquarter was taken"<<endl;
						flag=1;
					}
				}
				for (int i=1;i<=N;i++){
					if (warriorCity[i][0]+warriorCity[i][1]!=0){
						if (warriorCity[i][0]*warriorCity[i][1]!=0){
							printf("%03d:10",hour);
							cout<<" red "<<warriorRed[warriorCity[i][0]-1]<<" "<<warriorCity[i][0]<<" marched to city "<<i;
							cout<<" with "<<energyRed[warriorCity[i][0]-1]<<" elements and force "<<attackRed[warriorCity[i][0]-1]<<endl;
							printf("%03d:10",hour);
							cout<<" blue "<<warriorBlue[warriorCity[i][1]-1]<<" "<<warriorCity[i][1]<<" marched to city "<<i;
							cout<<" with "<<energyBlue[warriorCity[i][1]-1]<<" elements and force "<<attackBlue[warriorCity[i][1]-1]<<endl;
						}
						else if (warriorCity[i][0]!=0){
							printf("%03d:10",hour);
							cout<<" red "<<warriorRed[warriorCity[i][0]-1]<<" "<<warriorCity[i][0]<<" marched to city "<<i;
							cout<<" with "<<energyRed[warriorCity[i][0]-1]<<" elements and force "<<attackRed[warriorCity[i][0]-1]<<endl;
						}
						else if (warriorCity[i][1]!=0){
							printf("%03d:10",hour);
							cout<<" blue "<<warriorBlue[warriorCity[i][1]-1]<<" "<<warriorCity[i][1]<<" marched to city "<<i;
							cout<<" with "<<energyBlue[warriorCity[i][1]-1]<<" elements and force "<<attackBlue[warriorCity[i][1]-1]<<endl;
						}
					}
				}
				if (warriorCity[N+1][0]!=0){
					printf("%03d:10",hour);
					cout<<" red "<<warriorRed[warriorCity[N+1][0]-1]<<" "<<warriorCity[N+1][0]<<" reached blue headquarter";
					cout<<" with "<<energyRed[warriorCity[N+1][0]-1]<<" elements and force "<<attackRed[warriorCity[N+1][0]-1]<<endl;
					enemyBlue+=1;
					if (enemyBlue==2){
						printf("%03d:10",hour);
						cout<<" blue headquarter was taken"<<endl;
						flag=1;
					}
				}
			}
			
			// 判断是否结束战斗 
			if (flag==1){
				break;
			}
			
			// 每个城市产出10个生命元
			if (minute==20){
				for (int i=1;i<=N;i++){
					energyCity[i]+=10;
				} 
			}
			
			// 武士取走该城市中的所有生命元
			if (minute==30){
				for (int i=1;i<=N+1;i++){
					if (warriorCity[i][0]+warriorCity[i][1]!=0){
						if (warriorCity[i][0]==0){
							lifeBlue+=energyCity[i];
							if (energyCity[i]>0){
								printf("%03d:30 ",hour);
								cout<<"blue "<<warriorBlue[warriorCity[i][1]-1]<<" "<<warriorCity[i][1];
								cout<<" earned "<<energyCity[i]<<" elements for his headquarter"<<endl;
								energyCity[i]=0;
							}
						}
						if (warriorCity[i][1]==0){
							lifeRed+=energyCity[i];
							if (energyCity[i]>0){
								printf("%03d:30 ",hour);
								cout<<"red "<<warriorRed[warriorCity[i][0]-1]<<" "<<warriorCity[i][0];
								cout<<" earned "<<energyCity[i]<<" elements for his headquarter"<<endl;
								energyCity[i]=0;
							}
						}
					}
				}
			}
			
			// 拥有arrow的武士放箭，对敌人造成伤害
			if (minute==35){
				for (int i=1;i<=N;i++){
					if (warriorCity[i][0]!=0 && warriorCity[i+1][1]!=0 && i!=N){
						if (weaponRed[warriorCity[i][0]-1][2]>0){
							energyBlue[warriorCity[i+1][1]-1]-=R;
							weaponRed[warriorCity[i][0]-1][2]-=1;
							printf("%03d:35 ",hour);
							cout<<"red "<<warriorRed[warriorCity[i][0]-1]<<" "<<warriorCity[i][0]<<" shot";
							if (energyBlue[warriorCity[i+1][1]-1]<=0){
								cout<<" and killed blue "<<warriorBlue[warriorCity[i+1][1]-1]<<" "<<warriorCity[i+1][1];
								aliveBlue[warriorCity[i+1][1]-1]=0;
							}
							cout<<endl;
						}
					}
					if (warriorCity[i][1]!=0 && warriorCity[i-1][0]!=0 && i!=0){
						if (weaponBlue[warriorCity[i][1]-1][2]>0){
							energyRed[warriorCity[i-1][0]-1]-=R;
							weaponBlue[warriorCity[i][1]-1][2]-=1;
							printf("%03d:35 ",hour);
							cout<<"blue "<<warriorBlue[warriorCity[i][1]-1]<<" "<<warriorCity[i][1]<<" shot";
							if (energyRed[warriorCity[i-1][0]-1]<=0){
								cout<<" and killed red "<<warriorRed[warriorCity[i-1][0]-1]<<" "<<warriorCity[i-1][0];
								aliveRed[warriorCity[i-1][0]-1]=0;
							}
							cout<<endl;
						}
					}
				}
			}
			
			// 拥有bomb的武士评估是否应该使用bomb
			if (minute==38){
				for (int i=1;i<=N;i++){
					int r=warriorCity[i][0],b=warriorCity[i][1];
					if (r==0 || b==0){
						continue;
					}
					if (aliveRed[r-1]==0 || aliveBlue[b-1]==0){
						continue;
					}
					if (weaponRed[r-1][1]==1 || weaponBlue[b-1][1]==1){
						int ER=energyRed[r-1],EB=energyBlue[b-1];
						int AR=attackRed[r-1],AB=attackBlue[b-1];
						int WR=weaponRed[r-1][0],WB=weaponBlue[b-1][0];
						if (flagCity[i]==1 || (flagCity[i]==0 && i%2==1)){
							EB-=(AR+WR);
							WR=WR*4/5;
							if (EB<=0){
								if (weaponBlue[b-1][1]==1){
									printf("%03d:38 ",hour);
									cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" used a bomb and killed red "<<warriorRed[r-1]<<" "<<r<<endl;
									weaponBlue[b-1][1]=0;
									aliveRed[r-1]=0;
									aliveBlue[b-1]=0;
								}
							}
							else if (warriorBlue[b-1]!="ninja"){
								ER-=(AB/2+WB);
								WB=WB*4/5;
								if (ER<=0){
									if (weaponRed[r-1][1]==1){
										printf("%03d:38 ",hour);
										cout<<"red "<<warriorRed[r-1]<<" "<<r<<" used a bomb and killed blue "<<warriorBlue[b-1]<<" "<<b<<endl;
										weaponRed[r-1][1]=0;
										aliveRed[r-1]=0;
										aliveBlue[b-1]=0;
									}
								}
							}
						}
						else{
							ER-=(AB+WB);
							WB=WB*4/5;
							if (ER<=0){
								if (weaponRed[r-1][1]==1){
									printf("%03d:38 ",hour);
									cout<<"red "<<warriorRed[r-1]<<" "<<r<<" used a bomb and killed blue "<<warriorBlue[b-1]<<" "<<b<<endl;
									weaponRed[r-1][1]=0;
									aliveRed[r-1]=0;
									aliveBlue[b-1]=0;
								}
							}
							else if (warriorRed[r-1]!="ninja"){
								EB-=(AR/2+WR);
								WR=WR*4/5;
								if (EB<=0){
									if (weaponBlue[b-1][1]==1){
										printf("%03d:38 ",hour);
										cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" used a bomb and killed red "<<warriorRed[r-1]<<" "<<r<<endl;
										weaponBlue[b-1][1]=0;
										aliveRed[r-1]=0;
										aliveBlue[b-1]=0;
									}
								}
							}
						}
					}
				}
			}
			
			// 在有两个武士的城市，会发生战斗
			if (minute==40){
				int earnedRed=0;
				int earnedBlue=0;
				vector<int> winRed;
				vector<int> winBlue;
				for (int i=1;i<=N;i++){
					int r=warriorCity[i][0],b=warriorCity[i][1];
					if (r==0 || b==0){
						
					}
					else if (aliveRed[r-1]==0 && aliveBlue[b-1]==0){
						
					}
					else if (aliveRed[r-1]==0){
						if (warriorBlue[b-1]=="dragon"){
							moraleBlue[b-1]+=0.2;
							if ((flagCity[i]==2 || (flagCity[i]==0 && i%2==0)) && moraleBlue[b-1]>0.8){
								printf("%03d:40 ",hour);
								cout<<"blue dragon "<<b<<" yelled in city "<<i<<endl;
							}
						}
						else if (warriorBlue[b-1]=="wolf"){
							if (weaponBlue[b-1][0]==0 && weaponRed[r-1][0]!=0){
								weaponBlue[b-1][0]=weaponRed[r-1][0];
							}
							if (weaponBlue[b-1][1]==0 && weaponRed[r-1][1]!=0){
								weaponBlue[b-1][1]=weaponRed[r-1][1];
							}
							if (weaponBlue[b-1][2]==0 && weaponRed[r-1][2]!=0){
								weaponBlue[b-1][2]=weaponRed[r-1][2];
							}
						}
						if (energyCity[i]>0){
							printf("%03d:40 ",hour);
							cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" earned "<<energyCity[i]<<" elements for his headquarter"<<endl;
						}
						earnedBlue+=energyCity[i];
						winBlue.push_back(i);
						energyCity[i]=0;
						if (winCity[i]!=2){
							winCity[i]=2;
						}
						else if (flagCity[i]!=2){
							flagCity[i]=2;
							printf("%03d:40 ",hour);
							cout<<"blue flag raised in city "<<i<<endl;
						}
					}
					else if (aliveBlue[b-1]==0){
						if (warriorRed[r-1]=="dragon"){
							moraleRed[r-1]+=0.2;
							if ((flagCity[i]==1 || (flagCity[i]==0 && i%2==1)) && moraleRed[r-1]>0.8){
								printf("%03d:40 ",hour);
								cout<<"red dragon "<<r<<" yelled in city "<<i<<endl;
							}
						}
						else if (warriorRed[r-1]=="wolf"){
							if (weaponRed[r-1][0]==0 && weaponBlue[b-1][0]!=0){
								weaponRed[r-1][0]=weaponBlue[b-1][0];
							}
							if (weaponRed[r-1][1]==0 && weaponBlue[b-1][1]!=0){
								weaponRed[r-1][1]=weaponBlue[b-1][1];
							}
							if (weaponRed[r-1][2]==0 && weaponBlue[b-1][2]!=0){
								weaponRed[r-1][2]=weaponBlue[b-1][2];
							}
						}
						if (energyCity[i]>0){
							printf("%03d:40 ",hour);
							cout<<"red "<<warriorRed[r-1]<<" "<<r<<" earned "<<energyCity[i]<<" elements for his headquarter"<<endl;
						}
						earnedRed+=energyCity[i];
						winRed.push_back(i);
						energyCity[i]=0;
						if (winCity[i]!=1){
							winCity[i]=1;
						}
						else if (flagCity[i]!=1){
							flagCity[i]=1;
							printf("%03d:40 ",hour);
							cout<<"red flag raised in city "<<i<<endl;
						}
					}
					else{
						int tmpR=energyRed[r-1],tmpB=energyBlue[b-1];
						if (flagCity[i]==1 || (flagCity[i]==0 && i%2==1)){
							energyBlue[b-1]-=(attackRed[r-1]+weaponRed[r-1][0]);
							weaponRed[r-1][0]=weaponRed[r-1][0]*4/5;
							printf("%03d:40 ",hour);
							cout<<"red "<<warriorRed[r-1]<<" "<<r<<" attacked blue "<<warriorBlue[b-1]<<" "<<b;
							cout<<" in city "<<i<<" with "<<energyRed[r-1]<<" elements and force "<<attackRed[r-1]<<endl;
							if (energyBlue[b-1]<=0){
								energyBlue[b-1]=0;
								aliveBlue[b-1]=0;
							}
							else if (warriorBlue[b-1]!="ninja"){
								energyRed[r-1]-=(attackBlue[b-1]/2+weaponBlue[b-1][0]);
								weaponBlue[b-1][0]=weaponBlue[b-1][0]*4/5;
								printf("%03d:40 ",hour);
								cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" fought back ";
								cout<<"against red "<<warriorRed[r-1]<<" "<<r<<" in city "<<i<<endl;
								if (energyRed[r-1]<=0){
									energyRed[r-1]=0;
									aliveRed[r-1]=0;
								}
							}
						}
						else{
							energyRed[r-1]-=(attackBlue[b-1]+weaponBlue[b-1][0]);
							weaponBlue[b-1][0]=weaponBlue[b-1][0]*4/5;
							printf("%03d:40 ",hour);
							cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" attacked red "<<warriorRed[r-1]<<" "<<r;
							cout<<" in city "<<i<<" with "<<energyBlue[b-1]<<" elements and force "<<attackBlue[b-1]<<endl;
							if (energyRed[r-1]<=0){
								energyRed[r-1]=0;
								aliveRed[r-1]=0;
							}
							else if (warriorRed[r-1]!="ninja"){
								energyBlue[b-1]-=(attackRed[r-1]/2+weaponRed[r-1][0]);
								weaponRed[r-1][0]=weaponRed[r-1][0]*4/5;
								printf("%03d:40 ",hour);
								cout<<"red "<<warriorRed[r-1]<<" "<<r<<" fought back ";
								cout<<"against blue "<<warriorBlue[b-1]<<" "<<b<<" in city "<<i<<endl;
								if (energyBlue[b-1]<=0){
									energyBlue[b-1]=0;
									aliveBlue[b-1]=0;
								}
							}
						}
						if (aliveRed[r-1]==1 && aliveBlue[b-1]==1){
							winCity[i]=0;
							if (warriorRed[r-1]=="lion"){
								loyaltyRed[r-1]-=K;
							}
							if (warriorBlue[b-1]=="lion"){
								loyaltyBlue[b-1]-=K;
							}
							if (warriorRed[r-1]=="dragon"){
								moraleRed[r-1]+=0.2;
								if ((flagCity[i]==1 || (flagCity[i]==0 && i%2==1)) && moraleRed[r-1]>0.8){
									printf("%03d:40 ",hour);
									cout<<"red dragon "<<r<<" yelled in city "<<i<<endl;
								}
							}
							if (warriorBlue[b-1]=="dragon"){
								moraleBlue[b-1]+=0.2;
								if ((flagCity[i]==2 || (flagCity[i]==0 && i%2==0)) && moraleBlue[b-1]>0.8){
									printf("%03d:40 ",hour);
									cout<<"blue dragon "<<b<<" yelled in city "<<i<<endl;
								}
							}
						}
						else if (aliveRed[r-1]==1){
							printf("%03d:40 ",hour);
							cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" was killed in city "<<i<<endl;
							if (warriorRed[r-1]=="dragon"){
								moraleRed[r-1]+=0.2;
								if ((flagCity[i]==1 || (flagCity[i]==0 && i%2==1)) && moraleRed[r-1]>0.8){
									printf("%03d:40 ",hour);
									cout<<"red dragon "<<r<<" yelled in city "<<i<<endl;
								}
							}
							else if (warriorRed[r-1]=="wolf"){
								if (weaponRed[r-1][0]==0 && weaponBlue[b-1][0]!=0){
									weaponRed[r-1][0]=weaponBlue[b-1][0];
								}
								if (weaponRed[r-1][1]==0 && weaponBlue[b-1][1]!=0){
									weaponRed[r-1][1]=weaponBlue[b-1][1];
								}
								if (weaponRed[r-1][2]==0 && weaponBlue[b-1][2]!=0){
									weaponRed[r-1][2]=weaponBlue[b-1][2];
								}
							}
							else if (warriorRed[r-1]=="lion"){
								loyaltyRed[r-1]-=K;
							}
							if (warriorBlue[b-1]=="lion"){
								energyRed[r-1]+=tmpB;
							}
							if (energyCity[i]>0){
								printf("%03d:40 ",hour);
								cout<<"red "<<warriorRed[r-1]<<" "<<r<<" earned "<<energyCity[i]<<" elements for his headquarter"<<endl;
							}
							earnedRed+=energyCity[i];
							winRed.push_back(i);
							energyCity[i]=0;
							if (winCity[i]!=1){
								winCity[i]=1;
							}
							else if (flagCity[i]!=1){
								flagCity[i]=1;
								printf("%03d:40 ",hour);
								cout<<"red flag raised in city "<<i<<endl;
							}
						}
						else if (aliveBlue[b-1]==1){
							printf("%03d:40 ",hour);
							cout<<"red "<<warriorRed[r-1]<<" "<<r<<" was killed in city "<<i<<endl;
							if (warriorBlue[b-1]=="dragon"){
								moraleBlue[b-1]+=0.2;
								if ((flagCity[i]==2 || (flagCity[i]==0 && i%2==0)) && moraleBlue[b-1]>0.8){
									printf("%03d:40 ",hour);
									cout<<"blue dragon "<<b<<" yelled in city "<<i<<endl;
								}
							}
							else if (warriorBlue[b-1]=="wolf"){
								if (weaponBlue[b-1][0]==0 && weaponRed[r-1][0]!=0){
									weaponBlue[b-1][0]=weaponRed[r-1][0];
								}
								if (weaponBlue[b-1][1]==0 && weaponRed[r-1][1]!=0){
									weaponBlue[b-1][1]=weaponRed[r-1][1];
								}
								if (weaponBlue[b-1][2]==0 && weaponRed[r-1][2]!=0){
									weaponBlue[b-1][2]=weaponRed[r-1][2];
								}
							}
							else if (warriorBlue[b-1]=="lion"){
								loyaltyBlue[b-1]-=K;
							}
							if (warriorRed[r-1]=="lion"){
								energyBlue[b-1]+=tmpR;
							}
							if (energyCity[i]>0){
								printf("%03d:40 ",hour);
								cout<<"blue "<<warriorBlue[b-1]<<" "<<b<<" earned "<<energyCity[i]<<" elements for his headquarter"<<endl;
							}
							earnedBlue+=energyCity[i];
							winBlue.push_back(i);
							energyCity[i]=0;
							if (winCity[i]!=2){
								winCity[i]=2;
							}
							else if (flagCity[i]!=2){
								flagCity[i]=2;
								printf("%03d:40 ",hour);
								cout<<"blue flag raised in city "<<i<<endl;
							}
						}
					}
				}
				for (int i=winRed.size()-1;i>=0;i--){
					if (lifeRed<8){
						break;
					}
					energyRed[warriorCity[winRed[i]][0]-1]+=8;
					lifeRed-=8;
				}
				for (int i=0;i<winBlue.size();i++){
					if (lifeBlue<8){
						break;
					}
					energyBlue[warriorCity[winBlue[i]][1]-1]+=8;
					lifeBlue-=8;
				}
				lifeRed+=earnedRed;
				lifeBlue+=earnedBlue;
				for (int i=1;i<=N;i++){
					if (warriorCity[i][0]!=0){
						if (aliveRed[warriorCity[i][0]-1]==0){
							warriorCity[i][0]=0;
						}
					}
					if (warriorCity[i][1]!=0){
						if (aliveBlue[warriorCity[i][1]-1]==0){
							warriorCity[i][1]=0;
						}
					}
				}
			}
			
			// 司令部报告它拥有的生命元数量
			if (minute==50){
				printf("%03d:50 ",hour);
				cout<<lifeRed<<" elements in red headquarter"<<endl;
				printf("%03d:50 ",hour);
				cout<<lifeBlue<<" elements in blue headquarter"<<endl;
			}
			
			// 每个武士报告其拥有的武器情况
			if (minute==55){
				for (int i=numRed-1;i>=0;i--){
					if (aliveRed[i]==1){
						printf("%03d:55 ",hour);
						cout<<"red "<<warriorRed[i]<<" "<<i+1<<" has ";
						bool flag=0;
						if (weaponRed[i][2]!=0){
							cout<<"arrow("<<weaponRed[i][2]<<")";
							flag=1;
						}
						if (weaponRed[i][1]!=0){
							if (flag==1){
								cout<<",";
							}
							cout<<"bomb";
							flag=1;
						}
						if (weaponRed[i][0]!=0){
							if (flag==1){
								cout<<",";
							} 
							cout<<"sword("<<weaponRed[i][0]<<")";
							flag=1;
						}
						if (flag==0){
							cout<<"no weapon";
						}
						cout<<endl;
					}
				}
				for (int i=0;i<numBlue;i++){
					if (aliveBlue[i]==1){
						printf("%03d:55 ",hour);
						cout<<"blue "<<warriorBlue[i]<<" "<<i+1<<" has ";
						bool flag=0;
						if (weaponBlue[i][2]!=0){
							cout<<"arrow("<<weaponBlue[i][2]<<")";
							flag=1;
						}
						if (weaponBlue[i][1]!=0){
							if (flag==1){
								cout<<",";
							}
							cout<<"bomb";
							flag=1;
						}
						if (weaponBlue[i][0]!=0){
							if (flag==1){
								cout<<",";
							} 
							cout<<"sword("<<weaponBlue[i][0]<<")";
							flag=1;
						}
						if (flag==0){
							cout<<"no weapon";
						}
						cout<<endl;
					}
				}
			}
			
		}
		
	}
	
	return 0;
}
