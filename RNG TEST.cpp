#include <fstream>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

struct playerStats{
 //rng stuff   

                    struct rune1{
                        int common,
                            uncommon,
                            rare,
                            epic,
                            legendary,
                            mythic;
                    };
                    rune1 Rune1[1];

                    struct rune2{
                        int fragile,
                            weak,
                            basic,
                            adept,
                            great,
                            superior,
                            prime;
                    };
                    rune2 Rune2[1];

// player buffs
    int totalRolled;
};

playerStats Stats[1];


int main(){
    bool run = true;
    long i = 1;
    string roll;
    int quantity = 1;
	int bulk = 1;
	int luck = 0;
	int rolledNumber;

    srand(time(0));

    ifstream saveIn  ("save.txt");
    ofstream saveOut ("save1.txt");



    while (run == true){
        cout << "What do you want to do?"<<endl<<"roll  stats  end" << endl;
        cin>>roll;
        if(roll == "roll"){
		cout << "Type in how much bulk you want: " << endl;
		cin >> bulk;
		cout << "Type in your luck: " << endl;
		cin >> luck;
			for (int k = 1; k <= 1; k++)
			{

				for (int j = 1; j <= bulk; j++)
				{
                    Stats[1].totalRolled++;
					int rolledNumber = (rand() % (101 - luck));

					if (rolledNumber <= 1)
					{
							//cout<<"MYTHIC!!!!!"<<endl;
						Stats[1].Rune1[1].mythic+=1;
					}
					else if (rolledNumber <= 6)
					{
							//cout<<"Legendary! NICE! "<<endl;
						Stats[1].Rune1[1].legendary+=1;
					}
					else if (rolledNumber <= 17)
					{
							//cout<<"Epic!"<<endl;
						Stats[1].Rune1[1].epic+= 1;
					}
					else if (rolledNumber <= 35)
					{
							//cout<<"Rare!"<<endl;
						Stats[1].Rune1[1].rare+=1;
					}
					else if (rolledNumber <= 64)
					{
							//cout<<"Uncommon"<<endl;
						Stats[1].Rune1[1].uncommon+=1;
					}
					else
					{
							//cout<<"Common"<<endl;
						Stats[1].Rune1[1].common+=1;}
				}
            }
    }

    if(roll == "stats"){
        cout<<"Rune Stats: "<<endl<<"           Rune1: Common - "<<Stats[1].Rune1[1].common<<" | Uncommon - "<<Stats[1].Rune1[1].uncommon<<" | Rare - "<<Stats[1].Rune1[1].rare<<" | Epic - "<<Stats[1].Rune1[1].epic<<"  | Legendary - "<<Stats[1].Rune1[1].legendary<<" | Mythic - "<<Stats[1].Rune1[1].mythic<<endl;
        cout<<endl<<"Total Rolled - "<<Stats[1].totalRolled<<endl;
    }

    if(roll == "end") run = false;

}
}