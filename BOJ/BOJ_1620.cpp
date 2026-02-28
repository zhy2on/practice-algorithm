#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;

int str_to_num(string str) {
    int n = 0;
    for (auto c : str) {
        n *= 10;
        n += (c - '0');
    }
    return n;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    unordered_map<string, int> str_to_int;
    string int_to_str[100002];
    for (int i = 1; i <= N; ++i) {
        string name;
        cin >> name;
        str_to_int.emplace(name, i);
        int_to_str[i] = name;
    }

    for (int i = 0; i < M; ++i) {
        string str;
        cin >> str;
        if (str[0] >= '0' && str[0] <= '9') cout << int_to_str[str_to_num(str)] << '\n';
        else cout << str_to_int.find(str)->second << '\n';
    }
}
