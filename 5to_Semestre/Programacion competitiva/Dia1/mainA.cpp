#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
 
int main(){
	int n, t, i, minv, minid, a, b, v;
	while (scanf("%d%d", &n, &t) != EOF){
		minid = INF;
		minv = INF;
		for (i = 1; i <= n; i++){
			scanf("%d%d", &a, &b);
			if (t > a) v = ((a - t) % b + b) % b;
			else v = a - t;
			//printf("%d\n", v);
			if (v < minv){
				minv = v;
				minid = i;
			}
		}
		printf("%d\n", minid);
	}
	return 0;
}