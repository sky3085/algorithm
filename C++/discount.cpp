#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>

using namespace std;


bool compare(int i, int j){
    return j < i;
}

int main(void){
    int n;//물건 개수
    int x;//할인율
    
	//freopen("C:\\in09.txt", "r", stdin);
	
    cin >> n;
    cin >> x;
	long long *answer =new long long[n];//정답을 구하기 위한 배 열  
    vector<long long> arr;
    int r;//벡터를 입력받기 위한 변 수 
    
    for(int i=0; i<n; i++){
        cin >> r;
        arr.push_back(r);
    }
    
    sort(arr.begin(), arr.end(), compare);
	
	for(int i=0; i<arr.size(); i++){
		if(i==0){
			answer[0]=arr[0]*(100-x)/100;
		}else if(i==1){
			answer[1]=answer[0]+(arr[1]*(100-x)/100);
		}else if(i==2){
			long long son = (arr[0]+arr[1]+arr[2])*(100-x)/100;
			long long kim = arr[0] + arr[1];
			if(son < kim){
				answer[i]=son;
			}else{
				answer[i]=kim;
			}
		}else{
			long long son = answer[i-1] + (arr[i]*(100-x)/100);
			long long kim = answer[i-3] + arr[i-2] + arr[i-1];
			if(son < kim){
				answer[i]=son;
			}else{
				answer[i]=kim;
			}
		}
		
		
	}
    


	cout << answer[n-1];
//    string s = to_string(answer[n-1]);
//    ofstream writeFile;
//    writeFile.open("output.txt");
//    writeFile.write(s.c_str(), s.size());
//    writeFile.close();

    delete[] answer;

}
