#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3) return -1;
	
	string aid = argv[1];
	string api = "https://api.m.jd.com/client.action?functionId=executeTopActivityTask&body={\"activityId\":\"";
	api += aid;
	api += "\",\"lotterySku\":\"";
	api += argv[2];
	api += "\",\"sharePin\":\"";
	string tail = "\",\"taskType\":16}&client=wh5&clientVersion=2.0.0&appid=content_ecology";

	freopen("car.txt", "r", stdin);
	freopen(("pin" + aid + ".txt").c_str(), "w", stdout);

	string line;
	string pattern = "pt_pin=";

	while (getline(cin, line)) {
		int t = 0;
		if (line != "" && (t = line.find(pattern)) != string::npos) {
			line = line.substr(t + pattern.length());
			line = line.substr(0, line.find(";"));
			cout << api + line + tail << endl;
		}
	}

	return 0;
}