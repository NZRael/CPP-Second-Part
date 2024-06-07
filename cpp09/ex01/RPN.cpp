#include "RPN.hpp"

bool	check_expression(std::string str){
	if (str.empty())
		return false;
	for (int i = 0; str[i]; i++){
		if (std::isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ' ')
			continue;
		return false;
	}
	std::stack<long long int> expression;
	std::istringstream	ss(str);
	std::string			word;
	while (ss >> word){
		// std::cout << "'" + word + "'" << std::endl;
		if (word.size() != 1)
			return false;
		if (std::isdigit(word[0]))
			expression.push(word[0] - '0');
		else if (word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/'){
			if (expression.size() < 2)
				return false;
			if (expression.size() >= 2){
				long long int a = expression.top();
				expression.pop();
				long long int b = expression.top();
				expression.pop();
				if (word[0] == '+')
					expression.push(b + a);
				else if (word[0] == '-')
					expression.push(b - a);
				else if (word[0] == '*')
					expression.push(b * a);
				else if (word[0] == '/'){
					if (a == 0){
						std::cout << "Division by zero : ";
						return false;
					}
					expression.push(b / a);
				}
			}
		}
		else
			return false;
	}
	if (expression.size() != 1)
		return false;
	if (expression.top() > INT_MAX || expression.top() < INT_MIN)
		return false;
	std::cout << expression.top() << std::endl;
	return true;
}
