#include <iostream>
using namespace std;

char arr[101][101];

int main(void) {
	int r, c;
	cin >> r >> c;

	int gr, gc, pr, pc;
	cin >> gr >> gc >> pr >> pc;

	bool gs = false, ps = false;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 'G' && !gs) {
				gs = true;

				for (int k = i; k < gr + i; ++k) {
					for (int l = j; l < gc + j; ++l) {
						// 가희가 배게에 덮여져 있다면
						if (arr[k][l] != 'G') {
							// 배게 위에서 자고있는 것이 아님.
							cout << 0 << endl;
							return 0;
						}
					}
				}


			}
		}

		// 최초 한번 찾은 시점에서만 위 로직을 실행하면 되기 때문에
		if (gs)
			break;
	}
	
	// 여기부분에 도달했다는 것은 가희가 배게 위에 덮여진 것이 아니기 때문에
	// 반대로 배게가 가희에 의해 덮여졌는지 확인

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 'P' && !ps) {
				ps = true;

				for (int k = i; k < pr + i; ++k) {
					for (int l = j; l < pc + j; ++l) {
						// 배게가 가희에게 덮여져 있다면
						if (arr[k][l] != 'P') {
							// 가희는 배게 위에서 자고있는 것임.
							cout << 1 << endl;
							return 0;
						}
					}
				}


			}
		}

		// 최초 한번 찾은 시점에서만 위 로직을 실행하면 되기 때문에
		if (ps)
			break;
	}

	// 여기까지 프로그램이 종료되지 않았다는 뜻은
	// 서로 겹쳐지는 부분이 존재하지 않는다는 것을 의미하므로.
	cout << 0 << endl;

	//DEBUG
	//cout << ps << gs << endl;
	return 0;
}