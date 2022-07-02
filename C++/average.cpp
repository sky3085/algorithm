#include<iostream>

using namespace std;

int main(void){
    int n; //배열의 크기를 입력 받습니다. 
    cin >> n;
    int *arr = new int[n];
	//배열 값을 입력받습니다. 
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }


    int count=0;//부분배열에 평균값을 카운트합니다. 
    double thisSum=0; //부분배열의 총합을 구합니다. 
    double avg=0; //부분배열의 평균을 구합니다. 

    for(int a=0; a<n; a++){
        thisSum=0;
        for(int b=a; b<n; b++){
            
            thisSum+=arr[b];
            avg=thisSum/(double)(b-(a-1));
            
            if((avg-(int)avg) == 0){//만약 부분배열의 평균이 정수인지 확인합니다. 
                
                for(int i=a; i<=b; i++){//부분배열에 평균값이 있는지 확인합니다. 
                	
                	if(avg==arr[i]){//부분배열에 평균값이 있다면 카운트합니다. 
                		count++;
                		break;
					}
                	
				}
            }
            else{//평균값에 소수값이 있다면 확인할 필요없이 다음 반복문으로 진행합니다. 
                continue;
            }
        }
        
        	
    }

	cout << count;
}
