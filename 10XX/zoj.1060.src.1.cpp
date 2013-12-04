// ƭ���Һö� WA ������
// ��������� 8 ���ߣ�ǰ 5 ���Ѿ�ȷ�������й�ϵ����ô����ļ�ʹì��Ҳ����ȷ��
// Ҳ����˵��ì�ܺ�����ȷ����ͬ���ȼ��ģ���
// �߼�������Ŀ������������ BS һ�¶Բ����Լ�

// �㷨�������ģ���һ��ͼ�ڽӾ���
// �� A < B ����� E<A,B>
// ��һ��������Ȩͼ��δ���Ϊ -1
// û����һ����ϵ A<B
// ��� adj[A][B]
// �� 0�������ì�ܣ����ì�� 
// �� 1�������ظ��ı�ǣ�����
// �� -1����һ���µĹ�ϵ����ǣ������� 1
//     ���ң�ͬ���ݹ鿼����û�� �ӱ�ı��ܵ� A �� (C<A)��
//     ���ߴ� B ����ĵ�� (B<C)������У�ִ������ͬ�����б�
// �������߼���������������������һ���ǵݹ�Ķ�ջ���ܱȽ����� 400 �� K ����� 


#include <cstdio>
#include <cstring>

int	N,	Q;
char	adj[26][26],	oper[4];
int	inconsistency;
int	determine,	count;

void remark( int p1, int p2, int i ) {	
	// -1 ��δ����ǺϷ��ģ��ֱ��֮������ǰ׷��
	if( adj[p1][p2] == -1 ) {
		adj[p1][p2] = 1;
		adj[p2][p1] = 0;
		// ÿ���һ����·����Ҫ����һ������ 
		count++;
		// �����з�ɴ��ݵĵ� 
		for( int j = 0; j < N; j++ )
			if( adj[p2][j] == 1 )
				remark( p1, j, i );
		for( int j = 0; j < N; j++ )
			if( adj[j][p1] == 1 )
				remark( j, p2, i );
	} 
	// 1 ���ظ���ǣ�ֱ������ 
	else if( adj[p1][p2] == 1 ) return; 
	// ������ 0�������һ��ì��
	else {
		inconsistency = i;
		return;
	}
}

int main() {
	while( scanf( "%d%d", &N, &Q ) && ( N || Q ) ) {
		memset( adj, -1, 676 );
		inconsistency = 0;
		determine = 0;
		count = 0; 
		int	p1,	p2;
		for( int i = 1; i <= Q; i++ ) {
			// ���� 
			scanf( "%s", oper );
			// ����Ѿ�����ì�ܣ����� 
			if( inconsistency || determine ) continue;
			// ��ȡ���������� 
			p1 = oper[0] - 'A';
			p2 = oper[2] - 'A';
			// �������������� 
			if( p1 == p2 ) {
				inconsistency = i;
				continue;
			}
			// ������еݹ��� 
			remark( p1, p2, i );
			// �����Ǽ����ﵽ�� N * (N - 1) / 2���������
			if( !determine && count == N * (N - 1) / 2 ) {
				determine = i; 
			}
		} 
		// ע�������ȫ��ȷ��֮������ì�ܣ����ì����Ϊ���� 
		if( inconsistency )
			printf( "Inconsistency found after %d relations.\n", inconsistency );
		else if( determine ) {
			printf( "Sorted sequence determined after %d relations: ", determine );
			// һ�������� k ����ߣ������ŵ� k
			char	output[27];
			output[N] = 0;
			for( int i = 0; i < N; i++ ) {
				int	k = 1; 
				for( int j = 0; j < N; j++ )
					k += adj[j][i];
				output[k] = 'A' + i; 
			}
			printf( "%s.\n", output );

		}
		// �������û�ҵ� 
		else	printf( "Sorted sequence cannot be determined.\n" ); 
	}
}
