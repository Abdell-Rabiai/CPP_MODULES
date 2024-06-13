# pragma once
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <string>
# include <exception>
# include <stdexcept>
# include <vector>

bool is_operator(const std::string &token);
int calculate_rpn(const std::string &expression);
int do_op(const std::string &op, int a, int b);