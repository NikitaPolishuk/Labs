//3. Написать свой аналог стандартной функции обработки строк из файла cstring, в
//соответствии с вариантом.В функции main на тестовых данных продемонстрировать
//результат работы как стандартной функции, так и собственной версии.Ввод - вывод
//данных организовать средствами cstdio
//Полищук Нилищук Алексеевич
//Вариант 1
#include <iostream>

char* reverseChar(char* s, int c)
{
	int len = 0;

	char* rest_of_string = NULL;

	while (s[len] != '\0')
	{
		
		if (s[len] == c)
		{
			rest_of_string = s + len;
			break; //Выход изи цикла после первого найденного совпадения 
		}
		len++;
	}

	return rest_of_string;
}

int main()
{
	char s[] = "www.some_address.add_something_else.com";

	char* standard_result = strchr(s, '.');

	char* my_result = reverseChar(s, '.');

	printf("Initial string: %s\nStandard: %s\nMy version: %s\n", s, standard_result, my_result);

	return 0;

} 

