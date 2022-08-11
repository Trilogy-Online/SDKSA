/*
* SDK module for Trilogy Online modification.
* The author of this file is the lead developer of Trilogy Online.
* Detailed information can be found on the website.
* https://trilogy-online.com/
*/

module;

export module TrilogyOnline.SDK.Entity;

import TrilogyOnline.SDK.Fundamental;
import TrilogyOnline.SDK.Placeable;

export namespace TrilogyOnline
{
	namespace API
	{
		class CEntity : public CPlaceable
		{
		public:
			virtual void ToggleCollision(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsCollisionEnabled() const = 0;

			virtual void ToggleVisibility(const bool value) = 0;

			[[nodiscard]]
			virtual bool IsVisible() const = 0;

			virtual void SetAreaCode(const UInt8 value) = 0;

			[[nodiscard]]
			virtual UInt8 GetAreaCode() const = 0;
		};
	}
}