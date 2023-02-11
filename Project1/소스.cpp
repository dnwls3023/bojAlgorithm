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
						// ���� ��Կ� ������ �ִٸ�
						if (arr[k][l] != 'G') {
							// ��� ������ �ڰ��ִ� ���� �ƴ�.
							cout << 0 << endl;
							return 0;
						}
					}
				}


			}
		}

		// ���� �ѹ� ã�� ���������� �� ������ �����ϸ� �Ǳ� ������
		if (gs)
			break;
	}
	
	// ����κп� �����ߴٴ� ���� ���� ��� ���� ������ ���� �ƴϱ� ������
	// �ݴ�� ��԰� ���� ���� ���������� Ȯ��

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (arr[i][j] == 'P' && !ps) {
				ps = true;

				for (int k = i; k < pr + i; ++k) {
					for (int l = j; l < pc + j; ++l) {
						// ��԰� ���񿡰� ������ �ִٸ�
						if (arr[k][l] != 'P') {
							// ����� ��� ������ �ڰ��ִ� ����.
							cout << 1 << endl;
							return 0;
						}
					}
				}


			}
		}

		// ���� �ѹ� ã�� ���������� �� ������ �����ϸ� �Ǳ� ������
		if (ps)
			break;
	}

	// ������� ���α׷��� ������� �ʾҴٴ� ����
	// ���� �������� �κ��� �������� �ʴ´ٴ� ���� �ǹ��ϹǷ�.
	cout << 0 << endl;

	//DEBUG
	//cout << ps << gs << endl;
	return 0;
}