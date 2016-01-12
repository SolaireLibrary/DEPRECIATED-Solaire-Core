#ifndef SOLAIRE_MATHS_HPP
#define SOLAIRE_MATHS_HPP

//Copyright 2015 Adam Smith
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

// Contact :
// Email             : solairelibrary@mail.com
// GitHub repository : https://github.com/SolaireLibrary/SolaireCPP

/*!
	\file Maths.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\version 1.0
	\date
	Created			: 26th September 2015
	Last Modified	: 5th January 2016
*/

#include <cstdint>

namespace Solaire{

	enum : uint64_t {
		BIT_0		= 1,
		BIT_1		= BIT_0 << 1L,
		BIT_2		= BIT_1 << 1L,
		BIT_3		= BIT_2 << 1L,
		BIT_4		= BIT_3 << 1L,
		BIT_5		= BIT_4 << 1L,
		BIT_6		= BIT_5 << 1L,
		BIT_7		= BIT_6 << 1L,
		BIT_8		= BIT_7 << 1L,
		BIT_9		= BIT_8 << 1L,
		BIT_10		= BIT_9 << 1L,
		BIT_11		= BIT_10 << 1L,
		BIT_12		= BIT_11 << 1L,
		BIT_13		= BIT_12 << 1L,
		BIT_14		= BIT_13 << 1L,
		BIT_15		= BIT_14 << 1L,
		BIT_16		= BIT_15 << 1L,
		BIT_17		= BIT_16 << 1L,
		BIT_18		= BIT_17 << 1L,
		BIT_19		= BIT_18 << 1L,
		BIT_20		= BIT_19 << 1L,
		BIT_21		= BIT_20 << 1L,
		BIT_22		= BIT_21 << 1L,
		BIT_23		= BIT_22 << 1L,
		BIT_24		= BIT_23 << 1L,
		BIT_25		= BIT_24 << 1L,
		BIT_26		= BIT_25 << 1L,
		BIT_27		= BIT_26 << 1L,
		BIT_28		= BIT_27 << 1L,
		BIT_29		= BIT_28 << 1L,
		BIT_30		= BIT_29 << 1L,
		BIT_31		= ((uint64_t) BIT_30) << 1L,
		BIT_32		= ((uint64_t) BIT_31) << 1L,
		BIT_33		= ((uint64_t) BIT_32) << 1L,
		BIT_34		= ((uint64_t) BIT_33) << 1L,
		BIT_35		= ((uint64_t) BIT_34) << 1L,
		BIT_36		= ((uint64_t) BIT_35) << 1L,
		BIT_37		= ((uint64_t) BIT_36) << 1L,
		BIT_38		= ((uint64_t) BIT_37) << 1L,
		BIT_39		= ((uint64_t) BIT_38) << 1L,
		BIT_40		= ((uint64_t) BIT_39) << 1L,
		BIT_41		= ((uint64_t) BIT_40) << 1L,
		BIT_42		= ((uint64_t) BIT_41) << 1L,
		BIT_43		= ((uint64_t) BIT_42) << 1L,
		BIT_44		= ((uint64_t) BIT_43) << 1L,
		BIT_45		= ((uint64_t) BIT_44) << 1L,
		BIT_46		= ((uint64_t) BIT_45) << 1L,
		BIT_47		= ((uint64_t) BIT_46) << 1L,
		BIT_48		= ((uint64_t) BIT_47) << 1L,
		BIT_49		= ((uint64_t) BIT_48) << 1L,
		BIT_50		= ((uint64_t) BIT_49) << 1L,
		BIT_51		= ((uint64_t) BIT_50) << 1L,
		BIT_52		= ((uint64_t) BIT_51) << 1L,
		BIT_53		= ((uint64_t) BIT_52) << 1L,
		BIT_54		= ((uint64_t) BIT_53) << 1L,
		BIT_55		= ((uint64_t) BIT_54) << 1L,
		BIT_56		= ((uint64_t) BIT_55) << 1L,
		BIT_57		= ((uint64_t) BIT_56) << 1L,
		BIT_58		= ((uint64_t) BIT_57) << 1L,
		BIT_59		= ((uint64_t) BIT_58) << 1L,
		BIT_60		= ((uint64_t) BIT_59) << 1L,
		BIT_61		= ((uint64_t) BIT_60) << 1L,
		BIT_62		= ((uint64_t) BIT_61) << 1L,
		BIT_63		= ((uint64_t) BIT_62) << 1L,

