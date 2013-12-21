// ����ı���⣬�㷨���� 
// ע���������Ҫ�Ƚ�����
// �������ݽṹ��ѡ��Ҳ�й�ϵ
#include <iostream>
#include <string>
using namespace std;

struct Node {
	string	name;
	int	grade;
	Node*	parent;
};

int main() {
	int	N,	Q;
	string	temp;
	Node	tree[1000];
	while( ( cin >> N >> Q ) && ( N || Q ) ) {
		getchar();
		// ���� 
		for( int i = 0; i < N; i++ ) {
			getline( cin, tree[i].name );
			tree[i].grade = 0;
			while( tree[i].name[tree[i].grade] == ' ' )
				tree[i].grade++;
			tree[i].name.erase( 0,tree[i].grade );
			if( tree[i].grade == 0 )
				tree[i].parent = NULL;
			else {
				for( int j = i - 1; j >= 0; j-- ) {
					if( tree[j].grade < tree[i].grade ) {
						tree[i].parent = tree + j;
						break;
					}
				}
			}
		}
		// ����
		string	node1,	oper,	node2;
		Node*	pNode1;
		Node*	pNode2;
		bool	yes;
		while( Q-- ) {
			cin >> node1 >> oper >> oper >> oper >> node2 >> node2;
			// �������һ����� 
			node2.erase( node2.size() - 1 );
			// ����ǰ����������ڵĽڵ�ָ�� 
			pNode1 = pNode2 = NULL;
			for( int i = 0; i < N; i++ ) {
				if( node1 == tree[i].name )
					pNode1 = tree + i;
				if( node2 == tree[i].name )
					pNode2 = tree + i;
				if( pNode1 && pNode2 )
					break;
			}
			if( !pNode1 || !pNode2 ) {
				// ����ʧ��
				cout << "False" << endl;
				continue;
			}
			// �߼��б� 
			yes = false; 
			if( oper == "child" )
				yes = pNode1 -> parent == pNode2;
			else if( oper == "parent" )
				yes = pNode2 -> parent == pNode1; 
			else if( oper == "sibling" )
				// ��û�ж�������������������á� 
				yes = pNode1 -> parent ==
				      pNode2 -> parent &&
				      pNode2 -> parent ; 
			else if( oper == "ancestor" ) {
				while( pNode2 -> parent ) {
					if( pNode2 -> parent == pNode1 ) {
						yes = true;
						break;
					}
					pNode2 = pNode2 -> parent;
				}
			}
			else if( oper == "descendant" ) {
				while( pNode1 -> parent ) {
					if( pNode1 -> parent == pNode2 ) {
						yes = true;
						break;
					}
					pNode1 = pNode1 -> parent;
				}
			}
			// ���
			if( yes ) cout << "True" << endl;
			else	  cout << "False" << endl;
		} 
		cout << endl;
	}
}
