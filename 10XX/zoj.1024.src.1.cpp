// ��һ���ݹ�Ĺ�ϵ
// ����һ����ά�������� DP
// ���� DP ��ʱ������˵ݹ飬����һ��ʼ�� 1900 1 1 �Ļ�
// �ݹ��������ᵼ�¶�ջ������� RE
// ���Ҫ��׼����������ǰ�����Ҳ��������� buffer ����
// ������������Ǻ�Ư�������٣������ҵ�һ���ǵݹ�� DP 

#include <cstdio>
#include <cstring>

/*
�����������߼���
    ������ĳһ���ǿ϶���Ӯ�ģ�����Ϊ date1 = yyyy/mm/dd
���ԣ���ʼ֪������������������������2001/11/3��2001/10/4
    ��ô�����������ĳһ�죬����������Ӳ��Ϸ�������һ��϶������
���������һ����¸���ͬһ�첻���ڣ���ô�� Move �����λ��ȥ�϶��ᵼ�����䣬

���ȡ���ڽ����ŵ���һ���Ƿ��ʤ���� win(someDay) = !win(someDay.nextday())
���ߣ������һ����¸���ͬһ����ڣ���ô����Ȩ�� Move ��������λ�õ��е�����һ�������������λ�õ���������һ�����䣬��ô���Ϳ��Խ��������ڱ����λ�ã�������λ�ñ�Ӯ���� win(someDay) = !win(someDay.nextday()) || !win(someDay.nextmonth())
*/

char	A[103][12][31];
int	DAY[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31 };

// �ж�һ������Ƿ�Ϊ���� 
inline bool isLeapYear( int year ) {
	return	year % 400 == 0 || year % 100 && year % 4 == 0;
}

// �ж�һ�������Ƿ��ںϷ���Χ�� 
inline bool isValid( int year, int month, int day ) {
	if( year < 1900 || month < 1 || day < 1 )
		return	false;
	DAY[1] = isLeapYear( year ) ? 29 : 28;
	if( year > 2001 || month > 12 || day > DAY[month - 1] )
		return	false;
	if( year == 2001 && month == 12 )
		return	false;
	if( year == 2001 && month == 11 && day > 3 )
		return	false;
	return	true;
}

// �ж�һ�������Ƿ���ʤ�� 
bool win( int year, int month, int day ) {
//	printf( "call: %d/%d/%d\n", year, month, day );
	if( !isValid( year, month, day ) )
		return	false;
	if( A[year - 1900][month - 1][day - 1] >= 0 )
		return	A[year - 1900][month - 1][day - 1];
	DAY[1] = isLeapYear( year ) ? 29 : 28;
	// �����ŵ���һ�� 
	int	nextDay = day + 1,
		nextMonth = month,
		nextYear = year;
	// �����������ĩ 
	if( day == DAY[month - 1] ) {
		// ��һ��Ӧ���� 1 ��
		nextDay = 1;
		// �·ݼ� 1���������Ϊ 12 �£�������Ϊ 1 �� 
		if( nextMonth++ == 12 ) {
			nextMonth = 1;
			// ������ݼ� 1 
			nextYear++;
		}
	}
	// ����һ��λ����ʤ����λ�ã���ô�����ǿ������λ��
	bool	ans = !win( nextYear, nextMonth, nextDay );
	// ��������¸��µ�ͬһ��
	if( isValid( year + month / 12, month % 12 + 1, day ) )
		// ��ֻҪ�����Ǹ�ʧ�ܵ�λ�õĻ��������Ǹ�ʤ����λ�� 
		ans = ans || !win( year + month / 12, month % 12 + 1, day );
	return	A[year - 1900][month - 1][day - 1] = char( ans );
}

// �������壬��ֹ���ȵݹ��ջ��� 
void buffer() {
	for( int year = 2000; year >= 1900; year -= 1 )	win( year, 1, 1 ); 
} 

int main() {
	memset( A, -1, sizeof( A ) );
	A[101][10][2] = 1;
	A[101][9][3] = 1;
	buffer();
	int	N,	yyyy,	mm,	dd;
	scanf( "%d", &N );
	while( N-- ) {
		scanf( "%d%d%d", &yyyy, &mm, &dd );
		printf( "%s\n", win( yyyy, mm, dd ) ? "YES" : "NO" );
	}
}
