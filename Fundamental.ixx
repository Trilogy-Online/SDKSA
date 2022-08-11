/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

#include <cstddef>
#include <cstdint>

export module TrilogyOnline.SDK.Fundamental;

export namespace TrilogyOnline
{
	using Byte = std::uint8_t;

	using Int8 = std::int8_t;
	using UInt8 = std::uint8_t;

	using Int16 = std::int16_t;
	using UInt16 = std::uint16_t;

	using Int32 = std::int32_t;
	using UInt32 = std::uint32_t;

	using Int64 = std::int64_t;
	using UInt64 = std::uint64_t;

	using NativeUInt = std::uintptr_t;
	using NativeInt = std::intptr_t;

	using NullPointer = std::nullptr_t;
}