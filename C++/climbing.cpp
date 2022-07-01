#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Player {
	public:
		int node[4];
        int rank;
		int score;
		
		bool operator < (Player& player) {
            if(rank == player.rank){
            	if(score == player.score){
            		return node[0] < player.node[0];
				}else{
					return score < player.score;
				}
            }else{
                return rank < player.rank;
            }
			
		}
};

int main(void){
    int n;
    vector<Player> v;

    cin >> n;

    Player p;
    for(int i=0; i<n; i++){
        cin >> p.node[0];
        cin >> p.node[1];
        cin >> p.node[2];
        cin >> p.node[3];
        v.push_back(p);
    }

    for(int a=0; a<n; a++){
        for(int b=0; b<4; b++){
            v[a].rank = v[a].node[1] * v[a].node[2] * v[a].node[3];
            v[a].score = v[a].node[1] + v[a].node[2] + v[a].node[3];
        }
        
    }

    sort(v.begin(), v.end());

    for(int a=0; a<2; a++){
        
        cout << v[a].node[0] << " ";
        
    }
    cout << v[2].node[0];

}
