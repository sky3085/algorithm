#include<iostream>
#include<vector>

using namespace std;

struct VEC//입력받은 원소값을 벡터로 받기 위한 구조체
{
	int num;//배열의 원소 값
    int count;// 연속된 숫자의 개수
    int beforeAfter;//앞 뒤 숫자가 같다면 그 둘의 합
};


int main(void){
    int n;//배열의 길이
    cin >> n;
    int *arr = new int[n];
    vector<VEC> v;//벡터 생성
    VEC inputV;//구조체 생성

    for(int i=0; i<n; i++){//원소 입력받기
        cin >> arr[i];
    }
	
	
    inputV.num=arr[0]; //벡터 첫번째 구조체 입력
    inputV.count=1;
    inputV.beforeAfter=0;
    v.push_back(inputV);
    

    for(int i =1; i<n; i++){//벡터 나머지 구조체 입력
    	
        if(arr[i]==arr[i-1]){
            v.back().count+=1;
        }
        else{
            
            inputV.num=arr[i];
            inputV.beforeAfter=0;
            inputV.count=1;
            v.push_back(inputV);
        }
        
    }

    int beforeAfterMax = 0;//앞뒤 연속된 숫자의 개수 최대값
	 
    for(int i=1; i<v.size()-1; i++){//해당 인덱스의 앞뒤 연속된 숫자의 개수
        //cout << v[i].num << " " << v[i].count << endl;
        if(v[i-1].num==v[i+1].num){
            v[i].beforeAfter=v[i-1].count+v[i+1].count;
            if(beforeAfterMax < v[i].beforeAfter){//최대값 갱신
            	beforeAfterMax = v[i].beforeAfter;
			}
        }
    }   
    
    int cnt=0;//삭감 연산 개수

    do{//벡터가 사라질 때까지 반복 
        for(int i=0; i<v.size(); i++){//현재 벡터에서 값을 비교 
            if(beforeAfterMax == 0 && v[i].beforeAfter==beforeAfterMax){//beforeAfterMax값이 0이고 벡터에서 값이 일치한다면 
                v.erase(v.begin()+i);//해당 인덱스를 삭제 
                cnt++;//인덱스를 삭제했으므로 삭감연산 증가 
                break;//처음부터 다시 시작 
            }
            else if(beforeAfterMax != 0 && v[i].beforeAfter==beforeAfterMax){//beforeAfterMax값이 0보다 크고 벡터에서 값이 일치한다면 
                v.erase(v.begin()+i);//해당 인덱스 삭제 
                v[i-1].count=v[i-1].count+v[i+1].count;//연속된 값이므로 값을 합친다 
                v.erase(v.begin()+i);//값을 합쳤으므로 해당 인덱스 삭제 

                cnt++;//인덱스를 삭제했으므로 삭감연산 증가 
				
				beforeAfterMax=0;//초기화 
                v[0].beforeAfter=0;//초기화 
                
                
            	for(int a=1; a<v.size()-1; a++){//값이 변경되었으므로 초기화 
                    v[a].beforeAfter=v[a-1].count+v[a+1].count;
                    
                }
                
                for(int a=0; a<v.size(); a++){//beforeAfterMax값을 다시 찾기 
                	if(beforeAfterMax < v[a].beforeAfter){
                        beforeAfterMax = v[a].beforeAfter;
	                }
				}
                
                
            	break;
			}
           
        }
        
    }while(v.size()>0);

    cout << cnt;//정답을 출력 
}
