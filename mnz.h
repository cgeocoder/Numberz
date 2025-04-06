#pragma once

#ifndef __MNZ_H__
#define __MNZ_H__

#include <string>

namespace mnz {
	// Converts a number from any number system to decimal
	// @param _Num - target number in string withoun prefix
	// @param _From - number system of target number
	long long convert_to10(
		std::string _Num,
		int _From
	);

	// Converts a number from decimal to any other system
	// @param _Num - target number
	// @param _To - the number system for converting to
	std::string convert_from10(
		long long _Num,
		int _To
	);
	
	// Converts a number from the _From number system to the _To number system
	inline std::string convert(
		std::string _Num,
		int _From,
		int _To
	) {
		return convert_from10(
			convert_to10(_Num, _From), _To
		);
	}
}

#endif // __MNZ_H__