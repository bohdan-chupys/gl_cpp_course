#ifndef __CUSTOM_STRING_INIT__
#define __CUSTOM_STRING_INIT__

#include <iostream>
#include <utility>

#define STRING_MAX_LENGTH	1024

class custom_string {
	private :
		char* data;
		int strlen;
	
	public :
		custom_string() = delete;
		
		custom_string(const char *input_text)
		{

			int size = 0;

			std::cout << "IN CONSTRUCTOR" << std::endl;

			while( (input_text[size++] != '\0') && (size != STRING_MAX_LENGTH) );

			data = new char[size];

			for(int i = 0; i < size; i++)
			{
				data[i] = input_text[i];
			}

			strlen = size;
		}

		custom_string(const custom_string& input)
			: data(input.data), strlen(input.strlen) 
		{
			std::cout << "IN COPY CONSTRUCTOR" << std::endl;
		}

		custom_string(custom_string&& input)
			: data(std::exchange(input.data, nullptr)), strlen(std::exchange(input.strlen, 0))
		{
			std::cout << "IN MOVE CONSTRUCTOR" << std::endl;
		}

		~custom_string()
		{
			std::cout << "In destructor" << std::endl;
			if(data != nullptr)
			{
				delete[] data;
				data = nullptr;
			}
			strlen = 0;
		}

		bool operator==(const custom_string& str);
		char operator[](size_t index);
		custom_string& operator=(const custom_string& other);
		custom_string& operator+=(const custom_string& other);

		int index_of(char ch);
		bool append(const custom_string& str);
		bool append(const char *str);
};

#endif
