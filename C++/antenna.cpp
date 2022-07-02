#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct POINT2D//���׳��� ��ǥ
{
	int x;
	int y;
};


int findP(int parent[], int u) {//��带 ���� ��Ű�� ���� ����Ŭ Ȯ��
	if (u == parent[u])
		return u;
	return parent[u] = findP(parent, parent[u]);
}

bool unionP(int parent[], int u, int v) {//����Ŭ�� ���� ������ �պ�
	u = findP(parent, u);
	v = findP(parent, v);
	if (u == v)
		return false;
	parent[v] = u;
	return true;
}

class Edge {//�������� ��� ������ �Ÿ� ����
	public:
		int node[2];
		double length;
		Edge(int x, int y, double length) {
			this->node[0] = x;
			this->node[1] = y;
			this->length = length;
		}
		bool operator < (Edge& edge) {
			return length < edge.length;
		}
};

int main(void) {
	int node_num;//��� ��带 �Է� ���� ������ Ȯ��
	cin >> node_num;
	POINT2D *arr = new POINT2D[node_num];//����ü �迭�� ����
	for (int i = 0; i < node_num; i++) {
		cin >> arr[i].x;
		cin >> arr[i].y;
	}
	
	vector<Edge> v;
	double length=0;//��� ������ ����

	for (int i = 0; i < node_num; i++) {//��� �������� �Ÿ��� ���ϱ�
		for (int a = i+1; a < node_num; a++) {
			length = sqrt(pow(arr[a].x-arr[i].x, 2)+ pow(arr[a].y - arr[i].y, 2));
			
			v.push_back(Edge(i, a, length));
			
		}
	}
	int edge_num = v.size();//������ ��

	sort(v.begin(), v.end());//�������� ����

	//ũ�罺Į �ʱ�ȭ
	int *parent = new int[node_num];
	for (int i = 0; i < node_num; i++) {
		parent[i] = i;
	}

	double max_edge = 0;//������ �ִ���� �ʱ�ȭ

	for (int i = 0; i < (int)v.size(); i++) {//ũ�罺Į ����
		if (unionP(parent, v[i].node[0], v[i].node[1])) {
			
			if (max_edge < v[i].length) {//�ִ� ���� ���� 
				max_edge = v[i].length;
			}
		}
	}
	
	printf("%.7f\n", max_edge / 2.0);//���

	delete arr;//�����Ҵ� �迭 �ݳ�
	return 0;
}
