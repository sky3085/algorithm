
#include<iostream>


using namespace std;


int main(void){
    int n;
    cin >> n;
    int *arr = new int[n];


    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int cnt = 0;
    
    for(int i=0; i<n-2; i++){
    	if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==1){
    		cnt++;
			arr[i]=0;
			arr[i+1]=0;
			arr[i+2]=0;
		}else if(arr[i]==1 && arr[i+1]==1 && arr[i+2]==0){
			cnt++;
			arr[i]=0;
			arr[i+1]=0;
			arr[i+2]=1;
		}else if(arr[i]==1 && arr[i+1]==0 && arr[i+2]==1){
			cnt++;
			arr[i]=0;
			arr[i+1]=1;
			arr[i+2]=0;
		}else if(arr[i]==1 && arr[i+1]==0 && arr[i+2]==0){
			cnt++;
			arr[i]=0;
			arr[i+1]=1;
			arr[i+2]=1;
		}
	}


	if(arr[n-2]==0 && arr[n-1]==1){
		cout << "impossible";
	}else if(arr[n-2]==1 && arr[n-1]==0){
		cout << "impossible";
	}else if(arr[n-2]==1 && arr[n-1]==1){
		cnt++;
		cout << cnt;
	}else if(arr[n-2]==0 && arr[n-1]==0){
		cout << cnt;
	}
	

}
