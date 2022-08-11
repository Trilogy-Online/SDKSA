/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

#include <string>
#include <vector>
#include <map>
#include <memory>

export module TrilogyOnline.SDK.Browser;

import TrilogyOnline.SDK.Fundamental;

export namespace TrilogyOnline
{
	namespace API
	{
		class CBrowser
		{
		public:
			class CMultiArgument
			{
			public:
				enum class EType : UInt8
				{
					Bool,
					Int8,
					UInt8,
					Int16,
					UInt16,
					Int32,
					UInt32,
					Int64,
					UInt64,
					Float,
					Double,
					LongDouble,
					String,
					ArrayView,
					ObjectView,
					Array,
					Object
				};

				virtual ~CMultiArgument() noexcept = default;

				[[nodiscard]]
				virtual EType GetType() const noexcept = 0;

				[[nodiscard]]
				virtual bool& AsBool() = 0;

				[[nodiscard]]
				virtual const bool& AsBool() const = 0;

				[[nodiscard]]
				virtual Int8& AsInt8() = 0;

				[[nodiscard]]
				virtual const Int8& AsInt8() const = 0;

				[[nodiscard]]
				virtual UInt8& AsUInt8() = 0;

				[[nodiscard]]
				virtual const UInt8& AsUInt8() const = 0;

				[[nodiscard]]
				virtual Int16& AsInt16() = 0;

				[[nodiscard]]
				virtual const Int16& AsInt16() const = 0;

				[[nodiscard]]
				virtual UInt16& AsUInt16() = 0;

				[[nodiscard]]
				virtual const UInt16& AsUInt16() const = 0;

				[[nodiscard]]
				virtual Int32& AsInt32() = 0;

				[[nodiscard]]
				virtual const Int32& AsInt32() const = 0;

				[[nodiscard]]
				virtual UInt32& AsUInt32() = 0;

				[[nodiscard]]
				virtual const UInt32& AsUInt32() const = 0;

				[[nodiscard]]
				virtual Int64& AsInt64() = 0;

				[[nodiscard]]
				virtual const Int64& AsInt64() const = 0;

				[[nodiscard]]
				virtual UInt64& AsUInt64() = 0;

				[[nodiscard]]
				virtual const UInt64& AsUInt64() const = 0;

				[[nodiscard]]
				virtual float& AsFloat() = 0;

				[[nodiscard]]
				virtual const float& AsFloat() const = 0;

				[[nodiscard]]
				virtual double& AsDouble() = 0;

				[[nodiscard]]
				virtual const double& AsDouble() const = 0;

				[[nodiscard]]
				virtual long double& AsLongDouble() = 0;

				[[nodiscard]]
				virtual const long double& AsLongDouble() const = 0;

				[[nodiscard]]
				virtual std::u16string& AsString() = 0;

				[[nodiscard]]
				virtual const std::u16string& AsString() const = 0;

				[[nodiscard]]
				virtual std::vector<CMultiArgument*>& AsArrayView() = 0;

				[[nodiscard]]
				virtual const std::vector<CMultiArgument*>& AsArrayView() const = 0;

				[[nodiscard]]
				virtual std::map<std::u16string, CMultiArgument*>& AsObjectView() = 0;

				[[nodiscard]]
				virtual const std::map<std::u16string, CMultiArgument*>& AsObjectView() const = 0;

				[[nodiscard]]
				virtual std::vector<std::unique_ptr<CMultiArgument>>& AsArray() = 0;

				[[nodiscard]]
				virtual const std::vector<std::unique_ptr<CMultiArgument>>& AsArray() const = 0;

				[[nodiscard]]
				virtual std::map<std::u16string, std::unique_ptr<CMultiArgument>>& AsObject() = 0;

				[[nodiscard]]
				virtual const std::map<std::u16string, std::unique_ptr<CMultiArgument>>& AsObject() const = 0;
			};

			virtual ~CBrowser() noexcept = default;

			virtual void SetUserData(void* const value) noexcept = 0;

			[[nodiscard]]
			virtual void* GetUserData() const noexcept = 0;

			virtual void Emit(const std::u16string_view eventName, const std::vector<CMultiArgument*>& multiArguments) = 0;

			virtual void Emit(const std::u16string_view eventName, const std::vector<std::unique_ptr<CMultiArgument>>& multiArguments) = 0;
		};
	}
}