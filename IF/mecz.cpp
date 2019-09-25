//
// Created by Adam Szokalski on 25/09/2019.
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string ciag;
    cin>>ciag;

    int pkt_a = 0, pkt_b = 0, gem_a=0, gem_b=0, set_a = 0, set_b = 0;
    bool tie_break = false;

    for(auto zwyciezca : ciag){

        switch(zwyciezca){
            case 'A':
                pkt_a++;
                break;
            case 'B':
                pkt_b++;
                break;
        }

        if(abs(pkt_a - pkt_b) >= 2){
            if((pkt_a > pkt_b) && ((!tie_break && pkt_a >= 4) || (tie_break && pkt_a >= 7))){
                gem_a++;
                pkt_a = 0;
                pkt_b = 0;
                if(tie_break){
                    set_a++;
                    gem_a = 0;
                    gem_b = 0;
                    tie_break = false;
                }

            } else if ((pkt_a < pkt_b) && ((!tie_break && pkt_b >= 4) || (tie_break && pkt_b >= 7))){
                gem_b++;
                pkt_a = 0;
                pkt_b = 0;
                if(tie_break){
                    set_b++;
                    gem_a = 0;
                    gem_b = 0;
                    tie_break = false;
                }
            }

            if(gem_a == 6 && gem_b == 6){
                tie_break = true;
            }
        }

        if(abs(gem_a - gem_b) >= 2){

            if(gem_a >= 6){
                set_a++;
                gem_a = 0;
                gem_b = 0;
            } else if (gem_b >= 6){
                set_b++;
                gem_a = 0;
                gem_b = 0;
            }

        }

        if(set_a == 3){
            cout<<"A"<<endl;
            break;
        }else if(set_b == 3){
            cout<<"B"<<endl;
            break;
        }

    }
}