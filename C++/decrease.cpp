#include<iostream>
#include<vector>

using namespace std;

struct VEC//�Է¹��� ���Ұ��� ���ͷ� �ޱ� ���� ����ü
{
	int num;//�迭�� ���� ��
    int count;// ���ӵ� ������ ����
    int beforeAfter;//�� �� ���ڰ� ���ٸ� �� ���� ��
};


int main(void){
    int n;//�迭�� ����
    cin >> n;
    int *arr = new int[n];
    vector<VEC> v;//���� ����
    VEC inputV;//����ü ����

    for(int i=0; i<n; i++){//���� �Է¹ޱ�
        cin >> arr[i];
    }
	
	
    inputV.num=arr[0]; //���� ù��° ����ü �Է�
    inputV.count=1;
    inputV.beforeAfter=0;
    v.push_back(inputV);
    

    for(int i =1; i<n; i++){//���� ������ ����ü �Է�
    	
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

    int beforeAfterMax = 0;//�յ� ���ӵ� ������ ���� �ִ밪
	 
    for(int i=1; i<v.size()-1; i++){//�ش� �ε����� �յ� ���ӵ� ������ ����
        //cout << v[i].num << " " << v[i].count << endl;
        if(v[i-1].num==v[i+1].num){
            v[i].beforeAfter=v[i-1].count+v[i+1].count;
            if(beforeAfterMax < v[i].beforeAfter){//�ִ밪 ����
            	beforeAfterMax = v[i].beforeAfter;
			}
        }
    }   
    
    int cnt=0;//�谨 ���� ����

    do{//���Ͱ� ����� ������ �ݺ� 
        for(int i=0; i<v.size(); i++){//���� ���Ϳ��� ���� �� 
            if(beforeAfterMax == 0 && v[i].beforeAfter==beforeAfterMax){//beforeAfterMax���� 0�̰� ���Ϳ��� ���� ��ġ�Ѵٸ� 
                v.erase(v.begin()+i);//�ش� �ε����� ���� 
                cnt++;//�ε����� ���������Ƿ� �谨���� ���� 
                break;//ó������ �ٽ� ���� 
            }
            else if(beforeAfterMax != 0 && v[i].beforeAfter==beforeAfterMax){//beforeAfterMax���� 0���� ũ�� ���Ϳ��� ���� ��ġ�Ѵٸ� 
                v.erase(v.begin()+i);//�ش� �ε��� ���� 
                v[i-1].count=v[i-1].count+v[i+1].count;//���ӵ� ���̹Ƿ� ���� ��ģ�� 
                v.erase(v.begin()+i);//���� �������Ƿ� �ش� �ε��� ���� 

                cnt++;//�ε����� ���������Ƿ� �谨���� ���� 
				
				beforeAfterMax=0;//�ʱ�ȭ 
                v[0].beforeAfter=0;//�ʱ�ȭ 
                
                
            	for(int a=1; a<v.size()-1; a++){//���� ����Ǿ����Ƿ� �ʱ�ȭ 
                    v[a].beforeAfter=v[a-1].count+v[a+1].count;
                    
                }
                
                for(int a=0; a<v.size(); a++){//beforeAfterMax���� �ٽ� ã�� 
                	if(beforeAfterMax < v[a].beforeAfter){
                        beforeAfterMax = v[a].beforeAfter;
	                }
				}
                
                
            	break;
			}
           
        }
        
    }while(v.size()>0);

    cout << cnt;//������ ��� 
}
