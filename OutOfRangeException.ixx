/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.OutOfRangeException;

import TrilogyOnline.SDK.Exception;

export namespace TrilogyOnline
{
	namespace API
	{
		class COutOfRangeException : public CException
		{
		public:
			COutOfRangeException() noexcept = default;

			COutOfRangeException(const char16_t* const errorMessage) noexcept :
				CException{ errorMessage } { }
		};
	}
}