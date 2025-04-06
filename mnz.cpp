#include "mnz.h"

#include <cmath>
#include <valarray>

namespace mnz {
	long long convert_to10(std::string _Num, int _From) {
		if ((_From < 2) || (_From > 36))
			throw std::exception("Number system out of range");

		char alpha[37] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
			'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 0 };

		alpha[_From] = 0;

		char* num_src = (char*)_Num.data();
		long long len = (long long)_Num.length();

		for (size_t i = 0; i < len; ++i)
			num_src[i] = tolower(num_src[i]);

		if (_Num.find_first_not_of(alpha) != std::string::npos)
			throw std::exception("Invalid char digit");

		long long res = 0;
		long long pow_counter = (len - 1);

		for (long long i = 0; i < len; ++i) {
			int char_n;
			char ch = num_src[i];

			if ((ch >= '0') && (ch <= '9'))
				char_n = (int)(ch - '0');
			else 
				char_n =(int)(ch - 'a' + 10);

			res += (long long)(char_n * std::pow((double)_From, (double)(pow_counter--)));
		}

		return res;
	}

	std::string convert_from10(long long _Num, int _To) {
		if ((_To < 2) || (_To > 36))
			throw std::exception("Number system out of range");

		char alpha[36] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
			'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

		std::string res;
		
		while (_Num > 0) {
			res = alpha[_Num % _To] + res;
			_Num /= _To;
		}

		return res;
	}
}
