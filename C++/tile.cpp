#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string a, string b){//sort 정렬을 위한 함수 
	return a>b;
}

int main(void){
    int n;//크기 입력 
    cin >> n;

    vector< vector<string> > v;
    vector<string> v1;
	
	//인덱스 계산 때문에 3까지 미리 입 력  
    v1.push_back("0");//n=0일떄
    v.push_back(v1);
    v1.clear();

    v1.push_back("1");//n=1일때
    v.push_back(v1);
    v1.clear();

    v1.push_back("2");//n=2일때
    v1.push_back("11");
    v.push_back(v1);
    v1.clear();
    
    v1.push_back("21");//n=3일때
    v1.push_back("12");
    v.push_back(v1);
    v1.clear();
    

    if(n>30){//30보다 클 때 
        for(int a=3; a<n; a++){
        	int s=v[a].size();
            for(int b=0; b<s; b++){
                //문자열 뒤에 1 추가한 후 111인지 확인하고 삽입
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
                //문자열 앞에 1 추가한 후 111인지 확인하고 삽입
                save="1";
                save.append(v[a][b]);
                
				c=save.substr(0,3);
                
				if(c=="111"){
                    save.erase(0,2);
                    save2="2";
                    save2 += save;
                    v1.push_back(save2);
                    //save.append("2");맨앞으로 가야하는데.. 
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
    
    }else{//30보다 작을 때 
        
        
        for(int a=3; a<n; a++){
        	int s=v[a].size();
            for(int b=0; b<s; b++){
                //문자열 뒤에 1 추가한 후 111인지 확인하고 삽입
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
                //문자열 앞에 1 추가한 후 111인지 확인하고 삽입
                save="1";
                save.append(v[a][b]);
                
				c=save.substr(0,3);
                
				if(c=="111"){
                    save.erase(0,2);
                    save2="2";
                    save2 += save;
                    v1.push_back(save2);
                    //save.append("2");맨앞으로 가야하는데.. 
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
