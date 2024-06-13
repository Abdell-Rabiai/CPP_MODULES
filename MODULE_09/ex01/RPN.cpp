# include "RPN.hpp"

bool is_operator(const std::string &str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

int do_op(const std::string &op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Unknown operator");
}

int StringToInt(const std::string &str) {
    std::istringstream iss(str);
    int value;
    if (!(iss >> value)) {
        throw std::runtime_error("Invalid value");
    }
    return value;
}

int calculate_rpn(const std::string &expression) {
    std::istringstream iss(expression);
    std::stack<int> stack;
    std::string str;

    while (iss >> str) {
        if (is_operator(str)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error: Invalid expression");

            int a = stack.top(); stack.pop();
            // std::cout << "pop : " << a << "\n";
            int b = stack.top(); stack.pop();
            // std::cout << "pop : " << b << "\n";
            int result = do_op(str, a, b);
            // std::cout << a << " " << str << " " << b << " = " << result << std::endl;
            stack.push(result);
        }
        else {
            int number;
            try {
                number = StringToInt(str);
                if (number < 0 || number >= 10)
                    throw std::out_of_range("Number out of range");
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                exit(1);
            }
            stack.push(number);
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression");
    
    return stack.top();
}
