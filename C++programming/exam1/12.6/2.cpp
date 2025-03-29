#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void moveColonToNthSpace(std::string& line, size_t n) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;
    size_t spaceCount = 0;

    // 分割字符串为token，并计算空格数
    while (std::getline(iss, token, ' ')) {
        if (!token.empty()) { // 忽略连续的空格
            tokens.push_back(token);
            spaceCount++;
            if (spaceCount == n - 1 && !line.empty() && line.back() != ':') {
                // 在第n个空格前插入冒号（但不在行尾插入）
                line.insert(line.find_last_of(' ') + 1, ":");
                // 标记已处理，跳出循环（如果只有一个冒号要移动，则这样即可）
                // 如果可能有多个冒号需要处理，这里需要更复杂的逻辑
                // 但基于题目要求，我们假设每行只有一个冒号需要移动
                break;
            }
        }
    }

    // 如果循环结束还没有找到第n个空格，并且确定需要移动冒号，
    // 这里可以添加额外处理逻辑（例如，在行尾添加冒号或其他操作）
    // 但根据题目要求，我们假设输入是有效的，即每行有足够多的空格

    // 注意：上面的插入操作可能破坏了对后续空格和冒号的简单查找
    // 如果需要处理更复杂的情况（多行多冒号等），建议使用更健壮的方法
    // 例如，重新构建整行，而不是尝试在原始行上插入

    // 下面的代码是一个更健壮的重新构建行的例子（但假设只有一个冒号需要移动）
    /*
    std::ostringstream oss;
    for (size_t i = 0; i < tokens.size(); ++i) {
        oss << tokens[i];
        if (i == n - 2 && line.find(':') != std::string::npos) {
            oss << ":"; // 在第n-1个token后插入冒号（假设原行中有冒号）
        }
        if (i < tokens.size() - 1) {
            oss << ' ';
        }
    }
    // 如果原行末尾有冒号且不在第n个空格后，需要决定是否保留或移除
    // 这里假设不保留，如果需要保留，可以在最后检查并添加
    // 如果确定原行没有在其他位置错误地包含冒号，可以简化逻辑
    line = oss.str(); // 更新line为重新构建后的字符串
    */

    // 注意：由于题目要求的简单性，上面的重新构建逻辑可能过于复杂
    // 在实际情况下，根据具体需求调整逻辑即可

    // 由于我们假设每行只有一个冒号需要移动，并且输入是有效的
    // 因此上面的简单插入操作应该足够（在找到第n个空格的情况下）
    // 如果需要处理更复杂的情况，请参考注释中的重新构建逻辑或其他方法
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::string line;
    size_t n = 3; // 假设要将冒号移动到第3个空格之后（即n=3）

    if (!inputFile.is_open()) {
        std::cerr << "无法打开输入文件。" << std::endl;
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "无法打开输出文件。" << std::endl;
        inputFile.close();
        return 1;
    }

    while (std::getline(inputFile, line)) {
        moveColonToNthSpace(line, n);
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "文件处理完成。" << std::endl;

    return 0;
}