#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string a, string b){//sort ������ ���� �Լ� 
	return a>b;
}

int main(void){
    int n;//ũ�� �Է� 
    cin >> n;

    vector< vector<string> > v;
    vector<string> v1;
	
	//�ε��� ��� ������ 3���� �̸� �� ��  
    v1.push_back("0");//n=0�ϋ�
    v.push_back(v1);
    v1.clear();

    v1.push_back("1");//n=1�϶�
    v.push_back(v1);
    v1.clear();

    v1.push_back("2");//n=2�϶�
    v1.push_back("11");
    v.push_back(v1);
    v1.clear();
    
    v1.push_back("21");//n=3�϶�
    v1.push_back("12");
    v.push_back(v1);
    v1.clear();
    

    if(n>30){//30���� Ŭ �� 
        for(int a=3; a<n; a++){
        	int s=v[a].size();
            for(int b=0; b<s; b++){
                //���ڿ� �ڿ� 1 �߰��� �� 111���� Ȯ���ϰ� ����
                string save = v[a][b];
                save.append("1");
                
                
                string c = save.substr(save.size()-3,save.size());
                
				string save2;
				if(c=="111"){
                	save.erase(save.size()-2,save.size());
                	save.append("2");
                	v1.push_back(save);
                }else{
                	v1.push_back(save);	
				}
                
                //v.push_back(v1);
                
                save2.clear();
                save.clear();
                c.clear();
                //���ڿ� �տ� 1 �߰��� �� 111���� Ȯ���ϰ� ����
                save="1";
                save.append(v[a][b]);
                
				c=save.substr(0,3);
                
				if(c=="111"){
                    save.erase(0,2);
                    save2="2";
                    save2 += save;
                    v1.push_back(save2);
                    //save.append("2");�Ǿ����� �����ϴµ�.. 
                }
                else{
                	v1.push_back(save);	
				}
                
                
                save2.clear();
				save.clear();
                c.clear();
                
            	
            }

            s=v[a-1].size();
            for(int b=0; b<s; b++){
                string compare1 = v[a-1][b];
                string first = compare1.substr(0,1);
                string last = compare1.substr(compare1.size()-1,compare1.size());
                if(first == "1"){
                    first.clear();
                    first.append("2");
                    first.append(compare1);
                    v1.push_back(first);	
                }
                else if(last == "1"){
                    last.clear();
                    last = compare1;
                    last.append("2");
                    v1.push_back(last);	
                }else{
                    continue;
                }
            }



            v.push_back(v1);
                
            v1.clear();
            sort(v[a+1].begin(),v[a+1].end());
            v[a+1].erase(unique(v[a+1].begin(), v[a+1].end()), v[a+1].end());
                
				
            
        }

        
		int result = v[n].size() % 20201212;
		cout << result;
    
    }else{//30���� ���� �� 
        
        
        for(int a=3; a<n; a++){
        	int s=v[a].size();
            for(int b=0; b<s; b++){
                //���ڿ� �ڿ� 1 �߰��� �� 111���� Ȯ���ϰ� ����
                string save = v[a][b];
                save.append("1");
                
                
                string c = save.substr(save.size()-3,save.size());
                
				string save2;
				if(c=="111"){
                	save.erase(save.size()-2,save.size());
                	save.append("2");
                	v1.push_back(save);
                }else{
                	v1.push_back(save);	
				}
                
                //v.push_back(v1);
                
                save2.clear();
                save.clear();
                c.clear();
                //���ڿ� �տ� 1 �߰��� �� 111���� Ȯ���ϰ� ����
                save="1";
                save.append(v[a][b]);
                
				c=save.substr(0,3);
                
				if(c=="111"){
                    save.erase(0,2);
                    save2="2";
                    save2 += save;
                    v1.push_back(save2);
                    //save.append("2");�Ǿ����� �����ϴµ�.. 
                }
                else{
                	v1.push_back(save);	
				}
                
                
                save2.clear();
				save.clear();
                c.clear();
                
            	
            }

            s=v[a-1].size();
            for(int b=0; b<s; b++){
                string compare1 = v[a-1][b];
                string first = compare1.substr(0,1);
                string last = compare1.substr(compare1.size()-1,compare1.size());
                if(first == "1"){
                    first.clear();
                    first.append("2");
                    first.append(compare1);
                    v1.push_back(first);	
                }
                else if(last == "1"){
                    last.clear();
                    last = compare1;
                    last.append("2");
                    v1.push_back(last);	
                }else{
                    continue;
                }
            }



            v.push_back(v1);
                
            v1.clear();
            sort(v[a+1].begin(),v[a+1].end(), compare);
            v[a+1].erase(unique(v[a+1].begin(), v[a+1].end()), v[a+1].end());
                
				
            
        }

        int result = v[n].size() % 20201212;
		cout << result<<endl;
		
        for(int a=0; a<v[n].size(); a++){
			string output = v[n][a];
			for(int b=0; b<output.size(); b++){
				if(output.at(b) == '2'){
					cout << "==";
				}else{
					cout << "|";
				}
			}
			cout<<endl;
		
		}
		
    }

}
