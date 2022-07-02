#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct POINT2D//안테나의 좌표
{
	int x;
	int y;
};


int findP(int parent[], int u) {//노드를 연결 시키기 전에 사이클 확인
	if (u == parent[u])
		return u;
	return parent[u] = findP(parent, parent[u]);
}

bool unionP(int parent[], int u, int v) {//사이클이 돌지 않으면 합병
	u = findP(parent, u);
	v = findP(parent, v);
	if (u == v)
		return false;
	parent[v] = u;
	return true;
}

class Edge {//간선으로 노드 사이의 거리 포함
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
	int node_num;//몇개의 노드를 입력 받을 것인지 확인
	cin >> node_num;
	POINT2D *arr = new POINT2D[node_num];//구조체 배열에 저장
	for (int i = 0; i < node_num; i++) {
		cin >> arr[i].x;
		cin >> arr[i].y;
	}
	
	vector<Edge> v;
	double length=0;//노드 사이의 길이

	for (int i = 0; i < node_num; i++) {//모든 노드사이의 거리를 구하기
		for (int a = i+1; a < node_num; a++) {
			length = sqrt(pow(arr[a].x-arr[i].x, 2)+ pow(arr[a].y - arr[i].y, 2));
			
			v.push_back(Edge(i, a, length));
			
		}
	}
	int edge_num = v.size();//간선의 수

	sort(v.begin(), v.end());//오름차순 정렬

	//크루스칼 초기화
	int *parent = new int[node_num];
	for (int i = 0; i < node_num; i++) {
		parent[i] = i;
	}

	double max_edge = 0;//간선의 최대길이 초기화

	for (int i = 0; i < (int)v.size(); i++) {//크루스칼 생성
		if (unionP(parent, v[i].node[0], v[i].node[1])) {
			
			if (max_edge < v[i].length) {//최대 간선 길이 
				max_edge = v[i].length;
			}
		}
	}
	
	printf("%.7f\n", max_edge / 2.0);//출력

	delete arr;//동적할당 배열 반납
	return 0;
}
