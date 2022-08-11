/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Exception;

export namespace TrilogyOnline
{
	namespace API
	{
		class CException
		{
		private:
			const char16_t* ErrorMessage{ };

		public:
			CException() noexcept = default;

			CException(const char16_t* const errorMessage) noexcept :
				ErrorMessage{ errorMessage } { }

			virtual ~CException() noexcept = default;

			virtual const char16_t* GetErrorMessage() const noexcept
			{
				return ErrorMessage;
			}
		};
	}
}