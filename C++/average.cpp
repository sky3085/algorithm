#include<iostream>

using namespace std;

int main(void){
    int n; //�迭�� ũ�⸦ �Է� �޽��ϴ�. 
    cin >> n;
    int *arr = new int[n];
	//�迭 ���� �Է¹޽��ϴ�. 
    for(int i =0; i<n; i++){
        cin >> arr[i];
    }


    int count=0;//�κй迭�� ��հ��� ī��Ʈ�մϴ�. 
    double thisSum=0; //�κй迭�� ������ ���մϴ�. 
    double avg=0; //�κй迭�� ����� ���մϴ�. 

    for(int a=0; a<n; a++){
        thisSum=0;
        for(int b=a; b<n; b++){
            
            thisSum+=arr[b];
            avg=thisSum/(double)(b-(a-1));
            
            if((avg-(int)avg) == 0){//���� �κй迭�� ����� �������� Ȯ���մϴ�. 
                
                for(int i=a; i<=b; i++){//�κй迭�� ��հ��� �ִ��� Ȯ���մϴ�. 
                	
                	if(avg==arr[i]){//�κй迭�� ��հ��� �ִٸ� ī��Ʈ�մϴ�. 
                		count++;
                		break;
					}
                	
				}
            }
            else{//��հ��� �Ҽ����� �ִٸ� Ȯ���� �ʿ���� ���� �ݺ������� �����մϴ�. 
                continue;
            }
        }
        
        	
    }

	cout << count;
}
