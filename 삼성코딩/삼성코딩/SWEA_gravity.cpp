#include<iostream>


using namespace std;



int main() {
	int Tcase;
	int width, height;
	int boxTop[101] = { 0, };
	int maxFall;
	int cntEmpty = 0;
	
	cin >> Tcase;
	while (Tcase--) {
		int box[101][101] = { 0, };
		cin >> width >> height;
		maxFall = 0;

		for (int i = 0; i < width; i++) {
			cin >> boxTop[i];
			for (int j = 0; j < boxTop[i]; j++) {
				box[i][j] = 1;
			}
		}

		for (int i = 0; i < width; i++) {
			if (boxTop[i] > 0) {
				cntEmpty = 0;
				for (int j = i + 1; j < width; j++) {
					if (box[j][boxTop[i]-1] == 0)
						cntEmpty++;
				}

				if (maxFall < cntEmpty)
					maxFall = cntEmpty;
			}
		}

		cout << maxFall << endl;
	}
}