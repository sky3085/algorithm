#include<iostream>

using namespace std;

int main(void){
    int n;

    cin >> n;
	
	long long answer = 1;
	
    for(int i=0; i<n; i++){
    	int a = 2*i+1;
    	answer = answer * 2 * a / (i+2);
    }
    
    cout << answer;

    

}