		NYBBLE_0	= BIT_0 | BIT_1 | BIT_2 | BIT_3,
		NYBBLE_1	= NYBBLE_0 << 4L,
		NYBBLE_2	= NYBBLE_1 << 4L,
		NYBBLE_3	= NYBBLE_2 << 4L,
		NYBBLE_4	= NYBBLE_3 << 4L,
		NYBBLE_5	= NYBBLE_4 << 4L,
		NYBBLE_6	= NYBBLE_5 << 4L,
		NYBBLE_7	= ((uint64_t) NYBBLE_6) << 4L,
		NYBBLE_8	= ((uint64_t) NYBBLE_7) << 4L,
		NYBBLE_9	= ((uint64_t) NYBBLE_8) << 4L,
		NYBBLE_10	= ((uint64_t) NYBBLE_9) << 4L,
		NYBBLE_11	= ((uint64_t) NYBBLE_10) << 4L,
		NYBBLE_12	= ((uint64_t) NYBBLE_11) << 4L,
		NYBBLE_13	= ((uint64_t) NYBBLE_12) << 4L,
		NYBBLE_14	= ((uint64_t) NYBBLE_13) << 4L,
		NYBBLE_15	= ((uint64_t) NYBBLE_14) << 4L,

		BYTE_0		= NYBBLE_0 | NYBBLE_1,
		BYTE_1		= BYTE_0 << 8L,
		BYTE_2		= BYTE_1 << 8L,
		BYTE_3		= ((uint64_t) BYTE_2) << 8L,
		BYTE_4		= ((uint64_t) BYTE_3) << 8L,
		BYTE_5		= ((uint64_t) BYTE_4) << 8L,
		BYTE_6		= ((uint64_t) BYTE_5) << 8L,
		BYTE_7		= ((uint64_t) BYTE_6) << 8L,

		SHORT_0		= BYTE_0 | BYTE_1,
		SHORT_1		= ((uint64_t) SHORT_0) << 16L,
		SHORT_2		= ((uint64_t) SHORT_1) << 16L,
		SHORT_3		= ((uint64_t) SHORT_2) << 16L,

		INT_0		= ((uint64_t) SHORT_0) | ((uint64_t) SHORT_1),
		INT_1		= ((uint64_t) SHORT_1) << 32L,

		LONG_0		= ((uint64_t) INT_0) | ((uint64_t) INT_1)
	};

	namespace Implementation {
		static constexpr uint64_t MAX_VALUES[64] = {
			0L, // 1L?
			2L,
			4L,
			8L,
			16L,
			32L,
			64L,
			128L,
			256L,
			512L,
			1024L,
			2048L,
			4096L,
			8192L,
			16384L,
			32768L,
			65536L,
			131072L,
			262144L,
			524288L,
			1048576L,
			2097152L,
			4194304L,
			8388608L,
			16777216L,
			33554432L,
			67108864L,
			134217728L,
			268435456L,
			536870912L,
			1073741824L,
			2147483648L,
			4294967296L,
			8589934592L,
			17179869184L,
			34359738368L,
			68719476736L,
			137438953472L,
			274877906944L,
			549755813888L,
			1099511627776L,
			2199023255552L,
			4398046511104L,
			8796093022208L,
			17592186044416L,
			35184372088832L,
			70368744177664L,
			140737488355328L,
			281474976710656L,
			562949953421312L,
			1125899906842620L,
			2251799813685250L,
			4503599627370500L,
			9007199254740990L,
			18014398509482000L,
			36028797018964000L,
			72057594037927900L,
			144115188075856000L,
			288230376151712000L,
			576460752303423000L,
			1152921504606850000L,
			2305843009213690000L,
			4611686018427390000L,
			9223372036854780000L
		};
	}

	////

	static constexpr uint64_t maxValue(const uint8_t aBits) {
		return Implementation::MAX_VALUES[aBits];
	}

	////

	static constexpr bool isPowerOfTwo(const uint32_t aValue) throw() {
		return aValue == 0 ? false : (aValue & (aValue - 1)) == 0;
	}

	////

	template<class T>
	static constexpr T linearInterpolationAccurate(const T aFirst, const T aSecond, const T aWeight) throw() {
		return (static_cast<T>(1) - aWeight) * aFirst + aWeight * aSecond;
	}

	template<class T>
	static constexpr T linearInterpolationFast(const T aFirst, const T aSecond, const T aWeight) throw() {
		return aFirst + aWeight *(aSecond - aFirst);
	}

