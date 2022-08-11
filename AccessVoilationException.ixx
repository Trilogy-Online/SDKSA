/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.AccessVoilationException;

import TrilogyOnline.SDK.Exception;

export namespace TrilogyOnline
{
	namespace API
	{
		class CAccessVoilationException : public CException
		{
		public:
			CAccessVoilationException() noexcept = default;

			CAccessVoilationException(const char16_t* const errorMessage) noexcept :
				CException{ errorMessage } { }
		};
	}
}