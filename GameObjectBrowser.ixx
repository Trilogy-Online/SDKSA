/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

#include <string>
#include <vector>
#include <memory>

export module TrilogyOnline.SDK.GameObjectBrowser;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Browser;

export namespace TrilogyOnline
{
	namespace API
	{
		class CGameObjectBrowser : public CBrowser
		{
		public:
			class CState
			{
			public:
				virtual ~CState() noexcept = default;

				virtual void OnEvent(CGameObjectBrowser& gameObjectBrowser, const std::u16string_view eventName, const std::vector<std::unique_ptr<CMultiArgument>>& multiArguments) = 0;

				virtual void OnLoadStart(CGameObjectBrowser& gameObjectBrowser) = 0;

				virtual void OnLoadEnd(CGameObjectBrowser& gameObjectBrowser, const Int32 httpStatusCode) = 0;

				virtual void OnLoadError(CGameObjectBrowser& gameObjectBrowser, const std::u16string_view errorText, const std::u16string_view failedUrl) = 0;
			};

			virtual void SetState(CState* const value) noexcept = 0;

			[[nodiscard]]
			virtual CState* GetState() const noexcept = 0;
		};
	}
}