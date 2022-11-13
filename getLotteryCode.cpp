#include <string>
#include <iostream>

using namespace std;

int main()
{
	freopen("carAll.txt", "r", stdin);
	freopen("LotteryCode.txt", "w", stdout);

	string line;
	string pattern = "\"lotteryCode\":\"";

	while (getline(cin, line)) {
		if (line != "") { // omit empty lines
			int w = line.find("{");
			cout << line.substr(0, w = min(11, w));
			while (w++ < 19) cout << "-";

			line = line.substr(line.find("myLotteryCodeList"));
			int t = 0, ptsz = pattern.length();
			while ((t = line.find(pattern, t)) != string::npos) {
				cout << "\t\t" << line.substr(t += ptsz, 8);
			}
			cout << endl;
		}
	}

	return 0;
}