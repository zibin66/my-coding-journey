#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int readInt(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) return x;
        cout << "输入无效，请输入一个数字！\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readDouble(const string& prompt) {
    double x;
    while (true) {
        cout << prompt;
        if (cin >> x) return x;
        cout << "输入无效，请输入一个数字！\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int choice;
    while (true) {
        // 主界面
        cout << "\n===== 简易计算器 =====\n";
        cout << "1. 加法 (+)\n";
        cout << "2. 减法 (-)\n";
        cout << "3. 乘法 (*)\n";
        cout << "4. 除法 (/)\n";
        cout << "0. 退出\n";
        choice = readInt("请选择操作：");

        if (choice == 0) {
            cout << "已退出，再见！\n";
            break;
        }
        if (choice < 1 || choice > 4) {
            cout << "无效选择，请重新输入！\n";
            continue;
        }

        char op;
        string name;
        switch (choice) {
            case 1: op = '+'; name = "加法"; break;
            case 2: op = '-'; name = "减法"; break;
            case 3: op = '*'; name = "乘法"; break;
            case 4: op = '/'; name = "除法"; break;
        }

        bool backToMenu = false;
        while (!backToMenu) {
            cout << "\n---- 当前运算：" << name << " (" << op << ") ----\n";
            double a, b;
            a = readDouble("请输入第一个数：");
            b = readDouble("请输入第二个数：");

            double result;
            bool ok = true;
            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        cout << "错误：除数不能为 0！\n";
                        ok = false;
                    } else {
                        result = a / b;
                    }
                    break;
            }

            if (ok) cout << "结果：" << a << " " << op << " " << b << " = " << result << "\n";

            // 计算后询问
            int after;
            while (true) {
                cout << "\n请选择：\n";
                cout << "1. 继续计算（同一运算符）\n";
                cout << "2. 返回主界面\n";
                after = readInt("请选择：");
                if (after == 1) break;
                if (after == 2) { backToMenu = true; break; }
                cout << "无效选择，请重新输入！\n";
            }
        }
    }
    return 0;
}