	////

	template<class T>
	static constexpr T ceilToMultiple(const T aValue, const T aMultiple) throw() {
		return ((aValue + aMultiple - 1) / aMultiple) * aMultiple;
	}

	template<class T>
	static constexpr T floorToMultiple(const T aValue, const T aMultiple) throw() {
		return aValue % aMultiple == 0 ? aValue : ceilToMultiple<T>(aValue, aMultiple) - aMultiple;
	}

	template<class T>
	static constexpr T roundToClosestMultiple(const T aValue, const T aMultiple) throw() {
		return ceilToMultiple<T>(aValue, aMultiple) - (((aValue % aMultiple) < 5) && ((aValue % aMultiple) != 0) ? 5 : 0);
	}

	////

	static constexpr uint64_t set1(const uint32_t aBits) {
		return aBits == 0 ? 0 : 1 | (set1(aBits - 1) << 1);
	}

	////

	static constexpr uint16_t combine16(
        const uint8_t aByte0, const uint8_t aByte1
    ) {
        return (static_cast<uint16_t>(aByte0) << 8) | aByte1;
    }

	static constexpr uint32_t combine32(
        const uint8_t aByte0, const uint8_t aByte1,
        const uint8_t aByte2, const uint8_t aByte3
    ) {
        return
            (static_cast<uint32_t>(aByte0) << 24) |
            (static_cast<uint32_t>(aByte1) << 16) |
            (static_cast<uint32_t>(aByte2) << 8) |
            aByte3;
    }

	static constexpr uint32_t combine64(
        const uint8_t aByte0, const uint8_t aByte1,
        const uint8_t aByte2, const uint8_t aByte3,
        const uint8_t aByte4, const uint8_t aByte5,
        const uint8_t aByte6, const uint8_t aByte7
    ) {
        return
            (static_cast<uint64_t>(aByte0) << 56L) |
            (static_cast<uint64_t>(aByte1) << 48L) |
            (static_cast<uint64_t>(aByte2) << 40L) |
            (static_cast<uint64_t>(aByte3) << 32L) |
            (static_cast<uint64_t>(aByte4) << 24L) |
            (static_cast<uint64_t>(aByte5) << 16L) |
            (static_cast<uint64_t>(aByte6) << 8L) |
            aByte7;
    }

    static constexpr int8_t signCast(const uint8_t aValue) {
        return *reinterpret_cast<const int8_t*>(aValue);
    }

    static constexpr int16_t signCast(const uint16_t aValue) {
        return *reinterpret_cast<const int16_t*>(aValue);
    }

    static constexpr int32_t signCast(const uint32_t aValue) {
        return *reinterpret_cast<const int32_t*>(aValue);
    }

    static constexpr int64_t signCast(const uint64_t aValue) {
        return *reinterpret_cast<const int64_t*>(aValue);
    }

    static constexpr uint8_t signCast(const int8_t aValue) {
        return *reinterpret_cast<const uint8_t*>(aValue);
    }

    static constexpr uint16_t signCast(const int16_t aValue) {
        return *reinterpret_cast<const uint16_t*>(aValue);
    }

    static constexpr uint32_t signCast(const int32_t aValue) {
        return *reinterpret_cast<const uint32_t*>(aValue);
    }

    static constexpr uint64_t signCast(const int64_t aValue) {
        return *reinterpret_cast<const uint64_t*>(aValue);
    }

	////

	/*template<class T, typename ENABLE = std::enable_if_t<std::is_integral<T>::value>>
	struct RowMajorOrder {
		static constexpr T index(const T aX, const T aY, const T aWidth, const T aHeight) throw() {
			return aWidth * aX + aY;
		}

		static constexpr T x(const T aIndex, const T aWidth, const T aHeight) throw() {
			return aWidth / aIndex;
		}

		static constexpr T y(const T aIndex, const T aWidth, const T aHeight) throw() {
			return aWidth % aIndex;
		}
	};

	template<class T, typename ENABLE = std::enable_if_t<std::is_integral<T>::value>>
	struct ColumnMajorOrder {
		static constexpr T index(const T aX, const T aY, const T aWidth, const T aHeight) throw() {
			return aHeight * aY + aX;
		}

		static constexpr T x(const T aIndex, const T aWidth, const T aHeight) throw() {
			return aHeight % aIndex;
		}

		static constexpr T y(const T aIndex, const T aWidth, const T aHeight) throw() {
			return aHeight / aIndex;
		}
	};*/

}


#endif
