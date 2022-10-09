#include <iostream>

#include <variant>
#include <vector>
#include <string>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;
	std::cout << random_variable << '\n';

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main(){
	
	std::variant<int, std::string, std::vector<int>>gg;
	
	gg = get_variant();

	if (const auto intPtr(std::get_if<int>(&gg)); intPtr)
	std::cout << 2*std::get<int>(gg) << '\n';

	else if (const auto stringPtr(std::get_if<std::string>(&gg)); stringPtr)
	std::cout << std::get<std::string>(gg) << '\n';

	else if (const auto vectorPtr(std::get_if<std::vector<int>>(&gg)); vectorPtr) {
		std::cout << std::holds_alternative<std::vector<int>>(gg) << '\n';
	}
	
    return 0;
}